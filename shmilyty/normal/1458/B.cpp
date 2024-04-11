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
int n,tot,f[101][10001];
array<int,2> a[101];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		tot+=y;
		a[i]={y,x};
	}
	memset(f,-0x3f3f,sizeof(f));
	for(int i=0;i<=n;i++)
		f[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int l=i;l;l--)
			for(int j=100*l;j>=a[i][1]-a[i][0];j--)
				f[l][j]=max(f[l][j],f[l-1][j-(a[i][1]-a[i][0])]+a[i][0]);
	for(int i=1;i<=n;i++)
	{
		double ans=0.0;
		for(int l=0;l<=100*i;l++)
			ans=max(ans,f[i][l]+min(1.0*l,(tot-f[i][l])/2.0));
		printf("%.10lf ",ans);
	}
	return 0;
}