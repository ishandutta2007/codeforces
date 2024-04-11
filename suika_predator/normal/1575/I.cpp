/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210000;

int n;
int a[maxn],b[maxn];
int f[maxn],fn;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	b[0]=0;
	for(int i=0;i<=n;i++) b[i]-=i;
	
	fn=0;
	for(int i=0;i<=n;i++) if(b[i]>=0)
	{
		int l=1,r=fn;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(f[mid]<=b[i]) l=mid+1;
			else r=mid-1;
		}
		l--;
		f[l+1]=b[i];
		if(l+1>fn) fn=l+1;
		
	}
	cout<<fn-1<<endl;
	
	
	return 0;
}
*/


#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

const int maxn = 210000;

int n,Q;
vector<int>V[maxn];
int val[maxn];

int siz[maxn],fa[maxn],son[maxn],dep[maxn];
int top[maxn],w[maxn],iw[maxn],z;
void dfs(const int x)
{
	siz[x]=1;
	for(auto y:V[x]) if(y!=fa[x])
	{
		fa[y]=x;
		dep[y]=dep[x]+1;
		dfs(y);
		siz[x]+=siz[y];
		if(siz[son[x]] <= siz[y]) son[x]=y;
	}
}
void build_tree(const int x,const int tp)
{
	top[x]=tp; w[x]=++z; iw[z]=x;
	if(son[x]) build_tree(son[x],tp);
	for(auto y:V[x]) if(y!=fa[x]&&y!=son[x])
		build_tree(y,y);
}

struct segment
{
	int seg[maxn<<2];
	void build(const int x,const int l,const int r)
	{
		if(l==r)
		{
			seg[x]=abs(val[iw[l]]);
			return;
		}
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		build(lc,l,mid); build(rc,mid+1,r);
		seg[x]=seg[lc]+seg[rc];
	}
	int loc,c;
	void upd(const int x,const int l,const int r)
	{
		if(l==r)
		{
			seg[x]=c;
			return;
		}
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		if(loc<=mid) upd(lc,l,mid);
		else upd(rc,mid+1,r);
		seg[x]=seg[lc]+seg[rc];
	}
	int lx,rx;
	int query(const int x,const int l,const int r)
	{
		if(rx<l||r<lx) return 0;
		if(lx<=l&&r<=rx) return seg[x];
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		return query(lc,l,mid)+query(rc,mid+1,r);
	}
}seg;

int query(int x,int y)
{
	int f1=top[x],f2=top[y];
	int sum= -abs(val[x])-abs(val[y]);
	while(f1!=f2)
	{
		if(dep[f1]<dep[f2])
		{
			swap(f1,f2);
			swap(x,y);
		}
		seg.lx=w[f1],seg.rx=w[x];
		sum+=2*seg.query(1,1,z);
		x=fa[f1],f1=top[x];
	}
	if(dep[x]>dep[y]) swap(x,y);
	seg.lx=w[x],seg.rx=w[y];
	sum+=2*seg.query(1,1,z);
	
	return sum;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>Q;
	for(int i=1;i<=n;i++) cin>>val[i];
	for(int i=1;i<n;i++)
	{
		int x,y; cin>>x>>y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	fa[1]=0; dep[1]=1; dfs(1);
	build_tree(1,1);
	
	seg.build(1,1,n);
	while(Q--)
	{
		int op,u,v; cin>>op>>u>>v;
		if(op==1)
		{
			seg.loc=w[u],seg.c=abs(v);
			val[u]=v;
			seg.upd(1,1,z);
		}
		else cout<<query(u,v)<<endl;
	}
	
	return 0;
}