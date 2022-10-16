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
int t,a,s;
vector<int> b;
void solve()
{
	a=read();
	s=read();
	b.clear();
	while(a)
	{
		int x=a%10;
		if(s%10>=x)
		{
			b.push_back(s%10-x);
			s/=10;
		}
		else
		{
			b.push_back(s%100-x);
			s/=100;
		}
		a/=10;
	}
	for(int i:b)
		if(i<0||i>9)
		{
			puts("-1");
			return ;
		}
	if(!s)
	{
		while(b.back()==0)
			b.pop_back();
	}
	reverse(ALL(b));
	if(s)
		cout<<s;
	for(int i:b)
		cout<<i;
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}