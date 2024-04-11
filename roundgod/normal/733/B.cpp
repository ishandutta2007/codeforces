#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#define MAXN 100000
#define INF 100000
using namespace std;
int maxi,mini,n,s,t1,t2;
int main()
{
    scanf("%d",&n);
    maxi=-INF;
    mini=INF;
    t1=0;
    t2=0;
    s=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        s+=x-y;
        if(x-y>maxi)
        {
            maxi=x-y;
            t1=i;
        }
        if(x-y<mini)
        {
            mini=x-y;
            t2=i;
        }
    }
    int ans=-1;
    if(max(s,-s)<max(s-2*mini,-s+2*mini))
    {
        ans=t2;
    if(max(s-2*mini,-s+2*mini)<max(s-2*maxi,-s+2*maxi))
    {
        ans=t1;
    }
    }
    else
    {
         if(max(s,-s)<max(s-2*maxi,-s+2*maxi))
    {
        ans=t1;
    }
    }
   printf("%d\n",ans+1);
    return 0;
}