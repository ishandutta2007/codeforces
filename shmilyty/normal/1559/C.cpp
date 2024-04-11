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
int t,n,a[10001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(a[1]==1)
	{
		cout<<n+1;
		for(int i=1;i<=n;i++)
			cout<<" "<<i;
		cout<<endl;
		return ;	
	} 
	if(a[n]==0)
	{
		for(int i=1;i<=n+1;i++)
			cout<<i<<" ";
		cout<<endl;
		return ;
	}
	for(int i=1;i<n;i++)
		if(a[i]==0&&a[i+1]==1)
		{
			for(int l=1;l<=i;l++)
				cout<<l<<" ";
			cout<<n+1;
			for(int l=i+1;l<=n;l++)
				cout<<" "<<l;
			cout<<endl;
			return ; 
		}
	puts("-1");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}