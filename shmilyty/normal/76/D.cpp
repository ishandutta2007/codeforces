#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int __int128
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
int a,b,v=1,ans1,ans2;
signed main()
{
	a=read();
	b=read();
	while(a||b)
	{
		if((a&1)!=(b&1))
			break;
		if(a&1)
			ans2+=v;
		elif((b&2)!=(a&2))
		{
			a-=2;
			ans1+=v;
			ans2+=v;
		}
		a>>=1;
		b>>=1;
		v<<=1;
	}
	if(a&b)
	{
		puts("-1");
		return 0;
	}
	cout<<(long long)ans1<<" "<<(long long)ans2;
	return 0;
}