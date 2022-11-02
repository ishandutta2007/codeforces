#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned mod=998244353;
const unsigned _mod=1e9+7;
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
char a[1010],b[1010];
ll n,m,dp[30][1010][1010],ans;
ll get(int i,int j,int k,int x,int y) 
{
    if (x&&y&&dp[k][i][j]!=-1) return dp[k][i][j];
    ll res=(x&&y);
    if (i<=n&&a[i]!=k+97) res+=get(i+1,j,a[i]-97,1,y);
    if (j<=m&&b[j]!=k+97) res+=get(i,j+1,b[j]-97,x,1);
    res%=mod;
    if (x&&y) dp[k][i][j]=res;
    return res;
}
int main() 
{
    M(dp,-1);
    cin>>a+1>>b+1;
    n=strlen(a+1),m=strlen(b+1);
    F(i) rep(j,1,m) (ans+=get(i,j,26,0,0))%=mod;
    cout<<ans<<'\n';
    return 0;
}