#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,m;
    int i,j;
    int a[10];
    int b[10];
    scanf("%d",&n);
    b[0]=0;
    for(i=1;i<=7;i++)
        {
        scanf("%d",&a[i]);
        b[i]=a[i]+b[i-1];
        }
    n=n%b[7];
    if(n==0)n=b[7];
    for(i=1;i<=7;i++)
        {
        if(n<=a[i]){printf("%d\n",i);return 0;}
        else n=n-a[i];
        }
    return 0;
    }