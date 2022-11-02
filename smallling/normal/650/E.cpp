#include<cstdio>
#include<algorithm>

#define N 1000010

using namespace std;

struct lhy{
	int x,y,next,v;
}edge[N];

struct lnm{
	int x,y;
}E[N],c[N];

int tot,n,t,x,y;
int son[N],fa[N],g[N];

struct Splay{
	Splay *fa,*child[2],*can;
	int id,v,rev,type;
	
	inline void Rev()
	{
		if(child[0])child[0]->type=1;
		if(child[1])child[1]->type=0;
		swap(child[0],child[1]);
		rev^=1;
	}
	
	inline void up()
	{
		can=0;
		if(child[1]&&child[1]->can)can=child[1]->can;
		if(v)can=this;
		if(child[0]&&child[0]->can)can=child[0]->can;
	}
	
	inline void down()
	{
		if(rev)
		{
			if(child[0])child[0]->Rev();
			if(child[1])child[1]->Rev();
			rev=0;
		}
	}
}*Q[N],*a[N],*b[N],Pool[2*N],*cur=Pool;

inline void add(int x,int y,int v)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].v=v;edge[tot].next=son[x];son[x]=tot;
}

void dfs(int x)
{
	for(int i=son[x],y;i;i=edge[i].next)
		if(fa[x]!=(y=edge[i].y))
		{
			g[y]=edge[i].v;
			fa[y]=x;
			dfs(y);
		}
}

void Rotate(Splay *u,int x)
{
	Splay *fa,*tmp;
	fa=u->fa;
	int y=fa->type;
	tmp=fa->fa;
	u->fa=tmp;
	if(y!=2)tmp->child[y]=u;
	u->type=y;
	y=1-x;
	tmp=u->child[y];
	fa->child[x]=tmp;
	if(tmp)tmp->fa=fa,tmp->type=x;
	fa->fa=u;
	fa->type=y;
	u->child[y]=fa;
	fa->up();
}

void splay(Splay *u)
{
	int l=0,a,b;
	Splay *fa,*i;
	for(i=u;i->type!=2;i=i->fa)Q[++l]=i;
	Q[++l]=i;
	for(int i=l;i;i--)Q[i]->down();
	while(u->type!=2)
	{
		a=u->type;
		fa=u->fa;
		b=fa->type;
		if(a==b)Rotate(fa,a);
		else Rotate(u,a);
		if(b==2)break;
		Rotate(u,b);
	}
	u->up();
} 

Splay *Access(Splay *u)
{
	Splay *v=0;
	while(u)
	{
		splay(u);
		if(u->child[1])u->child[1]->type=2;
		u->child[1]=v;
		if(v)v->type=1;
		u->up();
		v=u;
		u=u->fa;
	}
	return v;
} 

void ToRoot(Splay *u)
{
	Access(u);
	splay(u);
	u->Rev(); 
}

void Link(Splay *u,Splay *v)
{
	ToRoot(u);
	u->fa=v;
}

void Cut(Splay *u,Splay *v)
{
	ToRoot(v);
	Access(u);
	splay(u);
	u->child[0]->type=2;
	u->child[0]->fa=0;
	u->child[0]=0;
	u->up();
}

inline void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		a[i]=++cur,a[i]->type=2;
	for(int i=1;i<n;i++)
	{
		t++;
		b[t]=++cur;
		b[t]->type=2;
		read(x),read(y);
		add(x,y,t);
		add(y,x,t);
		Link(a[x],b[t]);
		Link(a[y],b[t]);
		b[t]->v=1;
		b[t]->id=t;
		E[t].x=x;
		E[t].y=y;
	}
	dfs(1);
	tot=0;
	for(int i=1;i<n;i++)
	{
		read(x),read(y);
		if(fa[x]==y)
		{
			Access(b[g[x]]);splay(b[g[x]]);
			b[g[x]]->v=0;b[g[x]]->up();
		}
		else if(fa[y]==x)
		{
			Access(b[g[y]]);splay(b[g[y]]);
			b[g[y]]->v=0;b[g[y]]->up();
		}
		else c[++tot].x=x,c[tot].y=y;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	{
		ToRoot(a[c[i].x]);
		Access(a[c[i].y]);
		splay(a[c[i].y]);
		Splay *now=a[c[i].y]->can;
		int x=now->id;
		printf("%d %d %d %d\n",E[x].x,E[x].y,c[i].x,c[i].y);
		now->v=0;
		for(Splay *j=now;;j=j->fa)
		{
			j->up();
			if(j->type==2)break;
		}
		Cut(a[E[x].x],now);
		Cut(a[E[x].y],now);
		Link(a[c[i].x],now);
		Link(a[c[i].y],now);
	}
}