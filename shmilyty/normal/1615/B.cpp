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
int t,l,r,f[200001][21];
void solve()
{
	l=read();
	r=read();
	int res=0;
	for(int i=0;i<=20;i++)
		res=max(res,f[r][i]-f[l-1][i]);
	cout<<r-l+1-res<<endl;
}
signed main()
{
	t=read();
	for(int i=0;i<=20;i++)
	{
		for(int l=1;l<=200000;l++)
			if((l>>i)&1)
				f[l][i]=f[l-1][i]+1;
			else
				f[l][i]=f[l-1][i];
	}
	while(t--)
		solve();
	return 0;
}