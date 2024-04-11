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
const int mod=998244353;
int n,k,C[501][501],f[501][501];
int qp(int x,int y)
{
	if(x<=1||y==1)
		return x;
	if(y==0)
		return 1;
	int res=qp(x,y/2);
	(res*=res)%=mod;
	if(y&1)
		(res*=x)%=mod;
	return res;
}
int dfs(int x,int y)
{
	if(x==0)
		return 1;
	if(x==1)
		return 0;
	if(f[x][y])
		return f[x][y];
	if(y<x)
		return qp(y,x);
	int res=0;
	for(int i=0;i<=x;i++)
		(res+=dfs(x-i,y-x+1)*qp(x-1,i)%mod*C[x][i]%mod)%=mod;
	return f[x][y]=res;
}
signed main()
{
	n=read();
	k=read();
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int l=1;l<=i;l++)
			C[i][l]=(C[i-1][l]+C[i-1][l-1])%mod;
	}
	cout<<dfs(n,k)<<endl;
	return 0;
}