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
vector<int> a,v[61];
void solve()
{
	n=read();
	a.clear();
	while(n)
	{
		a.push_back(n%10);
		n/=10;
	}
	reverse(a.begin(),a.end());
	int ans=INF;
	for(int i=0;i<=60;i++)
	{
		int y=0;
		for(int l:a)
			if(y!=v[i].size()&&l==v[i][y])
				y++;
		ans=min(ans,((int)a.size())-y+((int)v[i].size())-y);
	}
	cout<<ans<<endl;
}
signed main()
{
	int cnt=1;
	for(int i=0;i<=60;i++)
	{
		int x=cnt;
		while(x)
		{
			v[i].push_back(x%10);
			x/=10;
		}
		reverse(v[i].begin(),v[i].end());
		cnt*=2;
	}
	t=read();
	while(t--)
		solve();
	return 0;
}