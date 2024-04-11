#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=200005;
int n,m,fa[N],c[N];
struct D{int u,v,tp;} dat[N];
vector <int> vt[N];
int d[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int getfa(int x)
{
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}

bool check()
{
	rep(i,1,n)
	{
		if(!c[i]) continue;
		if(c[i]!=2) return 1;
	}
	return 0;
}

void addedge(int u,int v)
{
	vt[u].pb(v);
	vt[v].pb(u);
}

void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	for(auto v:vt[x]) if(v!=fa) dfs(v,x);
}

void solve()
{
	n=getint(),m=getint();
	rep(i,1,n) fa[i]=i;
	if(m<n+2)
	{
		rep(i,1,m)
		{
			int u=getint(),v=getint();
			u=getfa(u),v=getfa(v);
			if(u==v) putchar('1');
			else putchar('0'),fa[u]=v;
		}
		puts("");
	}
	else
	{
		rep(i,1,n) vt[i].clear(),c[i]=0;
		rep(i,1,m)
		{
			dat[i].u=getint(),dat[i].v=getint();
			int u=dat[i].u,v=dat[i].v;
			if(getfa(u)!=getfa(v))
			{
				addedge(u,v);
				u=getfa(u),v=getfa(v);
				fa[u]=v;
				dat[i].tp=0;
			}
			else
			{
				dat[i].tp=1;
				++c[u],++c[v];
			}
		}
		if(check())
			rep(i,1,m) putchar('0'+dat[i].tp);
		else
		{
			dfs(1,0);
			int mx=0;
			rep(i,1,m) if(dat[i].tp)
			{
				if(d[dat[i].u]>d[dat[i].v]) swap(dat[i].u,dat[i].v);
				mx=max(mx,d[dat[i].v]);
			}
			int x;
			rep(i,1,m) if(dat[i].tp && mx==d[dat[i].v])
			{
				x=dat[i].v;
				dat[i].tp=2;
				break;
			}
			rep(i,1,m)
			{
				if(d[dat[i].u]>d[dat[i].v]) swap(dat[i].u,dat[i].v);
				if(dat[i].tp==2)
				{
					putchar('0');
					continue;
				}
				if(dat[i].tp==0)
				{
					if(dat[i].v==x) putchar('1');
					else putchar('0');
				}
				else putchar('1');
			}
		}
		puts("");
	}
}				

int main()
{
//	freopen("d.in","r",stdin);
	int t=getint();
	while(t--) solve();
	return 0;
}