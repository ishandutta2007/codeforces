#include<bits/stdc++.h>
#define MAXN 100005
#define MAXP 8
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p,k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void upd(ll &a,ll b) {a=max(a,b);}
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
int s[MAXN][MAXP];
ll dp[MAXN][(1<<7)];
vector<P> v;
int main()
{
    scanf("%d%d%d",&n,&p,&k);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
        v.push_back(P(a[i],i));
    }
    sort(v.begin(),v.end(),greater<P>());
    for(int i=0;i<n;i++)
        for(int j=0;j<p;j++)
            scanf("%d",&s[i][j]);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<p);j++)
        {
            if(dp[i][j]==-1) continue;
            int has=(i-__builtin_popcount(j));
            if(has<k) upd(dp[i+1][j],dp[i][j]+a[v[i].S]);
            else upd(dp[i+1][j],dp[i][j]);
            for(int k=0;k<p;k++)
            {
                if(j&(1<<k)) continue;
                upd(dp[i+1][j^(1<<k)],dp[i][j]+s[v[i].S][k]);
            }
        }
    }
    printf("%lld\n",dp[n][(1<<p)-1]);
    return 0;
}