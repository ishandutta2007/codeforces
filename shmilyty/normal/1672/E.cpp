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
int n,ans,vis[4000001];
int query(int x)
{
	if(~vis[x])
		return vis[x];
	cout<<"? "<<x<<endl;
	return vis[x]=read();
}
void solve(int l,int r,int a=-1,int b=-1)
{
	int mid=(l+r)>>1,x=query(mid);
	if((!x)&&r)
		solve(mid+1,r,x);
	if(x==n)
		solve(l,mid);
}
signed main()
{
	n=read();
	memset(vis,-1,sizeof(vis));
	int l=1,r=4000000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(query(mid)==1)
			r=mid-1;
		else
			l=mid+1;
	}
	ans=l;
	for(int i=1;i<=n;i++)
	{
		int x=query(l/i);
		if(x)
			ans=min(ans,(l/i)*x);
	}
	cout<<"! "<<ans<<endl;
	return 0;
}