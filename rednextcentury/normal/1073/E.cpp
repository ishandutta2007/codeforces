#include <bits/stdc++.h>
using namespace std;
long long dp[20][2001][2][2];
long long dp2[20][2001][2][2];
int a[1000];
int k;
int mod=998244353;
long long tot=0;
long long p[100];
int r;
long long solve1(int l,int msk,bool is,bool has)
{
    if (__builtin_popcount(msk)>k)return 0;
    if (l>r){
        return __builtin_popcount(msk)<=k;
    }
    if (dp[l][msk][is][has]!=-1){
        return dp[l][msk][is][has];
    }
    long long &ret = dp[l][msk][is][has];
    ret = 0;
    for (int i=0;i<10;i++)
    {
        if (is && i>a[l])
            break;
        int newHas = has||(i>0);
        int newMsk = msk;
        if (newHas)newMsk|=(1<<i);
        long long cur = solve1(l+1,newMsk,is&&(i==a[l]),newHas);
        ret+=cur;
        ret%=mod;
    }
    return ret;
}
long long solve2(int l,int msk,bool is,bool has)
{
    if (__builtin_popcount(msk)>k)return 0;
    if (l>r){
        return 0;
    }
    if (dp2[l][msk][is][has]!=-1){
        return dp2[l][msk][is][has];
    }
    long long &ret = dp2[l][msk][is][has];
    ret = 0;
    for (int i=0;i<10;i++)
    {
        if (is && i>a[l])
            break;
        int newHas = has||(i>0);
        int newMsk = msk;
        if (newHas)newMsk|=(1<<i);
        long long cur = solve1(l+1,newMsk,is&&(i==a[l]),newHas);
        ret+=(cur*((p[r-l]*i)%mod))%mod;
        ret+=solve2(l+1,newMsk,is&&(i==a[l]),newHas);
        ret%=mod;
    }
    return ret;
}

long long solve(long long x)
{
    memset(dp,-1,sizeof(dp));memset(dp2,-1,sizeof(dp));
    tot=0;
    for (int i=1;i<=19;i++)a[i]=0;
    long long y=x;
    int i;
    for (i=1;i<=19;i++)
    {
        a[i]=y%10;
        y/=10;
    }
    reverse(a+1,a+20);
    r=19;
    return solve2(1,0,1,0);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long l,r;
    cin>>l>>r>>k;
    p[0]=1;
    for (int i=1;i<=30;i++)
    {
        p[i]=(p[i-1]*10)%mod;
    }
    cout<<(solve(r)-solve(l-1)+mod)%mod<<endl;
}