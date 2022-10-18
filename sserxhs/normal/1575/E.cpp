#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=2e5+20,p=1e9+7;
void inc(int &x,int y){x+=y;x%=p;//if ((x+=y)>=p) x-=p;
}
void dec(int &x,int y){if ((x-=y)<0) x+=p;}
template<int N> struct bit
{
	int a[N];
	int n;
	bit()
	{
		memset(a,0,sizeof a);
	}
	void init(int nn)
	{
		++nn;
		n=nn;
		memset(a+1,0,n*sizeof a[0]);
	}
	void add(int x,int y)
	{
		++x;
		inc(a[x],y);
		while ((x+=x&-x)<=n) inc(a[x],y);
	}
	void minus(int x,int y)
	{
		++x;
		dec(a[x],y);
		while ((x+=x&-x)<=n) dec(a[x],y);
	}
	int sum(int x)
	{
		++x;
		if (x>n) x=n;
		ll r=a[x];
		while (x^=x&-x) r+=a[x];
		return r%p;
	}
	int sum(int x,int y)
	{
		++x;++y;
		if (x>n) return 0;
		if (y>n) y=n;
		int r=sum(y)-sum(x-1);
		if (r<0) return r+p;return r;
	}
};
bit<N> nc[2],nt[2];
struct Q
{
	int v,w;
	Q(int a,int b):v(a),w(b){}
	bool operator<(const Q &o) const {return w<o.w;}
};
vector<Q> lj[N];
int siz[N],dep[N],col[N],cnt[N],tot[N],tv[N],a[N];
int n,m,ksiz,i,j,x,y,z,rt,md,ans;
bool ed[N];
void findrt(int u)
{
	ed[u]=1;siz[u]=1;
	int mx=0;
	for (auto &[v,w]:lj[u]) if (!ed[v])
	{
		findrt(v);
		mx=max(mx,siz[v]);
		siz[u]+=siz[v];
	}
	mx=max(mx,ksiz-siz[u]);
	if (mx*2<=ksiz) rt=u;
	ed[u]=0;
}
void dfs2(int u)
{
	md=max(md,dep[u]);ed[u]=1;siz[u]=1;
	for (auto &[v,w]:lj[u]) if (!ed[v])
	{
		col[v]=w;if ((tv[v]=tv[u]+a[v])>=p) tv[v]-=p;
		dep[v]=dep[u]+(w!=col[u]);
		dfs2(v);
		siz[u]+=siz[v];
	}
	ed[u]=0;
	inc(tot[dep[u]],tv[u]);
	++cnt[dep[u]];
}
void dfs1(int u)
{
	rt=0;findrt(u);assert(rt);
	u=rt;ed[u]=1;
	//cout<<"root = "<<u<<endl;
	nc[0].init(ksiz);nc[1].init(ksiz);
	nt[0].init(ksiz);nt[1].init(ksiz);
	for (auto &[v,w]:lj[u]) if (!ed[v])
	{
		col[v]=w;dep[v]=0;tv[v]=a[v];md=0;
		dfs2(v);
		if (w==0)
		{
			int q=min(md,m);
			for (int i=0;i<=q;i++) ans=(ans+(ll)nt[0].sum(m-i)*cnt[i]+(ll)nc[0].sum(m-i)*tot[i]+(ll)nc[0].sum(m-i)*cnt[i]%p*a[u])%p;
			for (int i=0;i<=q;i++) ans=(ans+(ll)cnt[i]*a[u]+tot[i])%p;
			for (int i=0;i<=q;i++) nt[0].add(i,tot[i]),nc[0].add(i,cnt[i]);
			memset(cnt,0,(md+1)*sizeof cnt[0]);
			memset(tot,0,(md+1)*sizeof tot[0]);
		}
		else
		{
			int q=min(md,m);
			for (int i=0;i<=q;i++) ans=(ans+(ll)nt[1].sum(m-i)*cnt[i]+(ll)nc[1].sum(m-i)*tot[i]+(ll)nc[1].sum(m-i)*cnt[i]%p*a[u])%p;
				//cout<<"temp ans = "<<ans<<endl;
			//cout<<cnt[0]<<' '<<tot[0]<<"\n";
			for (int i=0;i<=q;i++) ans=(ans+(ll)cnt[i]*a[u]+tot[i])%p;
				//cout<<"temp ans = "<<ans<<endl;
			for (int i=0;i<=q;i++) nt[1].add(i,tot[i]),nc[1].add(i,cnt[i]);
			q=min(md,m-1);
			for (int i=0;i<=q;i++) ans=(ans+(ll)nt[0].sum(m-i-1)*cnt[i]+(ll)nc[0].sum(m-i-1)*tot[i]+(ll)nc[0].sum(m-i-1)*cnt[i]%p*a[u])%p;
				//cout<<"temp ans = "<<ans<<endl;
			memset(cnt,0,(md+1)*sizeof cnt[0]);
			memset(tot,0,(md+1)*sizeof tot[0]);
		}
		//cout<<"ans = "<<ans<<" after dfs "<<v<<endl;
	}
	//cout<<"ans = "<<ans<<endl;
	for (auto &[v,w]:lj[u]) if (!ed[v])
	{
		ksiz=siz[v];dfs1(v);
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		lj[x].emplace_back(y,z);
		lj[y].emplace_back(x,z);
	}ksiz=n;
	for (i=1;i<=n;i++) sort(lj[i].begin(),lj[i].end());
	dfs1(1);
	for (i=1;i<=n;i++) inc(ans,a[i]);
	ans=ans%p+p;ans%=p;
	cout<<ans<<endl;
}