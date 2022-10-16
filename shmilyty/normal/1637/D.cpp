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
int t,n,a[101],b[101],f[101][10001],g[101][10001];
void solve()
{
	n=read();
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		sum+=b[i];	
	}
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int i=0;i<n;i++)
		for(int l=0;l<=10000;l++)
			if(f[i][l])
			{
				if(l+a[i+1]<=10000)
				{
					g[i+1][l+a[i+1]]=a[i+1];
					f[i+1][l+a[i+1]]=1;
				}
				if(l+b[i+1]<=10000)
				{
					g[i+1][l+b[i+1]]=b[i+1];
					f[i+1][l+b[i+1]]=1;
				}
			}
	for(int i=sum/2;i;i--)
	{
		if(f[n][i])
		{
			int ans=0;
			vector<int> v1,v2;
			for(int l=n;l;l--)
			{
				v1.push_back(g[l][i]);
				v2.push_back(a[l]+b[l]-g[l][i]);
				i-=g[l][i];
			}
			for(int i=0;i<n;i++)
				for(int l=i+1;l<n;l++)
					ans+=(v1[i]+v1[l])*(v1[i]+v1[l]);
			for(int i=0;i<n;i++)
				for(int l=i+1;l<n;l++)
					ans+=(v2[i]+v2[l])*(v2[i]+v2[l]);
			cout<<ans<<'\n';
			return ;	
		}
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}