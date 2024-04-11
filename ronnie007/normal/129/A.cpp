#include<iostream>
#include<stdio.h>
using namespace std;


int main()
    {
    int n;
    int i,j;
    int a[107];
    int s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        s+=a[i];
        }
    int br=0;
    for(i=0;i<n;i++)
        {
        if((s-a[i])%2==0)br++;
        }
    printf("%d\n",br);
    return 0;
    }