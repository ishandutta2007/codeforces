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
int t,n,k,f[2001][2001];
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		for(int l=0;l<=i;l++)
			f[i][l]=0;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		for(int l=0;l<i;l++)
		{
			f[i][l+1]=max(f[i][l+1],f[i-1][l]);
			f[i][l]=max(f[i][l],f[i-1][l]+(i-l==x));
		}
	}
	for(int i=0;i<=n;i++)
		if(f[n][i]>=k)
		{
			cout<<i<<endl;
			return ;
		}
	puts("-1");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}