#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1000
int n,t,k,d;
int main()
{
    scanf("%d %d %d %d",&n,&t,&k,&d);
    int x=((n-1)/k+1)*t;
    if(d>x)
    {
        printf("NO\n");
    }
    else
    {
        int i=d/t,j=((n-i*k)-1)/k+1;
        int ans=0;
        if(j%2==0) ans=j/2*t+d; else ans=(j+1)/2*t+i*t;
        if(ans>=x) printf("NO\n"); else printf("YES\n");
    }
    return 0;
}