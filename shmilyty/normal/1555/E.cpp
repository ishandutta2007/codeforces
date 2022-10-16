#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,L[4000001],R[4000001],mn[4000001],lz[4000001];
array<int,3> a[300001];
void push_up(int x)
{
	mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
void push_down(int x)
{
	if(lz[x])
	{
		mn[x<<1]+=lz[x];
		mn[x<<1|1]+=lz[x];
		lz[x<<1]+=lz[x];
		lz[x<<1|1]+=lz[x];
		lz[x]=0; 
	}
}
void build(int id,int l,int r)
{
	L[id]=l;
	R[id]=r;
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	push_up(id);
}
void modify(int id,int x,int y,int v)
{
	if(x<=L[id]&&y>=R[id])
	{
		lz[id]+=v;
		mn[id]+=v;
		return ; 
	}
	push_down(id);
	int mid=(L[id]+R[id])>>1;
	if(mid>=x)
		modify(id<<1,x,y,v);
	if(mid<y)
		modify(id<<1|1,x,y,v);
	push_up(id); 
}
int query(int id,int x,int y)
{
	if(x<=L[id]&&y>=R[id])
		return mn[id];
	push_down(id);
	int mid=(L[id]+R[id])>>1;
	int ans=INF;
	if(mid>=x)
		ans=min(ans,query(id<<1,x,y));
	if(mid<y)
		ans=min(ans,query(id<<1|1,x,y));
	return ans; 
}
signed main()
{
	n=read();
	m=read()-1;
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read()-1,w=read();
		a[i]={w,x,y};
	}
	sort(a+1,a+1+n);
	build(1,1,m);
	int l=0,r=0,ans=INF;
	while(r<=n)
	{
		if(l)
			modify(1,a[l][1],a[l][2],-1);
		++l;
		while(!query(1,1,m)&&r<=n)
		{
			++r;
			modify(1,a[r][1],a[r][2],1);
		}
		if(r>n)
			break;
		ans=min(ans,a[r][0]-a[l][0]);
	}
	cout<<ans;
	return 0;
}