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
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int n,ans,a[200001],lg[200001],f[200001][25];
int query(int l,int r)
{
	int x=lg[r-l+1];
//	cout<<l<<" "<<r<<" "<<x<<endl;
	return __gcd(f[l][x],f[r-(1<<x)+1][x]);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	lg[0]=-1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
		f[i][0]=a[i];
	for(int i=1;i<=24;i++)
		for(int l=1;l+(1<<i)-1<=n;l++)
			f[l][i]=__gcd(f[l][i-1],f[l+(1<<(i-1))][i-1]);
	int lst=0;
	for(int i=1;i<=n;i++)
	{
		int l=lst+1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(query(mid,i)<=i-mid+1)
				l=mid+1;
			else
				r=mid-1;
		}
		l=max(l-1,lst+1);
		if(query(l,i)==i-l+1)
		{
			lst=i;
			ans++;
		}
		cout<<ans<<' ';
	}
	return 0;
}