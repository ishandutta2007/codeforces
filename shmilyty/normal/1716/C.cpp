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
int t,n,ans,a[3][200001],p1[3][200001],p2[3][200001];
void solve()
{
	n=read();
	for(int i=1;i<3;i++)
		for(int l=1;l<=n;l++)
			a[i][l]=read()+1;
	fill(p1[1]+1,p1[1]+1+n,0);
	fill(p1[2]+1,p1[2]+1+n,0);
	fill(p2[1]+1,p2[1]+1+n,0);
	fill(p2[2]+1,p2[2]+1+n,0);
	if(n==1)
	{
		cout<<max(1ll,a[2][1])<<'\n';
		return ;
	}
	int mx=a[1][n]-n;
	p1[1][n]=n;
	for(int i=n-1;i;i--)
		if(a[1][i]-i>mx)
		{
			mx=a[1][i]-i;
			p1[1][i]=i;
		}
		else
			p1[1][i]=p1[1][i+1];
	mx=a[1][n]+n;
	p2[1][n]=n;
	for(int i=n-1;i;i--)
		if(a[1][i]+i>mx)
		{
			mx=a[1][i]+i;
			p2[1][i]=i;
		}
		else
			p2[1][i]=p2[1][i+1];
	mx=a[2][n]-n;
	p1[2][n]=n;
	for(int i=n-1;i;i--)
		if(a[2][i]-i>mx)
		{
			mx=a[2][i]-i;
			p1[2][i]=i;
		}
		else
			p1[2][i]=p1[2][i+1];
	mx=a[2][n]+n;
	p2[2][n]=n;
	for(int i=n-1;i;i--)
		if(a[2][i]+i>mx)
		{
			mx=a[2][i]+i;
			p2[2][i]=i;
		}
		else
			p2[2][i]=p2[2][i+1];
	int cnt=0;
	ans=0;
	ans+=n-1+max(0ll,a[1][p1[1][2]]-p1[1][2]+1-ans);
	ans+=n+max(0ll,a[2][p2[2][1]]-n+p2[2][1]-1-ans);
	for(int i=1;i<=n;i++)
		if(i&1)
		{
			if(i==1&&a[2][1]==1)
				cnt=1;
			else
			{
				cnt=max(cnt+1,a[1][i]);
				cnt=max(cnt+1,a[2][i]);
			}
			if(i==n)
				ans=min(ans,cnt);
			else
			{
				int res=cnt;
				res+=n-i+max(0ll,a[2][p1[2][i+1]]-p1[2][i+1]+i-res);
				res+=n-i+max(0ll,a[1][p2[1][i+1]]-n+p2[1][i+1]-1-res);
				ans=min(ans,res);
			}
		}
		else
		{
			cnt=max(cnt+1,a[2][i]);
			cnt=max(cnt+1,a[1][i]);
			if(i==n)
				ans=min(ans,cnt);
			else
			{
				int res=cnt;
				res+=n-i+max(0ll,a[1][p1[1][i+1]]-p1[1][i+1]+i-res);
				res+=n-i+max(0ll,a[2][p2[2][i+1]]-n+p2[2][i+1]-1-res);
				ans=min(ans,res);
			}
		}
	cout<<ans<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}