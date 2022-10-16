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
int t,n,m,k;
void solve()
{
	n=read();
	m=read();
	k=read();
	int x=n%m;
	for(int i=0,j=0;i<k;i++,j=(j+x*(n/m+1))%n)
	{
		for(int l=1;l<=x;l++)
		{
			cout<<n/m+1;
			for(int q=0;q<=n/m;q++,j=(j+1)%n)
				cout<<" "<<j+1;
			cout<<'\n'; 
		}
		for(int l=x+1;l<=m;l++)
		{
			cout<<n/m;
			for(int q=1;q<=n/m;q++,j=(j+1)%n)
				cout<<" "<<j+1;
			cout<<'\n';
		}
	}
	cout<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}