#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=300005;
int n,m,h[N],cnt,p[N],vis[N],tot,stk[N],ans,y,q;
struct edge{int v,n;} e[N<<1];
struct data{int x,y;} dat[N];
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
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void dfs(int x)
{
	vis[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(!vis[e[i].v])
		{
			vt[x].pb(e[i].v),vt[e[i].v].pb(x);
			dfs(e[i].v);
		}
}

void check(int x,int fa)
{
	int sz=vt[x].size();
	rep(i,0,sz-1) if(vt[x][i]!=fa) check(vt[x][i],x),p[x]^=p[vt[x][i]];
	ans+=p[x],p[x]=0;
}

void find(int x,int fa)
{
	stk[++tot]=x;
	if(x==y) return;
	int sz=vt[x].size();
	rep(i,0,sz-1) if(vt[x][i]!=fa)
	{
		find(vt[x][i],x);
		if(stk[tot]==y) return;
	}
	--tot;
}

int main()
{
	n=getint(),m=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,m) addedge(getint(),getint());
	dfs(1);
	q=getint();
	rep(i,1,q)
		p[dat[i].x=getint()]^=1,p[dat[i].y=getint()]^=1;
	check(1,0);
	if(ans==0)
	{
		puts("YES");
		rep(i,1,q)
		{
			y=dat[i].y,tot=0,find(dat[i].x,0);
			printf("%d\n",tot);
			rep(j,1,tot) printf("%d ",stk[j]);
			puts("");
		}
	}
	else puts("NO"),printf("%d\n",ans/2);
	return 0;
}