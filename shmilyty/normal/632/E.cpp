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
int n,k,mn,mx,a[1001];
int f[1000001];
signed main()
{
	n=read();
	k=read();
	mn=INF;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		mn=min(mn,a[i]);
	}
	for(int i=1;i<=n;i++)
		a[i]-=mn;
	for(int i=1;i<=n;i++)
		mx=max(mx,a[i]);
	mx*=k;
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
		if(a[i])
		{
			for(int l=a[i];l<=mx;l++)
				f[l]=min(f[l],f[l-a[i]]+1);
		}
	for(int i=0;i<=mx;i++)
		if(f[i]<=k)
			cout<<i+mn*k<<" ";
	return 0;
}