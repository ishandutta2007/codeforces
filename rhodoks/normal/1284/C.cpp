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

#define MAXN 310000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,m;
LL fac[MAXN];
int main()
{
	cin>>n>>m;
	fac[0]=1;
	for (int i=1;i<=300000;i++)
		fac[i]=fac[i-1]*i%m;
	LL ans=0;
	for (LL k=n;k>=0;k--)
		ans=(ans+k*(n-k+1)%m*fac[k]%m*fac[n-k]%m)%m;
	cout<<ans;
	return ~~(0^_^0);
}