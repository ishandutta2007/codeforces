#include<cstdio>
#include<algorithm>

#define N 1000010

using namespace std;

struct lhy{
	int ls,rs,sum;
}tree[N*25];

int n,m,lastans,o,tot,a,b,c,d,l1,r1,l2,r2;
int A[N],root[N];

inline void up(int k)
{
	tree[k].sum=tree[tree[k].ls].sum+tree[tree[k].rs].sum;
}

void modify(int k,int lastk,int l,int r,int ll)
{
	if(l==r)
	{
		tree[k].sum++;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)
	{
		tree[k].rs=tree[lastk].rs;
		tree[k].ls=++tot;
		modify(tree[k].ls,tree[lastk].ls,l,mid,ll);
	}
	else
	{
		tree[k].rs=++tot;
		tree[k].ls=tree[lastk].ls;
		modify(tree[k].rs,tree[lastk].rs,mid+1,r,ll);
	}
	up(k);
}

void build(int k,int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	tree[k].ls=++tot;
	build(k<<1,l,mid);
	tree[k].rs=++tot;
	build(k<<1|1,mid+1,r);
}

inline int F(int x)
{
	return (x-1+lastans)%n+1;
}

void ask(int k1,int k2,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
	{
		lastans+=tree[k1].sum-tree[k2].sum;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)ask(tree[k1].ls,tree[k2].ls,l,mid,ll,rr);
	if(mid<rr)ask(tree[k1].rs,tree[k2].rs,mid+1,r,ll,rr);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&o),A[o]=i;
	root[0]=++tot;
	build(root[0],1,n);
	for(int i=1;i<=n;i++)
	{
		root[i]=++tot;
		scanf("%d",&o);
		modify(root[i],root[i-1],1,n,A[o]);
	}
	scanf("%d",&m);
	lastans=-1;
	for(int i=1;i<=m;i++)
	{
		lastans++;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		l1=F(a);
		r1=F(b);
		l2=F(c);
		r2=F(d);
		if(l1>r1)swap(l1,r1);
		if(l2>r2)swap(l2,r2);
		lastans=0;
		ask(root[r2],root[l2-1],1,n,l1,r1);
		printf("%d\n",lastans);
	}
}