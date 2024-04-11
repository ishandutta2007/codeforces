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
int T,n,a[500001],vis[500001],t[500001];
#define lowbit(x) (x&(-x))
void add(int x)
{
	for(;x<=n;x+=lowbit(x))
		t[x]++;
}
int ask(int x)
{
	int res=0;
	for(;x;x^=lowbit(x))
		res+=t[x];
	return res;
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	fill(vis+1,vis+1+n,0);
	fill(t+1,t+1+n,0);
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]])
		{
			puts("YES");
			return ;
		}
		vis[a[i]]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=i-1-ask(a[i]);
		add(a[i]);
	}
	if(ans&1)
		puts("No");
	else
		puts("yes");
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}