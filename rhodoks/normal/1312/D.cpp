#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
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


int n,m;
LL dp[MAXN][2];
LL ans;
LL pow2[MAXN];
int main()
{
	fac_init(MAXN-10);
	pow2[1]=2;
	pow2[0]=1;
	for (int i=2;i<MAXN-10;i++)
	{
		pow2[i]=pow2[i-1]<<1;
		if (pow2[i]>MOD)
			pow2[i]-=MOD;
	}
	cin>>n>>m;
	for (int i=m;i>=n-1;i--)
	{
		//cout<<i-1<<' '<<n-2<<endl; 
		ans=ans+getC(i-1,n-2)*(n-2)%MOD*pow2[n-3]%MOD;
		//WRT(ans);
	}
	cout<<ans%MOD;
	return ~~(0^_^0);
}