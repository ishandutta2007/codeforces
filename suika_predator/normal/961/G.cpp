#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,inv2=500000004;
long long pw(long long x,int y)
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
long long fac[233333],ifac[233333];
long long C(int n,int k)
{
	return fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}
long long S2(int n,int k)
{
	long long ret=0;
	for(int i=1;i<=k;i++)
	{
		ret+=((k-i)%2?-1:1)*pw(i,n)*C(k,i)%MOD;
	}
	return (ret%MOD+MOD)%MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s+=x;
	}
	fac[0]=1;
	for(int i=1;i<=n+10;i++)fac[i]=fac[i-1]*i%MOD;
	ifac[n+10]=pw(fac[n+10],MOD-2);
	for(int i=n+10;i>=1;i--)ifac[i-1]=ifac[i]*i%MOD;
//	cerr<<S2(n-1,k)<<endl;
	cout<<s%MOD*(S2(n-1,k)%MOD*(n-1)%MOD+S2(n,k))%MOD*ifac[k]%MOD<<endl;
	return 0;
}