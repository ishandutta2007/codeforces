// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL C( LL n, LL m ) {
	if ( m>n || m<0 ) return 0;
	LL r=1;
	for ( int i=1; i<=m; i++ ) r=r*(n-i+1)/i;
	return r;
}
int main()
{
	LL n,m,t,ans=0;
	cin>>n>>m>>t;
	ans+=C(n+m,t);
	for ( int i=0; i<=3; i++ ) ans-=C(n,i)*C(m,t-i);
	ans-=C(n,t);
	cout<<ans<<endl;
	return 0;
}