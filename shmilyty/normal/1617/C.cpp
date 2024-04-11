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
int t,n,m,a[200001];
set<int> s;
vector<int> v;
void solve()
{
	n=read();
	s.clear();
	v.clear();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]<=n&&!s.count(a[i]))
			s.insert(a[i]);
		else
			v.push_back((a[i]-1)/2);
	}
	sort(ALL(v),greater<int>());
	for(int i=1;i<=n;i++)
		if(!s.count(i))
		{
			if(v.back()<i)
			{
				puts("-1");
				return ;
			}
			v.pop_back();
		}
	cout<<n-s.size()<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}