/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-29 00:45:46
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,j,k,a[MAXN],fact[MAXN],invf[MAXN],cnt[MAXN];
mt19937 wcy(time(NULL));
int prime[MAXN],is_prime[MAXN],miu[MAXN];
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
void genmiu(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    memset(miu,0,sizeof(miu));
    miu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; miu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
}
int comb(int n,int k)
{
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    scanf("%d",&n);
    genmiu(300000);
    fact[0]=invf[0]=1;
    for(int i=1;i<=300000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[300000]=pow_mod(fact[300000],MOD-2);
    for(int i=299999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    memset(cnt,0,sizeof(cnt));
    int g=0,m=2;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);m=min(m,a[i]);g=__gcd(g,a[i]);
        for(j=1;j*j<a[i];j++)
        {
            if(a[i]%j) continue;
            cnt[j]++;
            cnt[a[i]/j]++;
        }
        if(j*j==a[i]) cnt[j]++;
    }
    if(g>1) {puts("-1"); return 0;}
    if(m==1) {puts("1"); return 0;}
    for(int ans=2;ans<=min(n,10);ans++)
    {
        if(ans==n) {printf("%d\n",ans); return 0;}
        int now=0;
        for(int i=1;i<=300000;i++) 
        {
            if(cnt[i]>=ans) now=(now+miu[i]*comb(cnt[i],ans))%MOD;
        }
        if(now!=0) {printf("%d\n",ans); return 0;}
    }
    assert(0);//should not reach here
    return 0;
}