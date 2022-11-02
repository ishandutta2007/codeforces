// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
map<LL,bool> dp;
bool go( LL n ) {
	if ( dp.count(n) ) return dp[n];
	bool f=1;
	for ( LL i=2; i*i<=n; i++ ) if ( n%i==0 ) {
		f=0;
		if ( !go(i) || !go(n/i) ) return dp[n]=1;
	}
	return dp[n]=f;
}
int main()
{
	LL n;
	scanf("%I64d",&n);
	if ( go(n) ) {
		puts("1");
		for ( LL i=2; i*i<=n; i++ ) if ( n%i==0 ) {
			if ( !go(i) ) { printf("%I64d\n",i); return 0; }
			if ( !go(n/i) ) { printf("%I64d\n",n/i); return 0; }
		}
		puts("0");
	} else puts("2");
	return 0;
}