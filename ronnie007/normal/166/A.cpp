#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
    {
    int n,k;
    int a[100];
    int i,x,y;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&x,&y);
        a[i]=50*x-y;
        }
    sort(a,a+n);
    int br=0;
    for(i=0;i<n;i++)
        {
        if(a[i]==a[n-k])br++;
        }
    printf("%d\n",br);
    return 0;
    }