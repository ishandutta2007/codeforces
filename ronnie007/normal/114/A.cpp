#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,m;
    scanf("%d%d",&n,&m);
    int br=0;
    while(m%n==0)
        {
        m=m/n;
        br++;
        }
    if(m==1)printf("YES\n%d",br-1);
    else printf("NO\n");
    return 0;
    }