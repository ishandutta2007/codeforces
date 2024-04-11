#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,m,hour,dfn[N],low[N],h[N],cnt,lim;
bool vis[N],d[N];
int C[N],cty,id[N],stk[N],U[N],ans;
struct edge{int v,n;} e[N<<1];

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
	dfn[x]=low[x]=++lim;
	vis[stk[++*stk]=x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(!dfn[e[i].v])
			tarjan(e[i].v),low[x]=min(low[x],low[e[i].v]);
		else if(vis[e[i].v]) low[x]=min(low[x],dfn[e[i].v]);
	if(dfn[x]==low[x])
	{
		++cty;
		while(stk[*stk]!=x) id[stk[*stk]]=cty,++C[cty],vis[stk[*stk]]=0,--*stk;
		id[stk[*stk]]=cty,++C[cty],vis[stk[*stk]]=0,--*stk;
	}
}

int main()
{
	n=getint(),m=getint(),hour=getint();
	rep(i,1,n) U[i]=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,m)
	{
		int x=getint(),y=getint();
		if((U[x]+1)%hour==U[y]) addedge(x,y);
		if((U[y]+1)%hour==U[x]) addedge(y,x);
	}
	rep(i,1,n) if(!dfn[i]) tarjan(i);
	rep(i,1,n)
		for(int j=h[i]; j!=-1; j=e[j].n)
			if(id[i]!=id[e[j].v]) d[id[i]]=1;
	ans=n;
	rep(i,1,cty) if(!d[i]) ans=min(ans,C[i]);
	printf("%d\n",ans);
	rep(i,1,cty) if(!d[i] && C[i]==ans)
	{
		rep(j,1,n) if(id[j]==i) printf("%d ",j);
		puts("");
		break;
	}
	return 0;
}