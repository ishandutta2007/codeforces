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
int t,n;
void solve()
{
	n=read();
	if(n&1)
	{
		cout<<'c';
		n--;
		if(n==0)
		{
			cout<<endl;
			return ;
		}
	}
	for(int i=1;i*2<=n;i++)
		cout<<'a';
	cout<<'b';
	for(int i=1;i<n/2;i++)
		cout<<'a';
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}