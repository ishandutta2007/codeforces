// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef unsigned long long LL;
int main()
{
	LL n,m;
	cin>>n>>m;
	LL ans=n;
	for ( LL i=10; i<=n; i*=10 ) {
		LL d=n%i+1;
		if ( d==i ) ans=n;
		else if ( d<=m ) ans=n-d;
	}
	cout<<ans<<endl;
	return 0;
}