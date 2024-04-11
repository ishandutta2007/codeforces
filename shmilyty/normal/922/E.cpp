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
int n,w,b,x,sum,c[1001],cst[1001],f[1001][10001];
signed main()
{
	n=read();
	w=read();
	b=read();
	x=read();
	for(int i=1;i<=n;i++)
		c[i]=read();
	for(int i=1;i<=n;i++)
		cst[i]=read();
	memset(f,-1,sizeof(f));
	f[0][0]=w;
	for(int i=1;i<=n;i++)
	{
		sum+=c[i];
		for(int l=0;l<=sum;l++)
			for(int j=0;j<=c[i]&&j<=l;j++)
			{
				if(f[i-1][l-j]==-1)
					continue;
				if(f[i-1][l-j]<cst[i]*j)
					continue;
				f[i][l]=max(f[i][l],min(f[i-1][l-j]-cst[i]*j+x,w+l*b));	
			}
	}
	for(int i=sum;~i;i--)
		if(f[n][i]!=-1)
		{
			cout<<i;
			return 0;
		}
	return 0;
}