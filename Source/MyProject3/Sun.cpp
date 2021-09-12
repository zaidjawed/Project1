// Fill out your copyright notice in the Description page of Project Settings.


#include "Sun.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

// Sets default values
ASun::ASun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	RotationSpeed = FRotator(0.f);
	RevolveSpeed = 0.f;
}

// Called when the game starts or when spawned
void ASun::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ASun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = GetActorRotation().Add(RotationSpeed.Pitch, RotationSpeed.Yaw, RotationSpeed.Roll);
	SetActorRotation(NewRotation);

	// InitialLocation = GetActorLocation();
	//FVector NewLocation = FVector(InitialLocation.X, InitialLocation.Y + RevolveSpeed, InitialLocation.Z);
	//SetActorLocation(NewLocation, false, 0, ETeleportType::None);

}

