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
#define rd(x) x=read()
using namespace std;
const unsigned mod=998244353;
const unsigned _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
ll read(){ll x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y){ll ret=1;while(y){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
int n,m,u,v,g,h;
char op,p,q;
map<pair<int,int>,char> mp;
int main()
{
	cin>>n>>m;
	rep(i,1,m)
	{
		op=getchar();
		while(op!='+'&&op!='-'&&op!='?') op=getchar();
		rd(u);
		if (op=='+')
		{
			rd(v);
			p=getchar();
			while(p>'z'||p<'a') p=getchar();
			mp[{u,v}]=p;
			g+=(mp.count({v,u})>0);
            h+=(mp.count({v,u})>0&&p==mp[{v,u}]);
		}
		if (op=='-')
		{
			rd(v);
			q=mp[{u,v}],mp.erase({u,v});
            g-=(mp.count({v,u})>0);
            h-=(mp.count({v,u})>0&&q==mp[{v,u}]);
		}
		if (op=='?') 
		{
			if (u&1) puts(g?"YES":"NO");
            else puts(h?"YES":"NO");
		}
	}
	return 0 ;
}