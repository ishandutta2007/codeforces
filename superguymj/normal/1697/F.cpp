#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int N=20005,M=800005;
int n,m,k,tot,lim,num;
bool vis[M];
int stk[M],dfn[M],low[M],scc[M],id[2][N][12][2];
vector <int> vt[M];
int ans[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v)
{
	vt[u].pb(v);
	vt[v^1].pb(u^1);
}

void tarjan(int x)
{
	dfn[x]=low[x]=++lim;
	stk[++*stk]=x,vis[x]=1;
	for(auto v:vt[x])
	{
		if(!dfn[v]) tarjan(v),low[x]=min(low[x],low[v]);
		else if(vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		++num,scc[x]=num,vis[x]=0;
		while(stk[*stk]!=x) scc[stk[*stk]]=num,vis[stk[*stk]]=0,--*stk;
		--*stk;
	}
}

void init()
{
	rep(i,0,tot-1)
	{
		vt[i].clear();
		dfn[i]=low[i]=scc[i]=0;
	}
	lim=tot=num=0;
}

void solve()
{
	n=getint(),m=getint(),k=getint();
	rep(t,0,1) rep(i,1,n) rep(j,1,k) id[t][i][j][0]=tot++,id[t][i][j][1]=tot++;
	rep(i,1,n)
	{
		addedge(id[0][i][1][0],id[0][i][1][1]);
		rep(j,2,k)
		{
			addedge(id[0][i][j][1],id[0][i][j-1][1]);
			addedge(id[0][i][j][1],id[1][i][j-1][0]);
		}
		
		addedge(id[1][i][k][0],id[1][i][k][1]);
		rep(j,1,k-1)
		{
			addedge(id[1][i][j][1],id[1][i][j+1][1]);
			addedge(id[1][i][j][0],id[0][i][j+1][1]);
		}
	}
	rep(i,1,n-1)
		rep(j,1,k)
			addedge(id[0][i][j][1],id[0][i+1][j][1]);
			
	rep(i,1,m)
	{
		int tp=getint();
		if(tp==1)
		{
			int x=getint(),y=getint();
			addedge(id[0][x][y][1],id[0][x][min(k,y+1)][1]);
			addedge(id[1][x][y][1],id[1][x][max(1,y-1)][1]);
		}
		if(tp==2)
		{
			int x=getint(),y=getint(),z=getint();
			rep(j,1,k)
			{
				if(j>z)
				{
					addedge(id[0][x][j][1],id[0][x][j][0]);
					addedge(id[0][y][j][1],id[0][y][j][0]);
				}
				else
				{
					addedge(id[0][x][j][1],id[1][y][min(k,z-j)][1]);
					addedge(id[0][y][j][1],id[1][x][min(k,z-j)][1]);
				}
			}
		}
		if(tp==3)
		{
			int x=getint(),y=getint(),z=getint();
			rep(j,1,k)
			{
				if(j+k<z)
				{
					addedge(id[1][x][j][1],id[1][x][j][0]);
					addedge(id[1][y][j][1],id[1][y][j][0]);
				}
				else
				{
					addedge(id[1][x][j][1],id[0][y][max(1,z-j)][1]);
					addedge(id[1][y][j][1],id[0][x][max(1,z-j)][1]);
				}
			}
		}
	}
	rep(i,0,tot-1) if(!dfn[i]) tarjan(i);
	rep(t,0,1) rep(i,1,n) rep(j,1,k)
		if(scc[id[t][i][j][0]]==scc[id[t][i][j][1]])
		{
			puts("-1");
			return;
		}
	rep(i,1,n) rep(j,1,k)
		if(scc[id[0][i][j][1]]<scc[id[0][i][j][0]])
			ans[i]=j;
	rep(i,1,n) printf("%d ",ans[i]);
	puts("");
	init();
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}