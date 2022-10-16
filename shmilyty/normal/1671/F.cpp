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
const int mod=998244353;
int n,k1,k2,t,inv[51],f[51][12][12][12],g[51][12][12];
int calc(int x)
{
	int res=0;
	for(int i=1;i<=20;i++)
	{
		int t=g[i+20][k1][k2];
		for(int l=1;l<=20;l++)
			if(l!=i)
			{
				(t*=(x+mod-l))%=mod;
				if(i>l)
					(t*=inv[i-l])%=mod;
				else
					(t*=(mod-inv[l-i]))%=mod;
			}
			(res+=t)%=mod;
	}
	return res;
}
void solve()
{
	n=read();
	k1=read();
	k2=read();
	if(n<=50)
		cout<<g[n][k1][k2]<<'\n';
	else
		cout<<calc(n-20)%mod<<'\n';
}
signed main()
{
	inv[0]=inv[1]=1;
	for(int i=2;i<=50;i++)
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	// for(int i=2;i<=50;i++)
		// (inv[i]*=inv[i-1])%=mod;
	t=read();
	f[0][0][0][0]=1;
	for(int i=0;i<50;i++)
		for(int l=0;l<=11;l++)
			for(int j=0;j<=11;j++)
				for(int k=0;k<=11;k++)
					for(int jj=0;jj<=min(11-j,i);jj++)
						(f[i+1][jj][j+jj][k+(jj>l)]+=f[i][l][j][k])%=mod;
	for(int i=0;i<=50;i++)
		for(int l=0;l<=11;l++)
			for(int j=0;j<=11;j++)
				for(int k=0;k<=11;k++)
					(g[i][j][k]+=f[i][l][j][k])%=mod;
	while(t--)
		solve();
	return 0;
}