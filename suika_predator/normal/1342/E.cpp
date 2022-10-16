//S(n,m)=1/m!*sigma((-1)^k*C(m,k)*(m-k)^n))
#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
inline long long poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
inline long long inv(int x)
{
	return poww(x,MOD-2);
}
int n,k;
long long fac[233333];
inline long long C(int x,int y)
{
	return fac[x]*inv(fac[x-y]*fac[y]%MOD)%MOD;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<=200000;i++)fac[i]=fac[i-1]*i%MOD;
	cin>>n>>k;
	if(k==0)return cout<<fac[n]<<endl,0;
	else if(k>=n)return cout<<0<<endl,0;
	long long s=0;
	for(int i=0;i<=n-k;i++)s+=1ll*poww(MOD-1,i)*C(n-k,i)%MOD*poww(n-k-i,n)%MOD;
	s%=MOD;
	cout<<2*s%MOD*C(n,n-k)%MOD<<endl;
	return 0;
}