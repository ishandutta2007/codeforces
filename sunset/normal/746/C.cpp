#include <bits/stdc++.h>

using namespace std;

int x1,x2,t1,t2,s,p,d;

int main()
{
	scanf( "%d%d%d%d%d%d%d", &s, &x1, &x2, &t1, &t2, &p, &d );
	if( t2 <= t1 ) return printf( "%d\n", abs( x1 - x2 ) * t2 ), 0;
	int ans = abs( x1 - x2 ) * t2;
	if( d == 1 )
	{
		if( x1 < x2 )
		{
			if( p <= x1 ) ans = min( ans, ( x2 - p ) * t1 );
			else if( x1 < p && p <= x2 ) ans = min( ans, ( 2 * s + x2 - p ) * t1 );
			else ans = min( ans, ( 2 * s - p + x2 ) * t1 );
		}
		else
			ans = min( ans, ( s - x2 + s - p ) * t1 );	
	}
	else
	{
		if( x1 > x2 )
		{
			if( p >= x1 ) ans = min( ans, ( p - x2 ) * t1 );
			else if( x2 <= p && p < x1 ) ans = min( ans, ( 2 * s + p - x2 ) * t1 );
			else ans = min( ans, ( 2 * s + p - x2 ) * t1 );
		}
		else
			ans = min( ans, ( x2 + p ) * t1 );
	}
	cout << ans << endl;
}