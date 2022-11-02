#include<cstdio>
#include<algorithm>

#define N 200020
#define fi first
#define se second
#define mp make_pair

using namespace std;

struct lnm{
	int x,y,l,id;
}a[N];

struct lhy{
	int x,y,next;
}edge[2*N];

pair<int,int>q[110];
int son[N],size[N],mson[N],fa[N],start[N],top[N],x[N],y[N],deep[N],Give[N],l[N];
int n,m,tot,cnt,ans,L,lca,tree[N<<2],f[N],flag[N];
long long Ans;

inline int cmp(const lnm &a,const lnm &b)
{
	return a.l<b.l;
}

inline int cmp1(const lnm &a,const lnm &b)
{
	return a.id<b.id;
}

int getf(int v)
{
	if(f[v]==v)return v;
	return f[v]=getf(f[v]);
}

inline void add(int x,int y,int l)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

void dfs(int x)
{
	int y;
	for(int i=son[x];i;i=edge[i].next)
		if((y=edge[i].y)!=fa[x])
		{
			fa[y]=x;
			deep[y]=deep[x]+1;
			dfs(y);
			size[x]+=size[y];
			if(size[y]>size[mson[x]])mson[x]=y;
		}
	size[x]++;
}

void dfs(int x,int y)
{
	start[x]=++cnt;
	top[x]=y;
	if(mson[x])dfs(mson[x],y);
	int Y;
	for(int i=son[x];i;i=edge[i].next)
		if((Y=edge[i].y)!=fa[x]&&Y!=mson[x])dfs(Y,Y);
}

void add(int k,int l,int r,int ll,int val)
{
	if(l==r)
	{
		tree[k]=val;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)add(k<<1,l,mid,ll,val);
	else add(k<<1|1,mid+1,r,ll,val);
	tree[k]=max(tree[k<<1],tree[k<<1|1]);
}

void ask(int k,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
	{
		ans=max(ans,tree[k]);
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)ask(k<<1,l,mid,ll,rr);
	if(mid<rr)ask(k<<1|1,mid+1,r,ll,rr);
}

int Lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(deep[top[u]]<deep[top[v]])swap(u,v);
		q[++L]=mp(top[u],u);
		u=fa[top[u]];
	}
	if(deep[u]>deep[v])swap(u,v);
	q[++L]=mp(u,v);
	return u;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l),a[i].id=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)
		f[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int u=getf(a[i].x),v=getf(a[i].y);
		if(u^v)
		{
			cnt++;
			f[u]=v;
			Ans+=a[i].l;
			add(a[i].x,a[i].y,a[i].l);
			add(a[i].y,a[i].x,a[i].l);
			x[cnt]=a[i].x;
			y[cnt]=a[i].y;
			l[cnt]=a[i].l;
			flag[a[i].id]=1;
			if(cnt==n-1)break;
		}
	}
	dfs(1);
	dfs(1,1);
	for(int i=1;i<n;i++)
		if(fa[x[i]]==y[i])Give[i]=x[i];
		else Give[i]=y[i];
	for(int i=1;i<n;i++)
		add(1,1,n,start[Give[i]],l[i]);
	sort(a+1,a+1+m,cmp1);
	for(int p=1;p<=m;p++)
	{
		if(flag[p])printf("%I64d\n",Ans);
		else
		{
			L=0;
			ans=0;
			lca=Lca(a[p].x,a[p].y);
			for(int i=1;i<=L;i++)
				if(q[i].fi==lca)
				{
					if(start[q[i].fi]<start[q[i].se])ask(1,1,n,start[q[i].fi]+1,start[q[i].se]);
				}
				else ask(1,1,n,start[q[i].fi],start[q[i].se]);
			printf("%I64d\n",Ans-ans+a[p].l);
		}
	}
}