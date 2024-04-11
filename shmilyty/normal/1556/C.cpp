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
int n,ans,a[1001],f[1001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read()*(i%2?1:-1);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i+=2)
	{
		int minn=0,sum;
		for(int l=i+1;l<=n;l+=2)
		{
			sum=f[l-1]-f[i];
			int s=sum-minn;
//			cout<<i<<" "<<l<<" "<<sum<<" "<<minn<<" "<<s<<endl;
			ans+=max(0ll,min(a[i]+(minn!=0?minn+1:0),-a[l]+(s!=0?-s+1:-s)));
//			cout<<ans<<endl;
			minn=min(minn,f[l]-f[i]);
		}
	}
	cout<<ans;
	return 0;
}