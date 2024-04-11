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
int t,n;
vector<array<int,2>> lst[1001];
array<int,2> a[1001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		lst[i].clear();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]={x,y};
		for(int l=x;l<=y;l++)
			lst[l].push_back({y-x+1,i});
	}
	for(int i=1;i<=n;i++)
		sort(ALL(lst[i]));
	for(int i=1;i<=n;i++)
		cout<<a[lst[i][0][1]][0]<<" "<<a[lst[i][0][1]][1]<<" "<<i<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}