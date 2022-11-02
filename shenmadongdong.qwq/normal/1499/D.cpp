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
int a[20000010],p[2000010],v[20000010],cnt,l,mp[20000010];
void init(int n)
{
	v[1]=1;
	rep(i,2,n)
	{
		if (!v[i]) p[++cnt]=i,v[i]=i;
		rep(j,1,cnt)
		{
			if (i*p[j]>n) break;
			v[i*p[j]]=p[j];
			if (!(i%p[j])) break;
		}
	}
}
int q[1000010],r[1000010],tot,s[1000010];
void sy(ll x)
{
	tot=0;
	while(x!=1)
	{
		if (q[tot]!=v[x]) tot++,r[tot]=1,q[tot]=v[x];
		else r[tot]++;
		x/=v[x];
	}
	s[tot+1]=1;
	req(i,tot,1) s[i]=(r[i]+1)*s[i+1];
	rep(i,0,s[1]-1)
	{
		ll w=1;
		rep(j,1,tot) w*=qpow(q[j],i%s[j]/s[j+1]);
		a[++l]=w;
	}
}
ll abab(ll x)
{
	if (mp[x]) return mp[x];
	ll jyz=x;
	tot=0;
	while(x!=1)
	{
		if (q[tot]!=v[x]) tot++,q[tot]=v[x];
		x/=v[x];
	}
	return mp[jyz]=tot;
}
ll c,d,x,ans,y;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	init(2e7);
	DC
	{
		cin>>c>>d>>x;
		ans=0;
		if (x!=y) l=0,sy(x);
		rep(i,1,l)
		{
			ll g=a[i];
			if (!((d+x/g)%c)) ans+=qpow(2,abab((d*g+x)/(c*g)));
		}
		cout<<ans<<'\n';
	}
	return 0;
}