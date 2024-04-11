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
const int mod=1e9+7;
int n,ans,a[1001],f[1001][20001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		f[i][10000-a[i]]=1;
		f[i][10000+a[i]]=1;
		for(int l=a[i];l<=20000;l++)
			(f[i][l]+=f[i-1][l-a[i]])%=mod;
		for(int l=0;l+a[i]<=20000;l++)
			(f[i][l]+=f[i-1][l+a[i]])%=mod;
		(ans+=f[i][10000])%=mod;
	}
	cout<<ans;
	return 0;
}