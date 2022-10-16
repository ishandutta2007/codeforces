#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
	int l,r,w,s,v;
}a[1002];
bool cmp(node x,node y)
{
	if(x.r==y.r)
		return x.l>y.l;
	return x.r<y.r;
}
int n,m,f[1002][1002],g[1002]; 
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),x1=read(),x2=read(),x3=read(),x4=read();
		a[i]={x,x1,x2,x3,x4};
	}
	sort(a+1,a+1+n,cmp);
	a[n+1]={0,a[n].r+1,0,m,0};
	for(int i=1;i<=n+1;i++)
		for(int l=a[i].w;l<=m;l++)
		{
			int p=a[i].l;
			g[p]=0;
			for(int j=1;j<i;j++)
				if(a[j].l>=a[i].l)
				{
					while(p<a[j].r)
					{
						p++;
						g[p]=g[p-1];
					}
					g[p]=max(g[p],g[a[j].l]+f[j][min(l-a[i].w,a[i].s)]);
				}
			f[i][l]=g[p]+a[i].v;
		}
	cout<<f[n+1][m];
	return 0;
}