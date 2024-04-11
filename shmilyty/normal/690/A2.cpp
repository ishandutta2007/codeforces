#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
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
int n;
signed main()
{
	n=read();
	if(n&1)
		cout<<n/2;
	else
	{
		int x=sizeof(int)*8-__builtin_clz(n)-1;
		cout<<(n-(1<<x))/2;
	}
	return 0;
}