/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-27 22:41:03
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],sum[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    a[0]=0;
    a[n+1]=k;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    n++;
    for(int i=0;i<=n;i++)
    {
        if(i&1) sum[i]=sum[i-1]+a[i]-a[i-1]; else sum[i]=sum[i-1];
       // printf("%d %d\n",i,sum[i]);
    }
    int ans=max(sum[n],k-sum[n]);
    for(int i=1;i<n;i++)
    {
        if(a[i]-1>a[i-1]) 
        {
            if(sum[i]==sum[i-1])
            {
                int res=(k-a[i])-(sum[n]-sum[i])+1;
                ans=max(ans,res+sum[i]);
            }
            else
            {
                int res=(k-a[i])-(sum[n]-sum[i])-1;
                ans=max(ans,res+sum[i]);
            }
            //printf("%d %d\n",i,ans);
        }
        if(a[i+1]-1>a[i])
        {
            if(sum[i]==sum[i-1])
            {
                int res=(k-a[i])-(sum[n]-sum[i])+1;
                ans=max(ans,res+sum[i]);
            }
            else
            {
                int res=(k-a[i])-(sum[n]-sum[i])-1;
                ans=max(ans,res+sum[i]);
            }
            //printf("%d %d\n",i,ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}