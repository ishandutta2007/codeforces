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
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxn = 100010;
const int p = 999991;

ull pp[maxn], hash[maxn];
int n, a[maxn], rv[maxn];
pii ev[maxn];
int next[maxn], ls[maxn];

inline ull gethash( int i, int len )
{
	ull z = hash[i+len-1];
	if ( i > 0 ) z -= hash[i-1] * pp[len];
	//cout << "hash " << i << ", len = " << len << " is " << z << endl;
	return z;
}

int main()
{
	scanf( "%d", &n );
	forn( i,n )
	{
		scanf( "%d", &a[i] );
		ev[i] = pii( a[i], i );
	}
	
	sort( ev, ev+n );
	
	int last = -1;
	int cnt = 0;
	forn( i,n )
	{
		if ( ev[i].first != last ) 
		{
			cnt++;
			rv[cnt] = ev[i].first;
			last = ev[i].first;
		}
		a[ ev[i].second ] = cnt;
	}
	
	pp[0] = 1;
	for ( int i=1; i<=n; i++ ) pp[i] = pp[i-1] * p;
	hash[0] = a[0];
	for ( int i=1; i<n; i++ ) hash[i] = hash[i-1] * p + a[i];
	
	//forn( i,n ) printf( "%d ", a[i] ); printf( "\n" );
	
	for ( int i=1; i<=cnt; i++ ) ls[i] = n;
	for ( int i=n-1; i>=0; i-- )
	{
		next[i] = ls[ a[i] ];
		ls[ a[i] ] = i;
	}
	
	vector<pii> rep;
	forn( i,n )
		if ( next[i] != n )
		{
			int len = next[i] - i;
//			printf( "->%d %d\n", i, len );
			if ( next[i] + len <= n )
				if ( gethash( i, len ) == gethash( next[i], len ) )
					rep.pb( pii( len, i ) );
		}
		
	sort( rep.begin(), rep.end() );
	
	int is = 0;
	forn( i, rep.size() )
		if ( rep[i].second >= is )
			is = rep[i].second + rep[i].first;
			
	printf( "%d\n", n-is );
	for ( int i=is; i<n-1; i++ ) printf( "%d ", rv[ a[i] ] );
	printf( "%d\n", rv[ a[n-1] ] );
}