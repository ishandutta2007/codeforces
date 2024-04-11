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
int t,n,m,ans,fa[200001];
array<int,3> a[200001];
vector<int> v;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if((a[i][2]>>x)&1)
			continue;
		bool flag=1;
		for(int l:v)
			if((a[i][2]>>l)&1)
			{
				flag=0;
				break;
			}
		if(!flag)
			continue;
		fa[find(a[i][1])]=find(a[i][0]);
	}
	for(int i=1;i<=n;i++)
		if(find(i)!=find(1))
			return 0;
	return 1;
}
void solve()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		a[i]={x,y,z};
	}
	v.clear();
	ans=0;
	for(int i=31;~i;i--)
		if(check(i))
			v.push_back(i);
		else
			ans+=(1ll<<i);
	cout<<ans<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}