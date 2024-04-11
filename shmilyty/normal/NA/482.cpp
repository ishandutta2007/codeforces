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
int t,n,q,a[100001],ok[100001];
bool check(int x)
{
	int k=q;
	for(int i=1;i<=n;i++)
	{
		if(!k)
			break;
		ok[i]=0;
		// cout<<i<<" "<<x<<endl;
		if(a[i]<=k)
		{
			ok[i]=1;
			x--;
		}
		if(a[i]>k&&i>=n-x+1)
		{
			ok[i]=1;
			x--;
			k--;
		}
	} 
	// cout<<"x:"<<x<<endl;
	if(x<=0)
		return 1;
	return 0;
}
void solve()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	int l=1,r=n;
	// cout<<check(3)<<endl;
	
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	// cout<<check(l)<<endl;
	// cout<<l-1<<endl;
	check(l-1);
	for(int i=1;i<=n;i++)
		cout<<ok[i];
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}