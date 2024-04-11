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
string s;
int x;
signed main()
{
	cin>>s;
	x=read();
	if(s=="ABC")
		if(x<2000)
		{
			puts("YES");
			return 0;
		}
	if(s=="ARC")
		if(x<2800)
		{
			puts("YES");
			return 0;
		}
	if(s=="AGC")
		if(x>=1200)
		{
			puts("YES");
			return 0;
		}
	if(s=="AHC")
		{
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}