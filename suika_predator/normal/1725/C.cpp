#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	long long n,m;
	cin>>n>>m;
	if(n==1)
	{
		cout<<m<<endl;
		return 0;
	}
	auto poww=[&](long long x,int y)
	{
		long long ret=1;
		while(y)
		{
			if(y&1)ret*=x,ret%=MOD;
			x*=x,x%=MOD;
			y>>=1;
		}
		return ret;
	};
	vector<long long> fac(333333+5),ifac(333333+5);
	fac[0]=1;
	for(int i=1;i<=333333;i++)fac[i]=fac[i-1]*i%MOD;
	ifac[333333]=poww(fac[333333],MOD-2);
	for(int i=333333;i>=1;i--)ifac[i-1]=ifac[i]*i%MOD;
	auto C=[&](int n,int m)
	{
		return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
	};
	auto get=[&](long long b)
	{
		long long ret=0;
		for(int i=0;i<=min(b,m);i++)
		{
			ret+=C(b,i)*C(m,i)%MOD*fac[i]%MOD*poww((m-i)*(m-i-1)%MOD,b-i)%MOD*poww(m-i,n-b*2)%MOD;
//			cerr<<i<<' '<<ret<<' '<<C(b,i)<<' '<<C(m,i)<<' '<<poww((m-i)*(m-i-1)%MOD,b-i)<<' '<<poww(m-i,n-b*2)<<endl;
		}
		return (ret%MOD+MOD)%MOD;
	};
	vector<long long> a(n+5),s(n+5);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	long long S=s[n];
	if(S%2!=0)
	{
		cout<<get(0)<<endl;
		return 0;
	}
	int pre=1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		while(s[i]-s[pre]>S/2)pre++;
		if(s[i]-s[pre]==S/2)cnt++;
	}
//	cerr<<cnt<<endl;
	cout<<get(cnt)<<endl;
	return 0;
}