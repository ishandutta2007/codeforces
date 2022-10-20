#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
    {
    int n;
    int a[127];
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    int mn=1000000;
    int ind=-57;
    int x,y;
    for(i=0;i<n;i++)
        {
        x=i;
        y=(i+1)%n;
        if(abs(a[x]-a[y])<mn)
            {
            mn=abs(a[x]-a[y]);
            ind=i;
            }
        }
    printf("%d %d\n",ind+1,(ind+1)%n+1);
    return 0;
    }