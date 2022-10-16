#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int t,n,k,s,a[100001];
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	s=max(1ll,n-200);
	int ans=-INF;
	for(int i=s;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			ans=max(ans,i*l-k*(a[i]|a[l]));
	cout<<ans<<endl; 
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}