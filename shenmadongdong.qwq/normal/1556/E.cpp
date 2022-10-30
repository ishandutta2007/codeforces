#include <bits/stdc++.h>
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
const ll infi=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &x){x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*x;y>>=1;x=x*x;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
ll n,q,a[100010],b[100010],s[100010],t[100010],d[100010],mn[100010][30],mx[100010][30],g[100010];
int main()
{
	cin>>n>>q;
    F(i) rd(a[i]);
    F(i) rd(b[i]);
	F(i) s[i]=s[i-1]+a[i];
	F(i) t[i]=t[i-1]+b[i];
    F(i) d[i]=t[i]-s[i];
    F(i) mx[i][0]=mn[i][0]=d[i];
    rep(_,0,19) rep(i,1,n-(1<<_+1)+1)
    {
        mn[i][_+1]=min(mn[i][_],mn[i+(1<<_)][_]);
        mx[i][_+1]=max(mx[i][_],mx[i+(1<<_)][_]);
    }
    g[0]=-1;F(i) g[i]=g[i>>1]+1;
    rep(_,1,q)
    {
        int l,r;
		rd(l),rd(r);
		l--;
        if (s[r]-s[l]!=t[r]-t[l]||min(mx[l+1][g[r-l]],mx[r-(1<<g[r-l])+1][g[r-l]])-d[l]<0) puts("-1");
		else cout<<max(mx[l+1][g[r-l]],mx[r-(1<<g[r-l])+1][g[r-l]])-d[l]<<'\n';
    }
	return 0;
}