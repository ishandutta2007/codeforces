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
	int x,y,v,w,t;
	bool operator <(const node &A) const 
	{
		return w<A.w;
	}
}a[301];
int len,n,m,c[300001],tot,r[300001][51],fa[51],u[301];
int find(int x) 
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int calc(int x) 
{
	int ll=1,rr=len;
	while(ll<=rr)
	{
		int mid=(ll+rr)>>1;
		if(x>=c[mid])
			ll=mid+1;
		else
			rr=mid-1;
	}
	ll--;
	ll=max(ll,1ll);
	int ans=0;
	for(int i=1;i<n;++i)
		ans+=abs(u[r[ll][i]]-x);
	return ans;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		a[i].x=read();
		a[i].y=read();
		a[i].v=read();
		a[i].t=i;
		u[i]=a[i].v;
	}
	for(int i=1;i<=m;i++)
		for(int l=i;l<=m;l++)
		{
			c[++tot]=(a[i].v+a[l].v)/2;
			c[++tot]=(a[i].v+a[l].v)/2+1;
			c[++tot]=(a[i].v+a[l].v)/2-1;
		}
	sort(c+1,c+1+tot);
	for(int i=1;i<=tot;i++)
		if(i==1||c[i]!=c[i-1])
			c[++len]=c[i];
	for(int i=1;i<=len;i++)
	{
		for(int l=1;l<=m;l++)
			a[l].w=abs(a[l].v-c[i]);
		sort(a+1,a+1+m);
		for(int l=1;l<=n;l++)
			fa[l]=l;
		int cnt=0;
		for(int l=1;l<=m;l++)
			if(find(a[l].x)!=find(a[l].y))
			{
				fa[find(a[l].y)]=find(a[l].x);
				r[i][++cnt]=a[l].t;
			}
	}
	int p=read(),k=read(),A=read(),B=read(),C=read();
	int ans=0,x=0;
	for(int i=1;i<=p;i++)
	{
		x=read();
		ans^=calc(x);
	}
	for(int i=p+1;i<=k;i++)
	{
		x=(x*A+B)%C;
		ans^=calc(x);
	}
	cout<<ans;
	return 0;
}