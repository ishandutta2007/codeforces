#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(b+a<n)printf("%d\n",b+1);
    else printf("%d\n",(n-a));
    return 0;
    }