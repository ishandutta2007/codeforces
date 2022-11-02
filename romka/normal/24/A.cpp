#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <string>
#include <iostream>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

const int maxn = 110;

int n, x, y, z;
vector<int> g[maxn];
int w[maxn][maxn], is[maxn][maxn];
int a[maxn];

int main()
{
	scanf( "%d", &n );
	forn( i,n )
	{
		scanf( "%d %d %d", &x, &y, &z );
		g[x].pb( y );
		g[y].pb( x );
		w[x][y] = w[y][x] = z;
		is[x][y] = 1;
	}
	
	int ci = 1, p = -1;
	forn( q,n )
	{
		a[q] = ci;
		forn( j, g[ci].size() )
			if ( g[ci][j] != p )
			{
				p = ci;
				ci = g[ci][j];
				break;
			}
	}
	
	a[n] = ci;
	
	int ans = 0;
	forn( q,n )
	{
		int x = a[q];
		int y = a[q+1];
		if ( !is[x][y] ) ans += w[x][y];
	}
	
	int best = ans;
	ans = 0;
	reverse( a, a+n+1 );
	forn( q,n )
	{
		int x = a[q];
		int y = a[q+1];
		if ( !is[x][y] ) ans += w[x][y];
	}
	
	if ( ans < best ) best = ans;
	
	printf( "%d\n", best );
}