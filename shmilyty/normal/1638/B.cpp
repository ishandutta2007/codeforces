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
int t,n;
vector<int> v1,v2; 
void solve()
{
	n=read();
	v1.clear();
	v2.clear();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(x&1)
			v1.push_back(x);
		else
			v2.push_back(x);
	}
	for(int i=1;i<v1.size();i++)
		if(v1[i-1]>v1[i])
		{
			puts("No");
			return ;
		}
	for(int i=1;i<v2.size();i++)
		if(v2[i-1]>v2[i])
		{
			puts("No");
			return ;
		}
	puts("Yes");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}