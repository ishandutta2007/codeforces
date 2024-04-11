// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define M 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL pw( LL a, LL b ) {
	if ( b==0 ) return 1;
	LL t=pw(a,b/2);
	if ( b&1 ) return t*t%M*a%M;
	else return t*t%M;
}
int main()
{
	LL n;
	cin>>n;
	if ( n==0 ) puts("1");
	else cout<<(pw(2,2*n-1)+pw(2,n-1))%M<<endl;
	return 0;
}