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

const int inf = 100000010;

int n, m, x, y, z, g[1010][1010], a[1010];
pii ev[1010];

int main()
{
	scanf( "%d", &n );
	forn( i,n ) scanf( "%d", &a[i] );
	
	forn( i,n )
		forn( j,n )
			g[i][j] = inf;
	
	scanf( "%d", &m );
	forn( i,m )
	{
		scanf( "%d %d %d", &x, &y, &z );
		x--, y--;
		g[x][y] = min( g[x][y], z );
	}
	
	forn( i,n ) ev[i] = pii( a[i], i );
	sort( ev, ev+n );
	
	int ans = 0;
	for ( int i=n-2; i>=0; i-- )
	{
		int x = ev[i].second;
		int cur = inf;
		forn( j,n )
			if ( g[j][x] < cur ) cur = g[j][x];
		if ( cur == inf )
		{
			ans = -1;
			break;
		}
		ans += cur;
	}
	
	printf( "%d\n", ans );
}