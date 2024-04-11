// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int inv[N],fac[N],ifac[N];
int main()
{
	inv[1]=fac[0]=ifac[0]=1;
	for ( int i=2; i<N; i++ ) inv[i]=1LL*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for ( int i=1; i<N; i++ ) fac[i]=1LL*fac[i-1]*i%MOD;
	for ( int i=1; i<N; i++ ) ifac[i]=1LL*ifac[i-1]*inv[i]%MOD;
	int n,k,a[N],b[N]={},c[N];
	scanf("%d%d",&n,&k);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	c[0]=1; b[1]=a[1];
	for ( int i=1; i<=n; i++ ) c[i]=1LL*c[i-1]*(k+i-1)%MOD;
	for ( int i=2; i<=n; i++ ) for ( int j=1; j<=i; j++ ) b[i]=(b[i]+1LL*a[j]*c[i-j]%MOD*ifac[i-j]%MOD)%MOD;
	for ( int i=1; i<=n; i++ ) printf("%d%c",b[i],i==n?'\n':' ');
	return 0;
}