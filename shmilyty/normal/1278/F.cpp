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
int n,m,k,ans,p,f[5001][5001];
int qp(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			(res*=x)%=mod;
		y>>=1;
		(x*=x)%=mod;
	}
	return res;
}
signed main()
{
	n=read();
	m=read();
	k=read();
	f[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int l=1;l<=i;l++)
			f[i][l]=(f[i-1][l]*l+f[i-1][l-1]*(n-l+1))%mod;
	p=qp(m,mod-2);
	for(int i=1;i<=k;i++)
		(ans+=f[k][i]*qp(p,i)%mod)%=mod;
	cout<<ans;
	return 0;
}