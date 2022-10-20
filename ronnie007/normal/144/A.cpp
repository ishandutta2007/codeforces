#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int a[150];
    int mn=1000;
    int p;
    int mx=0;
    int p1;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        if(mn>=a[i])
            {
            mn=a[i];
            p=i;
            }
        if(mx<a[i])
            {
            mx=a[i];
            p1=i;
            }
        }
    int pen=0;
    if(p<p1)pen=-1;
    else pen=0;
    printf("%d\n",p1-1+(n-p)+pen);
    return 0;
    }