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
const int mod=31607;
int qp(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			(res*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return res;
}
int n,inv,lim,ans,pc[1<<21],a[21][21],g[21][1<<21],f[1<<21];
signed main()
{
	inv=qp(10000,mod-2);
	n=read();
	lim=(1<<n);
	for(int i=1;i<lim;i++)
		pc[i]=pc[i^lowbit(i)]+1;
	for(int i=0;i<n;i++)
	{
		g[i][0]=1;
		for(int l=0;l<n;l++)
		{
			a[i][l]=read()*inv%mod;
			g[i][1<<l]=a[i][l];
		}
		for(int l=1;l<lim;l++)
			g[i][l]=g[i][lowbit(l)]*g[i][l^lowbit(l)]%mod;
	}
	for(int i=0;i<=3;i++)
	{
		for(int l=0;l<lim;l++)
			if((pc[i]+pc[l])&1)
				f[l]=mod-1;
			else
				f[l]=1;
		for(int l=0;l<n;l++)
			for(int j=0;j<lim;j++)
			{
				int st=j;
				if(i&1)
					st|=(1<<l);
				if(i&2)
					st|=(1<<(n-l-1));
				int val=(mod+g[l][st]-g[l][lim-1])%mod;
				(f[j]*=val)%=mod;
			}
		for(int l=0;l<lim;l++)
			(ans+=f[l])%=mod;
	}
	cout<<(1+mod-ans)%mod;
	return 0;
}