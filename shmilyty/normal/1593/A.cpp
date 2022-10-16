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
int t,a,b,c;
void solve()
{
	a=read();
	b=read();
	c=read();
	cout<<max(0ll,max(b,c)+1-a)<<" "<<max(0ll,max(a,c)+1-b)<<" "<<max(0ll,max(b,a)+1-c)<<endl;
 } 
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}