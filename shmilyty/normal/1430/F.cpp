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
int n,k,ans,cnt,f[2001];
array<int,3> a[2001];
signed main()
{
	n=read();
	cnt=k=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read(),z=read();
		a[i]={x,y,z};
	}
	for(int i=n;i;i--)
	{
		int x=a[i][2];
		if(i<n&&a[i][1]==a[i+1][0])
			x+=f[i+1];
		if(x>(a[i][1]-a[i][0]+1)*k)
		{
			puts("-1");
			return 0;
		}
		f[i]=max(0ll,x-(a[i][1]-a[i][0])*k);
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt<f[i])
		{
			ans+=cnt;
			cnt=k;
		}
		ans+=a[i][2];
		cnt=(cnt+k-a[i][2]%k)%k;
	}
	cout<<ans;
	return 0;
}