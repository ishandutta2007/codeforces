/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e6+100;
int T,n,m,w,in[N],dfn[N],low[N],cnt;
int col[N],sf[N],ok[N],op[N],vi[N],ans[N],dg[N];
int tot,first[N],nxt[N*2],point[N*2];
stack <int> st;
vector <int> p[N],e[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
inline void add_edge(int x,int y)
{
	nxt[++tot]=first[x];
	first[x]=tot;
	point[tot]=y;
}
void dfs(int x)
{
	dfn[x]=low[x]=++cnt;
	st.push(x);in[x]=1;
	for (int i=first[x];i!=-1;i=nxt[i])
	{
		int u=point[i];
		if (!dfn[u]) dfs(u),low[x]=min(low[x],low[u]);
		else if (in[u]) low[x]=min(low[x],dfn[u]);
	}
	if (dfn[x]==low[x])
	{
		w++;
		while (st.top()!=x) p[w].push_back(st.top()),col[st.top()]=w,in[st.top()]=0,st.pop();
		p[w].push_back(x);st.pop();col[x]=w;in[x]=0;
	}
}
void dfs1(int x)
{
	vi[x]=1;
	for (int u:e[x]) if (!vi[u]) dfs1(u);
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		tot=-1;
		memset(first,-1,(n+10)*sizeof(int));
		memset(sf,0,(n+10)*sizeof(int));
		while (!st.empty()) st.pop();
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			if (u==v) sf[u]=1;
			else add_edge(u,v);
		}
		for (int i=1;i<=n;i++) p[i].clear();
		memset(col,0,(n+10)*sizeof(int));
		memset(in,0,(n+10)*sizeof(int));
		memset(dfn,0,(n+10)*sizeof(int));
		memset(dg,0,(n+10)*sizeof(int));
		memset(op,0,(n+10)*sizeof(int));
		cnt=w=0;
		for (int i=1;i<=n;i++) if (!dfn[i]) dfs(i);
		for (int i=1;i<=w;i++)
		{
			e[i].clear();
			for (int x:p[i])
			{
				for (int j=first[x];j!=-1;j=nxt[j])
				{
					int u=point[j];
					if (col[u]==i) continue;
					e[i].push_back(col[u]);
				}
			}
		}
		for (int i=1;i<=w;i++)
		{
			ok[i]=1;
			if (len(p[i])>1||sf[p[i][0]]) ok[i]=0;
		}
		for (int i=1;i<=w;i++) vi[i]=0;
		dfs1(col[1]);
		for (int i=1;i<=w;i++) if (vi[i])
		{
			for (int x:e[i]) dg[x]++;
		}
		for (int i=1;i<=w;i++) if (!vi[i]) op[i]=0;
		queue <int> q;
		q.push(col[1]);op[col[1]]=1;
		while (!q.empty())
		{
			int x=q.front();q.pop();
			if (!ok[x]) op[x]=-1;
			else if (op[x]>2) op[x]=2;
			for (int u:e[x]) if (vi[u])
			{
				dg[u]--;
				if (op[x]==-1) op[u]=-1;
				else if (op[u]!=-1) op[u]+=op[x];
				if (!dg[u]) q.push(u);
			}
		}
		for (int i=1;i<=w;i++) for (int j:p[i]) ans[j]=op[i];
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}	
}