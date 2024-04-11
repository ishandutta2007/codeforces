#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL fac[201000];
LL inv[201000]; 
LL n,m;

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
LL ans=0;

int main()
{
	fac[1]=1;
	inv[0]=1;
	fac[0]=1;
	for (int i=2;i<=200100;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[200100]=mpow(fac[200100],MOD-2);
	for (int i=200100-1;i;i--)
		inv[i]=inv[i+1]*(i+1)%MOD;
	cin>>n>>m;
	for (int i=1;2*i<=n+2;i++)
		ans=ans+fac[n-i+1]*inv[i-1]%MOD*inv[n-2*i+2]%MOD;
	for (int i=1;2*i<=m+2;i++)
		ans=ans+fac[m-i+1]*inv[i-1]%MOD*inv[m-2*i+2]%MOD;
	ans-=1;
	ans=((ans*2)%MOD+MOD)%MOD;
	cout<<ans;
	//cout<<inv[1]<<' '<<inv[2]<<endl;
	return ~~(0^_^0);
}