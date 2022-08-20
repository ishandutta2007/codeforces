#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill( x, y ) memset( x, y, sizeof x )
#define copy( x, y ) memcpy( x, y, sizeof x )
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) f = -1; ch = getchar(); }
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	int a = read(), b = read(), c = read(), n = read(), ret = 0;
	while( n-- ) { int x = read(); if( x > b && x < c ) ret++; }
	cout << ret << endl;
}