#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 35000005
#define INF 40000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int k;
int prime[MAXN];
bool is_prime[MAXN];
int dp[2][10005];
int inv[10005];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    scanf("%lld%d",&n,&k);
    for(int i=1;i<=10000;i++) inv[i]=pow_mod(i,MOD-2);
    int p=sieve(33000000);
    int ans=1;
    for(int i=0;i<p;i++) 
    {
        int cnt=0;
        while(n%prime[i]==0)
        {
            n=n/prime[i];
            cnt++;
        }
        if(cnt)
        {
            memset(dp,0,sizeof(dp));
            dp[0][cnt]=1;
            for(int j=1;j<=k;j++)
            {
                int now=j&1,last=(j-1)&1;
                memset(dp[now],0,sizeof(dp[now]));
                for(int p=0;p<=cnt;p++)
                    for(int l=p;l<=cnt;l++)
                        add(dp[now][p],1LL*dp[last][l]*inv[l+1]%MOD);
            }
            int res=0,s=1;
            for(int j=0;j<=cnt;j++)
            {
                add(res,1LL*s*dp[k&1][j]%MOD);
                s=1LL*s*prime[i]%MOD;
            }
            ans=1LL*ans*res%MOD;
        }
    }
    if(n!=1)
    {
        memset(dp,0,sizeof(dp));
        int cnt=1;
        dp[0][cnt]=1;
        for(int j=1;j<=k;j++)
        {
            int now=j&1,last=(j-1)&1;
            memset(dp[now],0,sizeof(dp[now]));
            for(int p=0;p<=cnt;p++)
                for(int l=p;l<=cnt;l++)
                    add(dp[now][p],1LL*dp[last][l]*inv[l+1]%MOD);
        }
        int res=0,s=1;
        for(int j=0;j<=cnt;j++)
        {
            add(res,1LL*s*dp[k&1][j]%MOD);
            s=1LL*s*n%MOD;
        }
        ans=1LL*ans*res%MOD;
    }
    printf("%d\n",ans);
    return 0;
}