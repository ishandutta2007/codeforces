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
int t,n,ans,a[101];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	ans=INF;
	for(int k=0;k<=2;k++)
		for(int j=0;j<=2;j++)
		{
			int mx=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]%3==0)
					mx=max(mx,a[i]/3-min(k,j));
				if(a[i]%3==1)
				{
					if(!k)
					{
						if(j!=2||a[i]<3)
						{
							mx=INF;
							break;
						}
						mx=max(mx,a[i]/3-1);
					}
					else
						mx=max(mx,a[i]/3-min(k-1,j));
				}
				if(a[i]%3==2)
				{
					mx=max(mx,a[i]/3-min(k,j-1));
					if(k!=2&&!j)
					{
						mx=INF;
						break;
					}
				}
			}
			ans=min(mx+j+k,ans);
		}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}