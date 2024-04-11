// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int s[100],n;
long long dp[100][10];
long long go( int p, int d ) {
	if ( p==n ) return 1;
	if ( dp[p][d]!=-1 ) return dp[p][d];
	if ( (s[p]+d)%2==0 ) return dp[p][d]=go(p+1,(s[p]+d)/2);
	return dp[p][d]=go(p+1,(s[p]+d)/2)+go(p+1,(s[p]+d+1)/2);
}
bool chk() {
	for ( int i=1; i<n; i++ ) if ( (s[i]+s[i-1])/2!=s[i] && (s[i]+s[i-1]+1)/2!=s[i] ) return 0;
	return 1;
}
int main()
{
	while ( ~scanf("%1d",s+n) ) n++;
	memset(dp,-1,sizeof(dp));
	long long ans=0;
	for ( int i=0; i<10; i++ ) ans+=go(1,i);
	if ( chk() ) ans--;
	cout<<ans<<endl;
	return 0;
}