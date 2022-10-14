#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 310000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL mpow(LL x,LL n)
{
	LL ans=1;
	while (n)
	{
		if (n&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return ans;
} 

LL inv(LL x)
{
	return mpow(x,MOD-2);
}

LL fac[MAXN+3];
LL invfac[MAXN+3];

void fac_init(int n=MAXN)
{
	fac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	invfac[n]=inv(fac[n]);
	for (int i=n;i;i--)
		invfac[i-1]=invfac[i]*i%MOD;
}

LL getC(int n,int x)
{
	return fac[n]*invfac[x]%MOD*invfac[n-x]%MOD;
}

LL n;
LL a[MAXN];
LL sum[MAXN];
int main()
{
	fac_init();
	cin>>n;
	for (int i=1;i<=2*n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+2*n+1);
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		ans-=a[i];
		ans+=a[i+n]; 
	}
	ans=ans%MOD+MOD;
	cout<<ans%MOD*getC(2*n,n)%MOD;
	return ~~(0^_^0);
}