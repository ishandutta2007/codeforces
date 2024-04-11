#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXM 730730
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int n,a,x,y,k,M;
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
const int mag=720720;
int dp[MAXM],ndp[MAXM];
int main()
{
    scanf("%d%d%d%d%d%d",&n,&a,&x,&y,&k,&M);
    int prob=pow_mod(n,MOD-2);
    for(int i=0;i<mag;i++) dp[i]=0;
    for(int i=0;i<k;i++)
    {
        int mod=k-i;
        for(int j=0;j<mag;j++)
        {
            int nxt=j-j%mod;
            ndp[j]=1LL*(MOD+1-prob)*dp[j]%MOD;
            add(ndp[j],1LL*prob*(j+dp[nxt])%MOD);
        }
        swap(dp,ndp);
    }
    int ans=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        add(cnt,a/mag);
        add(ans,dp[a%mag]);
        a=(1LL*a*x+y)%M;
    }
    add(ans,1LL*mag*cnt%MOD*prob%MOD*k%MOD);
    ans=1LL*ans*pow_mod(n,k)%MOD;
    printf("%d\n",ans);
    return 0;
}