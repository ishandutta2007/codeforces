#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    long long x,y,m;
    long long ans=0;
    scanf("%I64d%I64d%I64d",&x,&y,&m);
    if(x>y)
        {
        swap(x,y);
        }
    if(y>=m){printf("0\n");return 0;}
    if(m<0){printf("-1\n");return 0;}
    if(x<=0 && y<=0){printf("-1\n");return 0;}
    if(x<0)
        {
        ans=-(x/y);
        if(x%y)ans++;
        x+=ans*y;
        }

    long long p;
    while(y<m)
        {
        p=y;
        y=x+y;
        x=p;
        ans++;
        }
    printf("%I64d\n",ans);
    return 0;
    }