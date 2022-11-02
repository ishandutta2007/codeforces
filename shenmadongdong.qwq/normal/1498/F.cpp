#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,k,a[100010],dp[100010][45],p[100010],ans,x,y;
vector<int> G[100010];
void dfs(int x,int fa)
{
    dp[x][0]=a[x];
    for(int u:G[x]) if (u!=fa) 
    {
        dfs(u,x);
        rep(i,0,2*k-1) dp[x][(i+1)%(2*k)]^=dp[u][i];
    }
}
void _dfs(int x,int fa)
{
    for(int u:G[x]) if (u!=fa) 
    {
        rep(i,0,2*k-1) p[i]=dp[u][i];
        rep(i,0,2*k-1) dp[u][(i+1)%(2*k)]^=dp[x][i]^p[(i+2*k-1)%(2*k)];
        _dfs(u,x);
    }
}
int main()
{
    cin>>n>>k;
    rep(i,1,n-1) rd(x),rd(y),G[x].push_back(y),G[y].push_back(x);
    F(i) rd(a[i]);
    dfs(1,0),_dfs(1,0);
    F(i)
    {
        ans=0;
        rep(j,k,2*k-1) ans^=dp[i][j];
        cout<<(ans>0)<<' ';
    }
    puts("");
    return 0;    
}