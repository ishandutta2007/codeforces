#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,i;
    scanf("%d",&n);
    printf("%d ",n);
    for(i=2;i<=n;i++)
        {
        printf("%d ",i-1);
        }
    printf("\n");
    return 0;
    }