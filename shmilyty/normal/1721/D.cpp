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
int T,n,ans,a[100001],b[100001];
std::vector<int> v1,v2;
int solve(int x)
{
	v1.clear();
	v2.clear();
	for(int i=1;i<=n;i++)
		v1.push_back(a[i]&x);
	for(int i=1;i<=n;i++)
		v2.push_back(((1<<30)-1-b[i])&x);
	sort(ALL(v1));
	sort(ALL(v2));
	return v1==v2;
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	ans=0;
	for(int i=29;~i;i--)
		if(solve(ans|(1<<i)))
			ans|=(1<<i);
	cout<<ans<<'\n';
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}