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
int t,n,k;
int query(int x)
{
	cout<<x<<endl;
	cout.flush();
	int y=read();
	return y;
}
void solve()
{
	n=read();
	k=read();
	int tot=0;
	for(int i=0;i<n;i++)
	{
		int x=query(i^tot);
		if(x)
			return ;
		tot=i;
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}