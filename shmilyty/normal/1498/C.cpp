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
int t,n,k,f[1001][1001][2];
const int mod=1e9+7;
int dfs(int nn,int kk,int pos)
{
	if(f[nn][kk][pos])
		return f[nn][kk][pos];
	if(nn==0||nn==n+1)
		return f[nn][kk][pos]=f[nn][kk][pos]=1;
	if(kk==1)
		return f[nn][kk][pos]=1;
	if(pos==1&&nn==n)
		return f[nn][kk][pos]=(1+dfs(nn-1,kk-1,0))%mod;
	if(pos==0&&nn==1)
		return f[nn][kk][pos]=(1+dfs(nn+1,kk-1,1))%mod;
	if(pos)
		return f[nn][kk][pos]=(dfs(nn-1,kk-1,0)+dfs(nn+1,kk,1))%mod;
	return f[nn][kk][pos]=(dfs(nn+1,kk-1,1)+dfs(nn-1,kk,0))%mod;
}
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		k=read();
		for(int i=0;i<=n;i++)
			for(int l=0;l<=k;l++)
				f[i][l][0]=f[i][l][1]=0;
		cout<<dfs(1,k,1)<<endl;
	}
	return 0;
}