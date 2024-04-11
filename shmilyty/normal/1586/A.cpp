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
int t,n,sum,a[101],f[20001];
int pri(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 1;
	return 0;
}
void solve()
{
	n=read();
	sum=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	if(pri(sum))
	{
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
			cout<<i<<" ";
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(pri(sum-a[i]))
		{
			cout<<n-1<<endl;
			for(int l=1;l<=n;l++)
				if(l!=i)
					cout<<l<<" ";
			cout<<endl;
			return ;
		}
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			if(pri(sum-a[i]-a[l]))
			{
				cout<<n-2<<endl;
				for(int j=1;j<=n;j++)
					if(j!=i&&j!=l)
						cout<<j<<" ";
				cout<<endl;
				return ;
			}
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			for(int j=l+1;j<=n;j++)
				if(pri(sum-a[i]-a[l]-a[j]))
				{
					cout<<n-3<<endl;
					for(int k=1;k<=n;k++)
						if(i!=k&&l!=k&&j!=k)
							cout<<k<<" ";
					cout<<endl;
					return ;
				}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}