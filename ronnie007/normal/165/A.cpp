#include<iostream>
#include<stdio.h>
using namespace std;
int main()
    {
    int n;
    int x[500];
    int y[500];
    int i,j;
    int fl=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&x[i],&y[i]);
        }
    int br=0;
    int br1=0;
    for(i=0;i<n;i++)
        {
        fl=0;
        br1=0;
        for(j=0;j<n;j++)
            {
            if(x[j]<x[i] && y[j]==y[i]){fl=1;break;}
            }
        if(fl==1)br1++;
        fl=0;
        for(j=0;j<n;j++)
            {
            if(x[j]>x[i] && y[j]==y[i]){fl=1;break;}
            }
        if(fl==1)br1++;
        fl=0;
        for(j=0;j<n;j++)
            {
            if(x[j]==x[i] && y[j]<y[i]){fl=1;break;}
            }
        if(fl==1)br1++;
        fl=0;
        for(j=0;j<n;j++)
            {
            if(x[j]==x[i] && y[j]>y[i]){fl=1;break;}
            }
        if(fl==1)br1++;
        if(br1==4)br++;
        }
    printf("%d\n",br);
    return 0;
    }