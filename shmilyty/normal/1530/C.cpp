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
int t,n,a[100001],b[100001];
bool check(int x)
{
	int k=x+n;
	int tot=k-k/4;
	if(tot<=x)
		return 1;
	return (x*100+a[tot-x])>=b[min(n,tot)];
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	sort(a+1,a+1+n,greater<int>());
	sort(b+1,b+1+n,greater<int>());
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
		b[i]+=b[i-1];
	int l=0,r=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}