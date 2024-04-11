/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 12:28:25
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 2005
#define INF 1000000000
#define MOD 1000000007
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int h,w,n;
P a[MAXM];
int dp[MAXM];
int fact[MAXN],invf[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    a[n].x=h;a[n].y=w;
    sort(a,a+n+1);
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=0;i<=n;i++) dp[i]=comb(a[i].x+a[i].y-2,a[i].x-1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            dp[i]=((dp[i]-1LL*dp[j]*comb(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x))%MOD+MOD)%MOD;
    printf("%d\n",dp[n]);
    return 0;
}