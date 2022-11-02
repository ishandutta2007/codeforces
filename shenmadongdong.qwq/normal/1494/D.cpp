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
int n,a[2010][2010],p,c[2010],fa[2010],dx;
vector<int> vec;
int jyz(vector<int> v)
{
	if (!v.size()) return 0;
	if (!(v.size()-1)) 
	{
		int o=v[0];
		c[o]=a[o][o];
		return o;
	}
	int mx=0;
	rep_(i,1,v) mx=max(mx,a[v[0]][v[i]]);
	p++;
	int g=p;
	c[g]=mx;
	vector<int> G,H;
	G.resize(v.size());
	rep_(i,0,v) if (!G[i])
	{
		H.clear();
		rep_(j,i,v) if (a[v[i]][v[j]]!=mx) G[j]=1,H.push_back(v[j]);
		fa[jyz(H)] =g;
	}
	return g;
}
int main()
{
	cin>>n;p=n;
	F(i) F(j) rd(a[i][j]);
	F(i) vec.push_back(i);
	dx=jyz(vec);
	cout<<p<<'\n';
	rep(i,1,p) cout<<c[i]<<" \n"[i==p];
	cout<<dx<<'\n';
	rep(i,1,p) if (i!=dx) cout<<i<<' '<<fa[i]<<'\n';
	return 0 ;
}