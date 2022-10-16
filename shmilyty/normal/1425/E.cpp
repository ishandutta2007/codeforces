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
int n,k,ans,a[100001],b[100001]; 
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]+=b[i-1];
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			ans=max(ans,b[n]-b[i-1]-a[i]);
		cout<<ans<<endl; 
		return 0;
	}
	if(k>1)
	{
		int minn=INF;
		for(int i=1;i<n;i++)
			minn=min(minn,a[i]);
		cout<<max({0ll,b[n]-minn,b[n]-b[n-1]-a[n]});
		return 0;
	}
	int minn=INF;
	for(int i=1;i<n;i++)
	{
		minn=min(minn,a[i]);
		int res1=0,res2=0;
		res1=max(res1,b[i]-minn);
		res2=max(res2,b[n]-b[i]-a[i+1]);
		ans=max(ans,res1+res2);
	}
	for(int i=2;i<=n;i++)
		ans=max(ans,b[n]-(b[i]-b[i-1])-a[1]);
	cout<<ans;
	return 0;
}