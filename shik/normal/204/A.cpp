// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
bool chk( LL x ) {
	LL y=x%10;
	while ( x>=10 ) x/=10;
	return x==y;
}
int main()
{
	LL l,r,ans=0;
	cin>>l>>r;
	if ( r-l<=1000 ) {
		for ( LL i=l; i<=r; i++ ) if ( chk(i) ) ans++;
		cout<<ans<<endl;
		return 0;
	}
	while ( l%10!=0 ) {
		if ( chk(l) ) ans++;
		l++;
	}
	while ( r%10!=0 ) {
		if ( chk(r) ) ans++;
		r--;
	}
	ans+=(r-l)/10;
	cout<<ans<<endl;
	return 0;
}