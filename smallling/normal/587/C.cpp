#include<cstdio>
#include<algorithm>

#define N 100010

using namespace std;

struct lhy{
	int x,y,next;
}edge[N*2];

struct Tree{
	int val[12],size;
}tree[N*4];

int x,y,u,v,n,m,q,tot,cnt,l,r,a,ans[12],A[12],B[12];
int top[N],start[N],son[N],fa[N],deep[N],mson[N],size[N];

inline void add(int x,int y)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

void dfs(int x)
{
	for(int i=son[x];i;i=edge[i].next)
		if(edge[i].y!=fa[x])
		{
			fa[edge[i].y]=x;
			deep[edge[i].y]=deep[x]+1;
			dfs(edge[i].y);
			if(size[edge[i].y]>size[mson[x]])mson[x]=edge[i].y;
			size[x]+=size[edge[i].y];
		}
	size[x]++;
}

void dfs(int x,int y)
{
	start[x]=++cnt;
	top[x]=y;
	if(mson[x])dfs(mson[x],y);
	for(int i=son[x];i;i=edge[i].next)
		if(edge[i].y!=mson[x]&&edge[i].y!=fa[x])dfs(edge[i].y,edge[i].y);
}

inline void up(int k)
{
	tree[k].size=0;
	A[0]=tree[k<<1].size;
	for(int i=1;i<=A[0];i++)
		A[i]=tree[k<<1].val[i];
	B[0]=tree[k<<1|1].size;
	for(int i=1;i<=B[0];i++)
		B[i]=tree[k<<1|1].val[i];
	l=r=1;
	while(tree[k].size<10&&l<=A[0]&&r<=B[0])
	{
		tree[k].size++;
		if(A[l]<B[r])tree[k].val[tree[k].size]=A[l],l++;
		else tree[k].val[tree[k].size]=B[r],r++;
	}
	while(tree[k].size<10&&l<=A[0])
		tree[k].val[++tree[k].size]=A[l++];
	while(tree[k].size<10&&r<=B[0])
		tree[k].val[++tree[k].size]=B[r++];
}

void add(int k,int l,int r,int ll,int val)
{
	if(l==r)
	{
		tree[k].size++;
		tree[k].val[tree[k].size]=val;
		sort(tree[k].val+1,tree[k].val+1+tree[k].size);
		if(tree[k].size>10)tree[k].size=10;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)add(k<<1,l,mid,ll,val);
	else add(k<<1|1,mid+1,r,ll,val);
	up(k);
}

void upans(int k)
{
	A[0]=tree[k].size;
	B[0]=ans[0];
	for(int i=1;i<=tree[k].size;i++)
		A[i]=tree[k].val[i];
	for(int i=1;i<=ans[0];i++)
		B[i]=ans[i];
	l=r=1;
	ans[0]=0;
	while(ans[0]<a&&l<=A[0]&&r<=B[0])
	{
		ans[0]++;
		if(A[l]<B[r])ans[ans[0]]=A[l],l++;
		else ans[ans[0]]=B[r],r++;
	}
	while(ans[0]<a&&l<=A[0])
		ans[++ans[0]]=A[l++];
	while(ans[0]<a&&r<=B[0])
		ans[++ans[0]]=B[r++];
}

void ask(int k,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
	{
		upans(k);
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)ask(k<<1,l,mid,ll,rr);
	if(mid<rr)ask(k<<1|1,mid+1,r,ll,rr);
}

void Ask(int u,int v)
{
	ans[0]=0;
	while(top[u]!=top[v])
	{
		if(deep[top[u]]<deep[top[v]])swap(u,v);
		ask(1,1,n,start[top[u]],start[u]);
		u=fa[top[u]];
	}
	if(deep[u]<deep[v])swap(u,v);
	ask(1,1,n,start[v],start[u]);
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs(1);
	dfs(1,1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		add(1,1,n,start[x],i);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&u,&v,&a);
		Ask(u,v);
		for(int i=0;i<=ans[0];i++)
			printf("%d ",ans[i]);
		putchar('\n');
	}
}