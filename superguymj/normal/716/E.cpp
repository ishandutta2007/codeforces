#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
typedef long long LL;
int n,u,v,cnt,h[N],mod,seed;
LL ans,bin[N];
struct edge{int v,w,n;} e[N<<1];

struct tree_divide
{
	bool vis[N];
	int siz[N],mx[N],root,Max;
	map <int,int> t;

	void get_siz(int x,int fa)
	{
		siz[x]=1,mx[x]=0;
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(e[i].v!=fa && !vis[e[i].v])
				get_siz(e[i].v,x),siz[x]+=siz[e[i].v],mx[x]=max(mx[x],siz[e[i].v]);
	}

	void get_root(int tot,int x,int fa)
	{
		if(max(tot-siz[x],mx[x])<Max) Max=max(tot-siz[x],mx[x]),root=x;
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(e[i].v!=fa && !vis[e[i].v])
				get_root(tot,e[i].v,x);
	}

	void build(int x,int fa,LL w,int dep)
	{
		++t[w];
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(e[i].v!=fa && !vis[e[i].v])
				build(e[i].v,x,(w+e[i].w*bin[dep])%mod,dep+1);
	}

	void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
	{
		if(!b)
		{
			d=a,x=1,y=0;
			return;
		}	
		exgcd(b,a%b,d,y,x),y-=(a/b)*x;
	}

	LL query(LL x,int len)
	{
		x=(mod-x)%mod;
		if(!x) return 0;
		LL a,b,d;
		exgcd(bin[len],mod,d,a,b);
		if(x%d) return -1;
		return (x/d*a%mod+mod)%mod;
	}

	void dfs(int x,int fa,LL w,int dep,int tp)
	{
		LL c=query(w,dep);
		if(c!=-1 && t.count(c)) ans+=tp*t[c];
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(e[i].v!=fa && !vis[e[i].v])
				dfs(e[i].v,x,(w*10+e[i].w)%mod,dep+1,tp);
	}

	void dfs(int x)
	{
		get_siz(x,0),Max=siz[x],get_root(siz[x],x,0),vis[root]=1;
		build(root,0,0,0),dfs(root,0,0,0,1),t.clear();	
		for(int i=h[root]; i!=-1; i=e[i].n)
			if(!vis[e[i].v])
				build(e[i].v,0,e[i].w%mod,1),dfs(e[i].v,0,e[i].w%mod,1,-1),t.clear();
		for(int i=h[root]; i!=-1; i=e[i].n)
			if(!vis[e[i].v])
				dfs(e[i].v);
	}
} t;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v,int w)
{
	e[cnt]=(edge){v,w,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,w,h[v]},h[v]=cnt++;
}

int main()
{
	n=getint(),mod=getint(),memset(h,-1,sizeof(h)),bin[0]=1;
	rep(i,1,n-1) u=getint()+1,v=getint()+1,addedge(u,v,getint());
	rep(i,1,n) bin[i]=bin[i-1]*10%mod;
	t.dfs(1),printf("%lld\n",ans-n);
	return 0;
}