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
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
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
#define fi first
#define se second
map<int,int> cnt[200010];
set<pair<int,int> > r[200010];
ll n,q,a[200010],x,p[20010],cnt0,y;
bool vis[200010];
bool chk(int x)
{
	for(int i=2;1ll*i*i<=x;i++) if (x%i==0) return 0;
	return 1;
}
int main()
{
	rep(i,2,200000) if (chk(i)) p[++cnt0]=i;
    cin>>n>>q;
	F(i) 
	{
    	rd(x);
    	rep(j,1,cnt0) 
		{
			if (p[j]*p[j]>x) break;      
      		if (!(x%p[j])) {auto it=cnt[i].insert({p[j],0}).fi;while(!(x%p[j])) x/=p[j],it->se++;}
    	}
    	if (x!=1) cnt[i][x]=1;
    	for(auto it:cnt[i]) r[it.fi].insert({it.se,i});
  	}
    ll ans=1;
    rep(i,1,cnt0) if (n==r[p[i]].size()) ans=ans*ksm(p[i],r[p[i]].begin()->fi)%mod;
	rep(_,1,q) 
	{
     	rd(y),rd(x);
    	map<int,int> tmp;
    	rep(j,1,cnt0) 
		{
			if (p[j]*p[j]>x) break;      
      		if (!(x%p[j])) {auto it=tmp.insert({p[j],0}).fi;while(!(x%p[j])) x/=p[j],it->se++;}
    	}
    	if (x!=1) tmp[x]=1;
    	for(auto it:tmp) 
		{
      		auto rr=cnt[y].find(it.fi);
      		int bur=0,cur=0;
      		if (rr==cnt[y].end()) cur=it.se,bur=0,rr=cnt[y].insert(it).fi;
        	else bur=rr->se,cur=bur+it.se,rr->se+=it.se;
       		if (n==r[it.fi].size()) ans=ans*ksm(ksm(it.fi,r[it.fi].begin()->fi))%mod;
      		r[it.fi].erase({bur,y});
      		r[it.fi].insert({cur,y});
      		if (n==r[it.fi].size()) ans=ans*ksm(it.fi,r[it.fi].begin()->fi)%mod;
    	}
    	cout<<ans<<'\n';
  	}
	return 0;
}