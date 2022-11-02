#include <cstdio>
#include <cmath>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstring>
#include <iostream>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
	int tc, n;
	scanf( "%d", &tc );
	forn( it, tc )
	{
		scanf( "%d", &n );
		if ( n < 3 ) printf( "0\n" ); else
		if ( n == 3 ) printf( "1\n" ); else {
		int ans = n-2;
		printf( "%d\n", ans );
	}
	}
}