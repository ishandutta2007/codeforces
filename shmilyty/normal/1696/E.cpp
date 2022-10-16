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
const int mod=1e9+7,i2=(mod+1)/2;
int n,fac[400001],inv[400001];
int C(int x,int y)
{
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=400000;i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=400000;i++)
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(int i=2;i<=400000;i++)
		(inv[i]*=inv[i-1])%=mod;
	n=read();
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int x=read();
		(ans+=C(i+x,i+1))%=mod;
	}
	cout<<ans;
	return 0;
}