#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,k,l,c,d,p,nl,np;
    scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
    int x,y,z;
    x=k*l/nl;
    y=c*d;
    z=p/np;
    int mn=10000000;
    if(mn>x)mn=x;
    if(mn>y)mn=y;
    if(mn>z)mn=z;
    printf("%d\n",mn/n);
    return 0;
    }