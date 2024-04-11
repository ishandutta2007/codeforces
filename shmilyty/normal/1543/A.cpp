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
int t,a,b;
void solve()
{
	a=read();
	b=read();
	if(a==b)
	{
		puts("0 0");
		return ;
	}
	cout<<abs(a-b)<<" ";
	int x=abs(min(a,b)%abs(a-b));
	cout<<min(x,abs(a-b)-x)<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}