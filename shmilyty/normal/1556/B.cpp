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
int t,n,a[100001],n1[2],c[2];
void solve()
{
	n=read();
	n1[0]=n1[1]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read()%2;
		n1[a[i]]++;
	}
	if(abs(n1[0]-n1[1])>1)
	{
		puts("-1");
		return ;
	}
	int ans=INF,res=0;
	if(n1[0]>=n1[1])//010101
	{
		c[0]=1,c[1]=2;
		for(int i=1;i<=n;i++)
		{
			res+=abs(c[a[i]]-i);
			c[a[i]]+=2;
		}
		ans=min(ans,res);
	}
	res=0;
	if(n1[1]>=n1[0])
	{
		c[0]=2,c[1]=1;
		for(int i=1;i<=n;i++)
		{
			res+=abs(c[a[i]]-i);
			c[a[i]]+=2;
		}
		ans=min(ans,res);
	}
	cout<<ans/2<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}