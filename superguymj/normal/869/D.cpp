#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=7,mod=1000000007;
int n,m,tot,id[N];
LL ans;
struct data{int u,v;} e0[N],e1[N],e2[N],dat[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

namespace tree
{
	map <int,bool> vis,mt;
	map <int,int> dep,siz,sz;

	int getdep(int x)
	{
		int rt=0;
		while(x) ++rt,x>>=1;
		return rt;
	}

	int getsiz(int x)
	{
		int l=x,r=x,rt=0;
		while(l<=n)
		{
			rt+=min(n,r)-l+1;
			l=l<<1,r=r<<1|1;
		}
		return rt;
	}

	void ins(int x)
	{
		while(x)
		{
			if(vis[x]) break;
			vis[x]=1,dep[x]=getdep(x);
			if((x<<1)<=n) siz[x<<1]=getsiz(x<<1);
			if((x<<1|1)<=n) siz[x<<1|1]=getsiz(x<<1|1);
			siz[x]=siz[x<<1]+siz[x<<1|1];
			x>>=1;
		}
	}

	void build()
	{
		rep(i,1,m) ins(e0[i].u),ins(e0[i].v);
	}

	bool check(int x,int y)
	{
		int dx=dep[x],dy=dep[y];
		while(x!=y)
		{
			if(dx<dy) swap(x,y),swap(dx,dy);
			if(mt[x]) return 1;
			mt[x]=1,x>>=1,--dx;
		}
		if(mt[x]) return 1;
		mt[x]=1;
		return 0;
	}

	int lca(int x,int y)
	{
		int dx=dep[x],dy=dep[y];
		while(x!=y)
		{
			if(dx<dy) swap(x,y),swap(dx,dy);
			x>>=1,--dx;
		}
		return x;
	}

	int TOP(int x)
	{
		while(x)
		{
			int y=x>>1;
			if(!y || mt.count(y)) return x;
			x>>=1;
		}
	}

	int calc(int x,int fa=0)
	{
		if(mt.count(x)) return 0;
		int rt=1,v;
		v=x>>1;
		if(v && fa!=v) rt+=calc(v,x);
		rep(i,0,1) 	
		{
			v=x<<1|i;
			if(v==fa) continue;
			if(vis.count(v))
				rt+=calc(v,x);
			else rt+=siz[v];
		}
		return rt;
	}

	int dfs(int x)
	{
		if(x>n) return 0;
		if(!vis.count(x)) return sz[x]=siz[x];

		int rt=1;
		rep(i,0,1) if(!mt.count(x<<1|i)) rt+=dfs(x<<1|i);
		return sz[x]=rt;
	}

	void solve()
	{
		mt.clear();
		mt[dat[1].u]=mt[dat[tot].v]=1;
		rep(i,1,tot-1)
			if(check(dat[i].v,dat[i+1].u))
				return;

		mt.erase(dat[1].u);
		mt.erase(dat[tot].v);

		if(TOP(dat[1].u)!=TOP(dat[tot].v))
		{
			LL ans1=calc(dat[1].u);
			LL ans2=calc(dat[tot].v);
			ans=(ans+ans1*ans2)%mod;
		}
		else
		{
			LL ans1=calc(dat[1].u);
			int t=lca(dat[1].u,dat[tot].v);
			sz.clear();
			dfs(t);
			int tp2;
			for(int i=dat[1].u; i!=t; tp2=i&1,i>>=1) if(i!=dat[1].u)
				ans=(ans+(LL)(1+sz[i<<1|(tp2^1)])*sz[i<<1|tp2])%mod;

			int tp=-1;
			for(int i=dat[tot].v; i!=t; tp=i&1,i>>=1)
			{
				LL nw=tp==-1?sz[i]:(1+sz[i<<1|(tp^1)]);
				ans=(ans+(LL)nw*(ans1-sz[i]+mod))%mod;
			}

			if(t!=dat[1].u)
			{
				if(t!=dat[tot].v) ans=(ans+(LL)(ans1-sz[t]+1+mod)*sz[t<<1|(tp^1)])%mod;
				else ans=(ans+(LL)(ans1-sz[t<<1|tp2])*sz[t<<1|tp2])%mod;
			}
		}
	}
}			

void F3()
{
	int flv=1;
	rep(i,1,tot) flv*=i,id[i]=i;
	rep(i,1,flv)
	{
		rep(j,1,tot) dat[j]=e2[id[j]];
		tree :: solve();
		next_permutation(id+1,id+1+tot);
	}
}

void F2()
{
	rep(i,0,(1<<tot)-1)
	{
		rep(j,1,tot) if(e2[j]=e1[j],i&(1<<j-1)) swap(e2[j].u,e2[j].v);
		F3();
	}
}

void F1()
{
	rep(i,1,(1<<m)-1)
	{
		tot=0;
		rep(j,1,m) if(i&(1<<j-1)) e1[++tot]=e0[j];
		F2();
	}
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,m) e0[i].u=getint(),e0[i].v=getint();
	tree :: build();
	ans=(LL)n*n%mod;
	F1();
	printf("%lld\n",ans);
	return 0;
}