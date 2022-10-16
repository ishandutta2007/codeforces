#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
vector<int> v;
void solve()
{
	n=read();
	cout<<v[n-1]<<endl;
}
signed main()
{
	for(int i=1;i<=4000;i++)
	{
		if((int)v.size()==1000)
			break;
		if(i%3==0)
			continue;
		if(i%10==3)
			continue;
		int x=i,flag=1;
		if(flag)
			v.push_back(i);
	}
	t=read();
	while(t--)
		solve();
	return 0;
}