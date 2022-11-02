// by shik
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#define S 1000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
bool p[S];
long long sol[S];
int sn;
int main()
{
	for ( int i=2; i*i<S; i++ ) if ( !p[i] ) for ( int j=i*i; j<S; j+=i ) p[j]=1;
	for ( int i=2; i<S; i++ ) if ( !p[i] ) sol[sn++]=1LL*i*i;
	int n;
	long long x;
	scanf("%d",&n);
	while ( n-- ) {
		cin>>x;
		puts(*lower_bound(sol,sol+sn,x)==x ? "YES" : "NO");
	}
	return 0;
}