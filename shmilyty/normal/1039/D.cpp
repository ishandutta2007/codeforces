#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
struct node{
	int to,nxt;
}e[200001];
int n,tot,cnt,X,Y,h[100001],f[100001],ans[100001];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nxt=h[x];
	h[x]=cnt;
}
void dfs(int x,int fa,int len)
{
	int mx1=0,mx2=0;
	for(int i=h[x];i;i=e[i].nxt)
		if(e[i].to!=fa)
		{
			dfs(e[i].to,x,len);
			if(f[e[i].to]>mx1)
			{
				mx2=mx1;
				mx1=f[e[i].to];
			}
			elif(f[e[i].to]>mx2)
				mx2=f[e[i].to];
		}
	if(mx1+mx2+1>=len)
	{
		tot++;
		f[x]=0;
	}
	else
		f[x]=mx1+1;
}
void solve(int l,int r,int ll,int rr)
{
	if(l>r||ll>rr)
		return ;
	if(ll==rr)
	{
		for(int i=l;i<=r;i++)
			ans[i]=ll;
		return ;
	}
	tot=0;
	int mid=(l+r)>>1;
	dfs(1,0,mid);
	ans[mid]=tot;
	solve(l,mid-1,tot,rr);
	solve(mid+1,r,ll,tot);
}
signed main()
{
	scanf("%d",&n);
//	n=read();
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&X,&Y);
//		X=read(),Y=read();
		add(X,Y);
		add(Y,X);
	}
	for(int i=1;i<=300&&i<=n;i++)
	{
		tot=0;
		dfs(1,0,i);
		ans[i]=tot;
	}
	solve(301,n,0,n);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
//		cout<<ans[i]<<'\n';
	return 0;
}