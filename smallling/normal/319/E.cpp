#include<cstdio>
#include<vector>
#include<algorithm>

#define N 100010

using namespace std;

struct lhy{
	int opt,x,y;
}a[N];

vector<int>tree[N*8];

int n,m,tot,now,u,v;
int A[2*N],f[N],L[N],R[N];

int getf(int v)
{
	if(f[v]==v)return v;
	return f[v]=getf(f[v]);
}

void add(int k,int l,int r,int ll)
{
	while(tree[k].size())
	{
		now=tree[k][tree[k].size()-1];
		u=getf(tot),v=getf(now);
		L[u]=min(L[u],L[v]);
		R[u]=max(R[u],R[v]);
		f[v]=u;
		tree[k].pop_back();
	}
	if(l==r)return;
	int mid=(l+r)>>1;
	if(mid>=ll)add(k<<1,l,mid,ll);
	else add(k<<1|1,mid+1,r,ll);
}

void Add(int k,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
	{
		tree[k].push_back(tot);
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)Add(k<<1,l,mid,ll,rr);
	if(mid<rr)Add(k<<1|1,mid+1,r,ll,rr);
}

int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].opt,&a[i].x,&a[i].y);
		if(a[i].opt==1)A[++A[0]]=a[i].x,A[++A[0]]=a[i].y;
	}
	sort(A+1,A+1+A[0]);
	n=unique(A+1,A+1+A[0])-A-1;
	for(int i=1;i<=m;i++)
	{
		if(a[i].opt==1)
		a[i].x=lower_bound(A+1,A+1+n,a[i].x)-A,
		a[i].y=lower_bound(A+1,A+1+n,a[i].y)-A;
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i].opt==1)
		{
			L[++tot]=a[i].x+1;
			R[tot]=a[i].y-1;
			f[tot]=tot;
			add(1,1,n,a[i].x);
			add(1,1,n,a[i].y);
			if(L[tot]<=R[tot])Add(1,1,n,L[tot],R[tot]);
		}
		else
		{
			u=a[i].x,v=getf(a[i].y);
			if(L[u]>=L[v]&&R[u]<=R[v])puts("YES");
			else puts("NO");
		}
	}
}