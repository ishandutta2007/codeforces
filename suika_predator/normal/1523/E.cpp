#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,lim=212122;
long long fac[233333],ifac[233333];
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
inline long long C(long long n,long long m)
{
	if(n<0||m<0||m>n)return 0;
	else return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int main()
{
	int T;
	long long n,k;
	fac[0]=1;
	for(int i=1;i<=lim;i++)fac[i]=fac[i-1]*i%MOD;
	ifac[lim]=poww(fac[lim],MOD-2);
	for(int i=lim;i>=1;i--)ifac[i-1]=ifac[i]*i%MOD;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		long long ans=0;
		for(int i=0;i<=n;i++)
		{
			ans+=C(n-(i-1)*(k-1),i)*fac[n-i]%MOD*fac[i]%MOD;
		}
		cout<<ans%MOD*ifac[n]%MOD<<endl;
	}
	return 0;
}