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
#define for1( i,n ) for ( int i=1; i<=(int)(n); i++ )
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

int n;
ll j;
int xs, ys, px[100010], py[100010];

ll solve( int x0, int* px )
{
	ll C = 0;
	for1( i,n ) if ( i&1 ) C += px[i]; else C -= px[i];
	C *= 2;
	ll r = j / n;
	if ( r&1 ) x0 = C - x0;
	ll rest = j % n;
	ll res = x0;
	int i = 1;
	while ( rest-- )
	{
		res = 2*px[i] - res;
		i++;
	}
	
	return res;
}

int main()
{
	cin >> n >> j;
	scanf( "%d %d", &xs, &ys );
	for1( i,n ) scanf( "%d %d", &px[i], &py[i] );
	ll xa = solve( xs, px );
	ll ya = solve( ys, py );
	
	cout << xa << " " << ya << endl;
}