#include<iostream>
#include<stdio.h>
using namespace std;


int main()
    {
    long long x,y;
    scanf("%I64d%I64d",&x,&y);
    long long ans;
    string h;
    while(y!=0)
        {
        h+=(y%10+'0');
        y=y/10;
        }
    int i;
    y=0;
    for(i=0;i<h.size();i++)
        {
        y=10*y+(h[i]-'0');
        }
    ans=x+y;
    printf("%I64d\n",ans);
    return 0;
    }