#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

bool f(int x,int y)
    {
    if(abs(x)<abs(y))return true;
    return false;
    }

int main()
    {
    int i;
    int n;
    int a[700];
    int br=0;
    scanf("%d",&n);
    for(i=1;i<2*n;i++)
        {
        scanf("%d",&a[i]);
        if(a[i]>=0)br++;
        }
    sort(a+1,a+2*n,f);
    int sm=0;
    int zn=1;
    while(br<2*n)br+=n;
    br-=n;
    if(br%2==0 && n%2==0)br=2*n-2;
    else br=2*n-1;
    for(i=2*n-1;br>0;i--,br--)
        {
        sm+=abs(a[i]);
        }
    for(i;i>=1;i--)sm-=abs(a[i]);
    printf("%d\n",sm);
    return 0;
    }