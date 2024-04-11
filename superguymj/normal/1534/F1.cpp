#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=400005;
struct edge{int v,n;} e[N<<2];
bool vis[N],d[N],sand[N];
char s[N];
int n,m,ans,scc,ID[N],dfn[N],low[N],lim,stk[N],h[N],cnt;
vector <int> vt[N];

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
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
}

void add(int u,int v)
{
	addedge(u,v),addedge(v,u);
}

int id(int x,int y)
{
	return (x-1)*m+y;
}

void tarjan(int x)
{
	dfn[x]=low[x]=++lim;
	vis[stk[++*stk]=x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
	{
		int v=e[i].v;
		if(!dfn[v]) tarjan(v),low[x]=min(low[x],low[v]);
		else if(vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		++scc,vis[x]=0,ID[x]=scc;
		while(stk[*stk]!=x) vis[stk[*stk]]=0,ID[stk[(*stk)--]]=scc;
		--*stk;
	}
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) 
	{
		scanf("%s",s+1);
		rep(j,1,m) if(s[j]=='#') vt[j].pb(i),sand[id(i,j)]=1;
	}
	memset(h,-1,sizeof(h));
	rep(i,1,m)
	{
		int sz=vt[i].size();
		rep(j,1,sz-1)
			if(vt[i][j-1]+1==vt[i][j]) add(id(vt[i][j-1],i),id(vt[i][j],i));
			else addedge(id(vt[i][j-1],i),id(vt[i][j],i));
		if(i<m)
		{
			int px=0,py=0;
			while(px<vt[i].size() && py<vt[i+1].size())
			{
				if(vt[i][px]==vt[i+1][py])
				{
					add(id(vt[i][px],i),id(vt[i+1][py],i+1));
					++px,++py;
				}
				else if(vt[i][px]<vt[i+1][py])
				{
					addedge(id(vt[i][px],i),id(vt[i+1][py],i+1));
					++px;
				}
				else
				{
					addedge(id(vt[i+1][py],i+1),id(vt[i][px],i));
					++py;
				}
			}
		}
	}
	rep(i,1,n*m) if(sand[i] && !dfn[i]) tarjan(i);
	rep(x,1,n*m) for(int i=h[x]; i!=-1; i=e[i].n) if(ID[x]!=ID[e[i].v]) d[ID[e[i].v]]=1;
	rep(i,1,scc) if(!d[i]) ++ans;
	printf("%d\n",ans);
	return 0;
}