#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int t,n,k,bi[200001],Inv[200001],fac[200001],f[2][2],sum[200001],sum1[200001];
const int mod=1e9+7;
int qp(int x,int y)
{
	if(x<=1)
		return x;
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
int C(int x,int y)
{
	return fac[y]*Inv[y-x]%mod*Inv[x]%mod;
}
void solve()
{
	n=read();
	k=read();
	if(k==0)
	{
		puts("1");
		return ;
	}
	f[0][0]=f[0][1]=0;
	for(int i=1;i<=n;i++)
		if((n-i)%2==0)
			(f[0][0]+=C(i,n))%=mod;
		else
			(f[0][1]+=C(i,n))%=mod;
	f[1][0]=1;
	f[1][1]=0;
	if(n&1)
		swap(f[1][0],f[1][1]);
	sum[0]=1;
	for(int i=1;i<=k;i++)
		sum[i]=(sum[i-1]*(f[0][0]+f[1][1]))%mod;
	sum1[0]=1;
	for(int i=1;i<=k;i++)
		sum1[i]=(sum1[i-1]*(f[0][0]+f[1][1]+f[1][0]+f[0][1]))%mod;
	int ans=sum[k];
	for(int i=1;i<=k;i++)
		(ans+=sum[i-1]*f[1][0]%mod*sum1[k-i]%mod)%=mod;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	bi[0]=1;
	for(int i=1;i<=2e5;i++)
		bi[i]=bi[i-1]*2%mod;
	fac[0]=1;
	for(int i=1;i<=2e5;i++)
		fac[i]=(fac[i-1]*i)%mod;
	Inv[200000]=qp(fac[200000],mod-2);
	for(int i=199999;i>=0;i--)
		Inv[i]=Inv[i+1]*(i+1)%mod;
	while(t--)
		solve();
	return 0;
}