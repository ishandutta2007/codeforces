#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int n,mod,ans,pw[402],jiechen[402],f[402][402],mem[402][402];
int qp(int x,int y)
{
	if(x==0)
		return 0;
	if(x==1)
		return 1;
	if(y==0)
		return 1;
	if(y==1)
		return x;
	int res=qp(x,y/2);
	(res*=res)%=mod;
	if(y&1)
		(res*=x)%=mod;
	return res;
}
int c(int x,int y)
{
//	cout<<x<<" "<<y<<endl;
	swap(x,y);
	if(mem[x][y])
		return mem[x][y];
	int ret=jiechen[y]*qp(jiechen[y-x],mod-2)%mod*qp(jiechen[x],mod-2)%mod;
	return mem[x][y]=ret;
}
signed main()
{
	n=read();
	mod=read();
	f[1][1]=1;
	f[2][1]=2;
	pw[0]=1;
	for(int i=1;i<=n+1;i++)
		pw[i]=(pw[i-1]*2)%mod;
	jiechen[0]=1;
	for(int i=1;i<=n+1;i++)
		jiechen[i]=(jiechen[i-1]*i)%mod;
	for(int i=3;i<=n;i++)
		for(int j=1;j<=(i+1)/2;j++)
		{
			if(j!=1)
				for(int k=1;k<=i-2;k++)
					(f[i][j]+=f[k][j-1]*c(i-j+1,i-k-1)%mod*pw[i-k-2]%mod)%=mod;
			else
				f[i][j]=pw[i-1];
			if(i==n)
				(ans+=f[i][j])%=mod;
		}
	cout<<ans;
	return 0;
}