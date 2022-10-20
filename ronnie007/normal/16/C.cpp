#include<iostream>
#include<stdio.h>

using namespace std;

int gcd (int x,int y)
    {
    int a;
    while (y!=0)
        {
        a=y;
        y=x%y;
        x=a;
        }
    return x;
    }

int main ()
    {
    int a,b,x,y,ans;
    int f;
    scanf ("%d%d%d%d",&a,&b,&x,&y);

    f=gcd (x,y);
    x/=f;
    y/=f;

    ans=min(a/x,b/y);

    printf ("%d %d\n",x*ans,y*ans);

    return 0;
    }