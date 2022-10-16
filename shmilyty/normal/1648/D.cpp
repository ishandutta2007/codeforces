#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
struct node{
	int x,y,z;
	node operator+(const node& a)const
	{
		return {max(a.x,x),max(a.y,y),max({x+a.y,z,a.z})};
	}
}t[2000001];
int n,m,a[3][500001];
vector<array<int,2>> v[500001];
void pushup(int x)
{
	t[x]=t[x<<1]+t[x<<1|1];
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]={a[0][l]-a[1][l-1],a[1][l]+a[2][n]-a[2][l-1],a[0][l]+a[1][l]-a[1][l-1]+a[2][n]-a[2][l-1]};
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int p,int v)
{
	if(l==r)
	{
		t[x].x=max(t[x].x,v);
		t[x].z=t[x].x+t[x].y;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=p)
		modify(x<<1,l,mid,p,v);
	else
		modify(x<<1|1,mid+1,r,p,v);
	pushup(x);
}
node query(int x,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
		return t[x];
	node ans={-INF,-INF,-INF};
	int mid=(l+r)>>1;
	if(mid>=ll)
		ans=ans+query(x<<1,l,mid,ll,rr);
	if(mid<rr)
		ans=ans+query(x<<1|1,mid+1,r,ll,rr);
	return ans;
}
signed main()
{
	n=read();
	m=read();
	for(int i=0;i<3;i++)
		for(int l=1;l<=n;l++)
			a[i][l]=read()+a[i][l-1];
	build(1,1,n);
//	puts("ok");
	while(m--)
	{
		int x=read(),y=read(),z=read();
		v[y].push_back({x,z});
	}
	int ans=-INF;
	for(int i=1;i<=n;i++)
		for(auto l:v[i])
		{
			node x=query(1,1,n,l[0],i);
			if(i!=n)
				modify(1,1,n,i+1,x.x-l[1]);
			ans=max(ans,x.z-l[1]);
		}
	cout<<ans;
	return 0;
}