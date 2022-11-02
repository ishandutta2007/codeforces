#include<bitset>
#include<cstdio>

#define N 100010

using namespace std;

bitset<2010>tree[4*N],bz[1010],now1,now2;

struct lhy{
	int x,y,next;
}edge[2*N];

int ans,tot,n,m,cnt,u,v,a[N];
int st[N],ed[N],where[N],son[N],lazy[4*N];
int flag[2020],prime[2020],vis[2020];

inline void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}

inline void add(int x,int y)
{
	edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

void dfs(int x,int fa)
{
	st[x]=++cnt;
	where[cnt]=x;
	for(int i=son[x];i;i=edge[i].next)
		if(edge[i].y!=fa)dfs(edge[i].y,x);
	ed[x]=cnt;
}

void build(int k,int l,int r)
{
	if(l==r)
	{
		tree[k][a[where[l]]]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tree[k]=tree[k<<1]|tree[k<<1|1];
}

inline void down(int k)
{
	if(!lazy[k])return;
	(lazy[k<<1]+=lazy[k])%=m;
	now1=tree[k<<1]&bz[m-lazy[k]-1];
	now2=tree[k<<1]^now1;
	tree[k<<1]=(now1<<lazy[k])|((now2<<lazy[k])>>m);
	(lazy[k<<1|1]+=lazy[k])%=m;
	now1=tree[k<<1|1]&bz[m-lazy[k]-1];
	now2=tree[k<<1|1]^now1;
	tree[k<<1|1]=(now1<<lazy[k])|((now2<<lazy[k])>>m);
	lazy[k]=0;
}

void modify(int k,int l,int r,int ll,int rr,int val)
{
	if(ll<=l&&r<=rr)
	{
		now1=tree[k]&bz[m-val-1];
		now2=tree[k]^now1;
		lazy[k]+=val;
		lazy[k]%=m;
		tree[k]=(now1<<val)|((now2<<val)>>m);
		return;
	}
	int mid=(l+r)>>1;
	down(k);
	if(mid>=ll)modify(k<<1,l,mid,ll,rr,val);
	if(mid<rr)modify(k<<1|1,mid+1,r,ll,rr,val);
	tree[k]=tree[k<<1]|tree[k<<1|1];
}

void ask(int k,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
	{
		for(int i=1;i<=prime[0];i++)
			if(!flag[i]&&tree[k][prime[i]])flag[i]=1,ans++;
		return;
	}
	int mid=(l+r)>>1;
	down(k);
	if(mid>=ll)ask(k<<1,l,mid,ll,rr);
	if(mid<rr)ask(k<<1|1,mid+1,r,ll,rr);
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
		read(a[i]),a[i]%=m;
	for(int i=1;i<n;i++)
		read(u),read(v),add(u,v),add(v,u);
	dfs(1,0);
	build(1,1,n);
	for(int i=0;i<m;i++)
		for(int j=0;j<=i;j++)
			bz[i][j]=1;
	for(int i=2;i<=m;i++)
		if(!vis[i])
		{
			vis[i]=1;
			prime[++prime[0]]=i;
			for(int j=i;j<=m;j+=i)
				vis[j]=1;
		}
	int Q,opt,x;
	read(Q);
	while(Q--)
	{
		read(opt);
		if(opt==1)
		{
			read(v);read(x);
			x%=m;
			modify(1,1,n,st[v],ed[v],x);
		}
		else
		{
			ans=0;
			for(int i=1;i<=prime[0];i++)
				flag[i]=0;
			read(v);
			ask(1,1,n,st[v],ed[v]);
			printf("%d\n",ans);
		}
	}
}