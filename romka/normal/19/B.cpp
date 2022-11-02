#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

const ll inf = 1LL << 62;

int n, t[2010], c[2010];
ll f[2010][5010];

int main()
{
	scanf( "%d", &n );
	forn( i,n )
		scanf( "%d %d", &t[i], &c[i] );
	
	forn( i,n+2 )
		forn( j,2*n+6 )
			f[i][j] = inf;
			
	f[0][n+3] = 0;
	
	forn( i,n )
		forn( j,2*n+6 ) if ( f[i][j] < inf )
		{
			int z = min( 2*n+5, j+t[i] );
			f[i+1][z] = min( f[i+1][z], f[i][j] + c[i] );
			f[i+1][j-1] = min( f[i+1][j-1], f[i][j] );
		}
		
	ll ans = inf;
	for ( int j=n+3; j<2*n+6; j++ )
		if ( f[n][j] < ans )
			ans = f[n][j];
			
	cout << ans << endl;
}