#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;
pair < long double , int > a[ MAXN ] ;


void input ( ) {
	cin >> n ;
    int i ;
    long double x , y ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	cin >> x >> y ;
        a[ i ] = make_pair ( atan2 ( y , x ) , i ) ;
        if ( a[ i ].first < 0 ) { a[ i ].first += 2 * M_PI ; }
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int i ;
    long double ans = 1337 ;
    int id1 , id2 ;
	id1 = id2 = -1 ;
    a[ n + 1 ] = a[ 1 ] ;
    a[ n + 1 ].first += 2 * M_PI ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	long double cur = ( a[ i + 1 ].first - a[ i ].first ) ;
        if ( cur < ans ) { ans = cur ; id1 = a[ i ].second ; id2 = a[ i + 1 ].second ; }
    }
    cout << id1 << " " << id2 << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}