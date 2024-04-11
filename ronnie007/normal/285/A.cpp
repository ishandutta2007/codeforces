#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int main()
    {
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    int br=k+1;
    for(i=1;i<=k+1;i++)
        {
        printf("%d ",br);
        br--;
        }
    br=k+2;
    for(i=k+2;i<=n;i++)
        {
        printf("%d ",br);
        br++;
        }
    printf("\n");
    return 0;
    }