// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL get( LL x ) {
	LL y=9;
	while ( y<x ) y=y*10+9;
	return x*(y-x);
}
int main()
{
	LL ans=0;
	int l,r;
	cin>>l>>r;
	for ( LL i=5; i<=r; i*=10 ) {
		if ( l<=i && i<=r ) ans=max(ans,get(i));
		if ( l<=i-1 && i-1<=r ) ans=max(ans,get(i-1));
	}
	ans=max(ans,get(l));
	ans=max(ans,get(r));
	cout<<ans<<endl;
	return 0;
}