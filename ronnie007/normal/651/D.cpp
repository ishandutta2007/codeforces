#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 500007

int n , a , b , tm ;
string s ;

int pref[ MAXN ] ;
int suff[ MAXN ] ;

void input ( ) {
	cin >> n >> a >> b >> tm ;
    cin >> s ;
    s = '#' + s ;
    pref[ 0 ] = 0 ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	pref[ i ] = pref[ i - 1 ] ;
        if ( i != 1 ) { pref[ i ] += a ; }
        if ( s[ i ] == 'w' ) { pref[ i ] += b ; }
        pref[ i ] ++ ;
    }
    suff[ n ] = a ;
    if ( s[ n ] == 'w' ) { suff[ n ] += b ; }
    suff[ n ] ++ ;
    for ( i = n - 1 ; i >= 1 ; i -- ) {
    	suff[ i ] = suff[ i + 1 ] ;
        suff[ i ] += a ;
        if ( s[ i ] == 'w' ) { suff[ i ] += b ; }
        suff[ i ] ++ ;
    }
}

void solve ( ) {
	int ans = 0 ;
    int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
    	if ( pref[ i ] > tm ) { break ; }
        int l , r , mid ;
        l = i + 1 ;
        r = n ;
        while ( r - l > 3 ) {
        	mid = ( l + r ) / 2 ;
            if ( pref[ i ] + suff[ mid ] + a * min ( ( i - 1 ) , n - mid + 1 ) > tm ) { l = mid ; }
            else { r = mid ; }
        }
        while ( l <= n && pref[ i ] + suff[ l ] + a * min ( ( i - 1 ) , n - l + 1 ) > tm ) { l ++ ; }
        int cur = i + ( n - l + 1 ) ;
        if ( ans < cur ) { ans = cur ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}