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
set<pair<int,int>> s;
int t,n,m,fa[100001];
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		fa[i]=0;
	while(m--)
	{
		int x=read(),y=read(),z=read();
		fa[y]=1;
	}
	for(int i=1;i<=n;i++)
		if(!fa[i])
		{
			for(int l=1;l<=n;l++)
				if(l!=i)
					cout<<i<<" "<<l<<endl;
			return ;
		}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}