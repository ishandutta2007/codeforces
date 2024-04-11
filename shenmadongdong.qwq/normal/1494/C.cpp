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
#define U(a,b) lower_bound(a.begin(),a.end(),b)
vector<int> s,t,v;
int n,m,a[200010],b[200010],ans;
int count()
{
	v.clear(),v.resize(t.size());
	int ansp=0;
	rep_(j,0,t) {auto it=U(s,t[j]);j&&(v[j]=v[j-1]);v[j]+=(it!=s.end()&&*it==t[j]);}
	rep_(j,0,t)
	{
		int id=upper_bound(s.begin(),s.end(),t[j])-s.begin(),g,o;
		if (id) o=t[j]-id+1,g=U(t,o)-t.begin()-1,ansp=max(ansp,j-g+v.back()-v[j]);
	}
	return ansp;
}
int main()
{
	DC
	{
		cin>>n>>m;
		F(i) rd(a[i]);
		rep(i,1,m) rd(b[i]);
		ans=0;
		rep(_,0,1)
		{
			s.clear(),t.clear();
			if (!_) F(i) if (a[i]<0) s.push_back(-a[i]);
			if (!_) rep(i,1,m) if (b[i]<0) t.push_back(-b[i]);
			if (_) F(i) if (a[i]>0) s.push_back(a[i]);
			if (_) rep(i,1,m) if (b[i]>0) t.push_back(b[i]);
			if (!_) reverse(s.begin(),s.end()),reverse(t.begin(),t.end());
			ans+=count();
		}
		cout<<ans<<'\n';
	}
	return 0 ;
}