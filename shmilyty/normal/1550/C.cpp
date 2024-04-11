#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int t,n,ans,a[200001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	ans=0;
	for(int i=3;i<=5;i++)
		for(int l=1;l+i-1<=n;l++)
		{
			int j=l+i-1;
			bool flag=1;
			for(int i1=l;i1<=j;i1++)
				for(int i2=i1+1;i2<=j;i2++)
					for(int i3=i2+1;i3<=j;i3++)
					{
						if(a[i1]<=a[i2]&&a[i2]<=a[i3])
							flag=0;
						if(a[i1]>=a[i2]&&a[i2]>=a[i3])
							flag=0;
					}
			ans+=flag;
		}
	cout<<ans+2*n-1<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}