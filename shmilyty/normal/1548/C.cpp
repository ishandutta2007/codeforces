#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int n,q,fac[3000002],inv[3000001],g[3000002],f[3000001][4];
signed main()
{
	n=read();
	q=read();
	fac[0]=1;
	for(int i=1;i<=3*n+1;i++)
		fac[i]=(fac[i-1]*i)%mod;
	inv[3*n]=qp(fac[3*n],mod-2);
	g[0]=1;
	g[1]=1;
	for(int i=2;i<=3*n+1;i++)
		g[i]=((mod-mod/i)*g[mod%i])%mod;
//	cout<<g[2]<<endl;
	for(int i=3*n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<=3;i++)
		f[1][i]=(3*n+i*2-3)*n%mod*g[2]%mod;
	for(int i=2;i<=3*n;i++)
	{
		int x=i*f[i-1][1]%mod;
		int y=i*f[i-1][2]%mod;
		int lst=fac[3*n+1]*inv[3*n-i]%mod*g[i+1]%mod;
		f[i][1]=(g[3]*((lst-(2*x%mod+y)%mod+mod)%mod))%mod;
		f[i][2]=(f[i][1]+x)%mod;
		f[i][3]=(f[i][2]+y)%mod;
//		cout<<x<<" "<<y<<" "<<lst<<endl; 
	}
	while(q--)
	{
		int x=read();
		cout<<f[x][3]*inv[x]%mod<<endl;
	}
	return 0;
}