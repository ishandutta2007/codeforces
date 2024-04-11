#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int dp[MAXN],dp2[MAXN],sum[MAXN];
//dp[i]: number of rooted trees(ignoring directions) with longest path length i
//dp2[i]: number of rooted trees(ignoring directions) with longest path length i and root has 2 children
int n;
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
int main()
{
    scanf("%d",&n);
    if(n==1) {puts("5"); return 0;}
    dp[0]=sum[0]=1; dp2[0]=0;
    int inv6=pow_mod(6,MOD-2);
    for(int i=1;i<=n;i++)
    {
        if(i>=2) dp2[i]=1LL*dp[i-1]*sum[i-2]%MOD; else dp2[i]=0;
        add(dp2[i],(1LL*dp[i-1]*(dp[i-1]+1)/2)%MOD);
        dp[i]=dp2[i]; add(dp[i],dp[i-1]);
        sum[i]=sum[i-1]; add(sum[i],dp[i]);
    }
    int ans=0;
    //single central vertex case
    //1 or 2 children
    add(ans,2LL*dp[n]%MOD);
    //3 children
    add(ans,1LL*dp[n-1]*sum[n-2]%MOD*(sum[n-2]+1)%MOD);
    add(ans,1LL*sum[n-2]*dp[n-1]%MOD*(dp[n-1]+1)%MOD);
    add(ans,2LL*dp[n-1]*(dp[n-1]+1)%MOD*(dp[n-1]+2)%MOD*inv6%MOD);
    //two directing of a single chain is isomorphic, need to subtract one
    dec(ans,1);
    //enumerating on the length of the central chain
    for(int i=1;i<=n;i++) add(ans,1LL*(dp[i-1]+MOD-1)*dp2[n-i]%MOD);
    printf("%d\n",ans);
    return 0;
}