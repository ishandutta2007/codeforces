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
int t,n,res,ans[1000001];
array<int,2> a[1000001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]={-read(),i};
	sort(a+1,a+1+n);
	res=0;
	for(int i=1;i<=n;i++)
	{
		res-=a[i][0]*((i+1)/2);
		if(i&1)
			ans[a[i][1]]=(i+1)/2; 
		else
			ans[a[i][1]]=-i/2;
	}
	cout<<res*2<<endl;
	for(int i=0;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}