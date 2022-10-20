#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int i;
    int laste;
    int lasto;
    int s=0;
    laste=-1;
    lasto=-1;
    int br1=0;
    int br0=0;
    scanf("%d",&n);
    int c;
    for(i=0;i<n;i++)
        {
        scanf("%d",&c);
        if(c%2==1){lasto=i;br1++;}
        else {laste=i;br0++;}
        }
    if(br0==1)cout<<laste+1<<"\n";
    else cout<<lasto+1<<"\n";
    return 0;
    }