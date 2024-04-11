#include<iostream>
#include<stdio.h>
using namespace std;


long long ans;

long long l;


void f(long long x,int br4,int br7);

int main()
    {
    scanf("%I64d",&l);
    ans=1e12;
    f(0,0,0);
    printf("%I64d\n",ans);
    return 0;
    }


void f(long long x,int br4,int br7)
    {
    if(x>=l && br4==br7)
        {
        if(ans>x)ans=x;
        return ;
        }
    if(x>=10*l)return ;
    f(10*x+4,br4+1,br7);
    f(10*x+7,br4,br7+1);
    }