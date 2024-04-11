// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200010
#define M 1000000007
using namespace std;
typedef long long LL;
LL fac[N]={1},inv[N]={1};
LL pow_mod( int a, int b ) {
	if ( b==0 ) return 1;
	LL t=pow_mod(a,b/2);
	if ( b&1 ) return t*t%M*a%M;
	else return t*t%M;	
}
void pre_cal() {
	for ( int i=1; i<N; i++ ) fac[i]=fac[i-1]*i%M;
	for ( int i=1; i<N; i++ ) inv[i]=pow_mod(fac[i],M-2);
}
LL C( int n, int m ) { return fac[n]*inv[m]%M*inv[n-m]%M; }
int main()
{
	pre_cal();
	int n;
	scanf("%d",&n);
	printf("%I64d\n",((C(2*n-1,n)*2-n)%M+M)%M);
	return 0;
}