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

signed main()
{
	int n=read();
	if(n<1200)puts("1200");
		else if(n<1400)puts("1400");
		else if(n<1600)puts("1600");
		else if(n<1900)puts("1900");
		else if(n<2100)puts("2100");
		else if(n<2300)puts("2300");
		else if(n<2400)puts("2400");
		else if(n<2600)puts("2600");
		else puts("3000");

	return 0;
}