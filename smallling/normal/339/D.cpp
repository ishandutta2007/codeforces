#include<cstdio>

#define maxn 200000

using namespace std;

int i,j,k,l,m,n,o,p,he,r,tree[maxn*4],a[maxn];

void up(int x,int c)
{
	if(c%2==he%2)tree[x]=tree[x*2]^tree[x*2+1];
	else tree[x]=tree[x*2]|tree[x*2+1];
}

void build(int k,int l,int r,int x)
{
	if(l==r)
	{
		tree[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k*2,l,mid,x+1);
	build(k*2+1,mid+1,r,x+1);
	up(k,x);
}

void add(int k,int lc,int rc,int l,int r,int d,int x)
{
	if(lc==l&&rc==r){tree[k]=d;return;}
	int mid=(lc+rc)/2;
    if(r<=mid){add(k*2,lc,mid,l,r,d,x+1);up(k,x);return;}
    if(l>mid){add(k*2+1,mid+1,rc,l,r,d,x+1);up(k,x);return;}
    add(k*2,lc,mid,l,mid,d,x+1);
    add(k*2+1,mid+1,rc,mid+1,r,d,x+1);
    up(k,x);
}

int main()
{
	scanf("%d%d",&n,&m);
	o=1<<n;
	he=n+1;
	for(i=1;i<=o;i++)
	scanf("%d",&a[i]);
	build(1,1,o,1);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&p);
		add(1,1,o,l,l,p,1);
		printf("%d\n",tree[1]);
	}
}