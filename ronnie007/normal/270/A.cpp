#include<iostream>
#include<stdio.h>
using namespace std;


int main()
    {
    int i,n;
    int x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&x);
        if(360%(180-x)==0)printf("YES\n");
        else printf("NO\n");
        }
    return 0;
    }