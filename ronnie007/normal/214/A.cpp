#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,m;
    int i,j;
    int br=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<=32;i++)
        {
        for(j=0;j<=32;j++)
            {
            if(i*i+j==n && i+j*j==m)br++;
            }
        }
    printf("%d\n",br);
    return 0;
    }