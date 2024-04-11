#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=200005;
typedef long long LL;
bool vis[N<<1];
int n,m,tot,h[N],cnt,siz[N],Max,root,u,v,a,b,lim;
struct edge{int v,a,b,n;} e[N<<1];
struct data{int v,a,b;} pool[N];
struct point
{
	LL x,y;	

	point operator + (point t)
	{
		return (point){x+t.x,y+t.y};
	}

	point operator - (point t)
	{
		return (point){x-t.x,y-t.y};
	}

	bool operator < (const point &t) const
	{
		return x<t.x || (x==t.x && y<t.y);
	}
} stk[N];
vector <data> vt[N];
vector <point> con,pt[2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge1(int u,int v,int a,int b)
{
	vt[u].pb((data){v,a,b});
	vt[v].pb((data){u,a,b});
}

void addedge2(int u,int v,int a,int b)
{
	e[cnt]=(edge){v,a,b,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,a,b,h[v]},h[v]=cnt++;
}

void build(int x,int fa)
{
	int siz=vt[x].size()-1,p=0;
	rep(i,0,siz) if(vt[x][i].v!=fa) pool[++p]=vt[x][i];
	rep(i,1,p)
	{
		addedge2(tot+i,pool[i].v,pool[i].a,pool[i].b);
		if(i==1) addedge2(tot+1,x,0,0);
		else addedge2(tot+i-1,tot+i,0,0);
	}
	tot+=p;
	rep(i,0,siz) if(vt[x][i].v!=fa) build(vt[x][i].v,x);
}

void get(int x,int fa,int tp,LL a,LL b)
{
	pt[tp].pb((point){a,b});
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa && !vis[i])
			get(e[i].v,x,tp,a+e[i].a,b+e[i].b);
}

bool slope(point a,point b)
{
	return (double)a.x/b.x<=(double)a.y/b.y;
}

void get_convex(vector <point> &v)
{
	int top=0,siz=v.size()-1;
	sort(v.begin(),v.end());
	rep(i,0,siz)
	{
		point x=v[i];
		while(top && stk[top].x<=x.x && stk[top].y<=x.y) --top;
		while(top>1 && slope(stk[top]-stk[top-1],x-stk[top])) --top;
		stk[++top]=x;
	}
	v.clear();
	rep(i,1,top) v.pb(stk[i]);
}

void merge(vector <point> &v1,vector <point> &v2)
{
	int i=0,j=0,n=v1.size(),m=v2.size();
//	printf("%d %d\n",n,m);
	point lst;
	if(n<=2 || m<=2)
	{
		rep(i,0,n-1)
			rep(j,0,m-1)
				con.pb(v1[i]+v2[j]),++lim;
		return;
	}

	++lim;

	con.pb(lst=v1[0]+v2[0]);
	while(i<n || j<m)
	{
		point x=v1[i%n]+v2[(j+1)%m];
		point y=v1[(i+1)%n]+v2[j%m];

		++lim;

		if(slope(x-lst,y-lst)) con.pb(lst=y),++i;
		else con.pb(lst=x),++j;
	}
}

void solve()
{
	int p=0,siz=con.size()-1;
	rep(i,0,m-1)
	{
		while(p<siz && con[p].x*i+con[p].y<=con[p+1].x*i+con[p+1].y) ++p;
		printf("%lld ",con[p].x*i+con[p].y);
	}
	puts("");
}

void get_siz(int x,int fa)
{
	siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa && !vis[i])
		{
			get_siz(e[i].v,x);
			siz[x]+=siz[e[i].v];
		}
}

void get_root(int tot,int x,int fa)
{
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa && !vis[i])
		{
			get_root(tot,e[i].v,x);
			if(Max>=abs(tot-2*siz[e[i].v]))
				Max=abs(tot-2*siz[e[i].v]),root=i;
		}
}

void dfs(int x)
{
	get_siz(x,0);
	if(siz[x]==1) return;
	Max=siz[x],get_root(siz[x],x,0);
	pt[0].clear(),pt[1].clear();
	vis[root]=vis[root^1]=1;
	get(e[root].v,0,0,e[root].a,e[root].b);
	get(e[root^1].v,0,1,0,0);
	get_convex(pt[0]);
	get_convex(pt[1]);
//	puts("-1");
	merge(pt[0],pt[1]);
//	puts("-2");
	int rt=root;
//	printf("%d %d\n",lim,x);
	dfs(e[rt].v);
	dfs(e[rt^1].v);
}

int main()
{
	n=getint(),m=getint();
	if(n==1)
	{
		rep(i,0,m-1) printf("0 ");
		return puts(""),0;
	}
	rep(i,1,n-1)
	{
		u=getint(),v=getint(),a=getint(),b=getint();
		addedge1(u,v,a,b);
	}
	memset(h,-1,sizeof(h));
	tot=n,build(1,0),n=tot;
	dfs(1);
	get_convex(con);
	solve();
//	printf("%d\n",lim);
//	while(1);
	return 0;
}