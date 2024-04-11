#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=200005;
bool vis[N],cah[N];
int n,m,h[N],cnt,dfn[N],low[N],tim,stk[N],ans[N],scc[N],cty;
struct edge{int v,n;} e[N<<1];
vector <int> s[N];

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

void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	stk[++*stk]=x;
	for(int i=h[x],v; i!=-1; i=e[i].n)
	{
		if(!dfn[v=e[i].v]) tarjan(v),low[x]=min(low[x],low[v]);
		else if(!vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		++cty;
		while(stk[*stk]!=x) scc[stk[*stk]]=cty,vis[stk[*stk]]=1,--*stk;
		scc[stk[*stk]]=cty,vis[stk[*stk]]=1,--*stk;
	}
}

int main()
{
	n=getint(),m=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n)
	{
		int k=getint();
		rep(j,1,k) s[i].pb(getint());
		if(i>1)
		{
			int p=0;
			rep(j,1,min(s[i].size(),s[i-1].size()))
				if(s[i][j-1]!=s[i-1][j-1]) {p=j; break;}
			if(!p)
			{
				if(s[i].size()<s[i-1].size()) return puts("No"),0;
				continue;
			}
			int c1=s[i-1][p-1],c2=s[i][p-1];
			if(c1<c2) addedge(c2+m,c1+m),addedge(c1,c2);
			else addedge(c1,c1+m),addedge(c2+m,c2);
		}
	}
	rep(i,1,2*m) if(!dfn[i]) tarjan(i);
	rep(i,1,m)
	{
		if(scc[i]==scc[i+m]) return puts("No"),0;
		cah[min(scc[i],scc[i+m])]=1;
	}
	rep(i,1,m) if(cah[scc[i+m]]) ans[++*ans]=i;
	puts("Yes");
	printf("%d\n",*ans);
	rep(i,1,*ans) printf("%d ",ans[i]);
	puts("");
	return 0;
}