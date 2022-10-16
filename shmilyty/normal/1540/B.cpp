#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
const int mod=1e9+7;
int n,ans,dis[201][201],f[201][201];
int qp(int x,int y)
{
	if(x==1)
		return 1;
	if(y==0)
		return 1;
	if(y==1)
		return x;
	int ans=qp(x,y/2);
	(ans*=ans)%=mod;
	if(y&1)
		(ans*=x)%=mod;
	return ans;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)	
		for(int l=1;l<=n;l++)
			dis[i][l]=114514114514114514;
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		dis[x][y]=dis[y][x]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int l=1;l<=n;l++)
				dis[i][l]=min(dis[i][l],dis[i][k]+dis[k][l]);
	for(int i=1;i<=n;i++)
		f[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			f[i][l]=(f[i-1][l]+f[i][l-1])*500000004%mod;
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			for(int j=1;j<=n;j++)
			{
				int x=dis[i][j],y=dis[l][j],d=(x+y-dis[i][l])/2;
				x-=d;
				y-=d;
				(ans+=f[x][y])%=mod;
			}
	cout<<(ans*qp(n,mod-2))%mod;
	return 0;
}