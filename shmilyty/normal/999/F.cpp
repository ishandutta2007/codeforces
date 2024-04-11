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
int n,k,ans,c[5001],f[501],h[11],dp[5001][501],num1[100001],num2[100001];
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n*k;i++)
		num1[read()]++;
	for(int i=1;i<=n;i++)
	{
		f[i]=read();
		num2[f[i]]++;
	}
	for(int i=1;i<=k;i++)
		h[i]=read();
	sort(f+1,f+1+n);
	for(int i=1;i<=n*k;i++)
	{
		int minn=min(i,k);
		dp[i][1]=h[minn];
		for(int l=2;l<=n;l++)
			for(int j=1;j<=minn;j++)
				dp[i][l]=max(dp[i][l],dp[i-j][l-1]+h[j]);
	}
	for(int i=1;i<=n;)
	{
		ans+=dp[num1[f[i]]][num2[f[i]]];
		i+=num2[f[i]];
	}
	cout<<ans; 
	return 0;
}