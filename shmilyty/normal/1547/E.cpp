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
int T,n,k,a[300001],t[300001];
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=k;i++)
		a[i]=read();
	fill(t+1,t+1+n,1e10);
	for(int i=1;i<=k;i++)
		t[a[i]]=read();
	for(int i=2;i<=n;i++)
		t[i]=min(t[i-1]+1,t[i]);
	for(int i=n-1;i;i--)
		t[i]=min(t[i+1]+1,t[i]);
	for(int i=1;i<=n;i++)
		cout<<t[i]<<" ";
	cout<<endl;
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}