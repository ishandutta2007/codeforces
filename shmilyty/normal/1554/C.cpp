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
int t,n,m;
void solve()
{
	n=read();
	m=read()+1;
	if(n>=m)
	{
		puts("0");
		return ;
	}
	int ans=0;
	for(int i=30;i>=0;i--)
	{
		if(((n>>i)&1)&&(!((m>>i)&1)))
			break;
		if(((m>>i)&1)&&(!((n>>i)&1)))
			ans+=(1<<i);
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