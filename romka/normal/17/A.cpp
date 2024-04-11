#include <cstdio>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
typedef long long ll;
typedef pair<int,int> pii;

int n, k, u[10010], c;
int prime[1010];

int main()
{
	scanf( "%d %d", &n, &k );
	vector<int> pp;
	for ( int i=2; i<=n; i++ )
		if ( !u[i] )
		{			
			for ( int j=i*i; j<=n; j+=i )
				u[j] = 1;
			pp.push_back( i );
			prime[i] = 1;
		}
		
	forn( i, pp.size()-1 )
		u[ pp[i]+pp[i+1]+1 ] = 2;
			
	c = 0;
	for ( int i=2; i<=n; i++ )
		if ( u[i] == 2 && prime[i] ) c++;
		
	if ( c >= k ) printf( "YES\n" );
	else printf( "NO\n" );
}