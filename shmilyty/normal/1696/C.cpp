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
int t,n,m,k;
vector<array<int,2>> v1,v2;
void solve()
{
	n=read();
	m=read();
	v1.clear();
	v2.clear();
	while(n--)
	{
		int x=read();
		int y=1;
		while(x%m==0)
		{
			x/=m;
			y*=m;
		}
		if(!v1.empty()&&v1.back()[0]==x)
			v1.back()[1]+=y;
		else
			v1.push_back({x,y});
	}
	k=read();
	while(k--)
	{
		int x=read(),y=1;
		while(x%m==0)
		{
			x/=m;
			y*=m;
		}
		if(!v2.empty()&&v2.back()[0]==x)
			v2.back()[1]+=y;
		else
			v2.push_back({x,y});
	}
	if(v1==v2)
		puts("Yes");
	else
		puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}