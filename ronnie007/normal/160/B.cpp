#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
    {
    int n;
    int i,j;
    string a;
    int x[500];
    int y[500];
    cin>>n;
    cin>>a;
    for(i=0;i<n;i++)
        {
        x[i]=a[i]-'0';
        }
    for(i=n;i<2*n;i++)
        {
        y[i-n]=a[i]-'0';
        }
    sort(x,x+n);
    sort(y,y+n);
    int br=0;
    j=0;
    for(i=0;i<n;i++)
        {
        for(;j<n;j++)
            {
            if(x[i]<y[j])break;
            }
        if(j!=n)
            {
            br++;
            j++;
            }
        }
    if(br==n){printf("YES\n");return 0;}
    br=0;
    j=0;
    for(i=0;i<n;i++)
        {
        for(;j<n;j++)
            {
            if(y[i]<x[j])break;
            }
        if(j!=n)
            {
            br++;
            j++;
            }
        }
    if(br==n){printf("YES\n");return 0;}
    printf("NO\n");
    return 0;
    }