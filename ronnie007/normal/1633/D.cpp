#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , k ;
int a[ MAXN ] , b[ MAXN ] , c[ MAXN ] ;
int cost[ MAXN ] ;
int dp[ 2 ][ 12 * MAXN ] ;


void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> c[ i ] ;
    }
}

void solve ( ) {
    if ( k > 12 * n ) { k = 12 * n ; } 
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j <= k ; ++ j ) {
            dp[ i ][ j ] = 0 ; 
        }
    }
    int prv = 0 , nxt = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= k ; ++ j ) {
            if ( j + cost[ b[ i ] ] <= k ) {
                dp[ nxt ][ j + cost[ b[ i ] ] ] = max ( dp[ nxt ][ j + cost[ b[ i ] ] ] , dp[ prv ][ j ] + c[ i ] ) ;
            }
        }
        for ( int j = 0 ; j <= k ; ++ j ) {
            dp[ prv ][ j ] = dp[ nxt ][ j ] ;
        }
        prv ^= 1 , nxt ^= 1 ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i <= k ; ++ i ) {
        ans = max ( ans , dp[ prv ][ i ] ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        cost[ i ] = -1 ;
    }
    cost[ 1 ] = 0 ;
    for ( int i = 1 ; i <= 1000 ; ++ i ) {
        if ( cost[ i ] < 0 ) { continue ; }
        for ( int j = 1 ; j <= i ; ++ j ) {
            if ( cost[ i + ( i / j ) ] < 0 || cost[ i + ( i / j ) ] > cost[ i ] + 1 ) {
                cost[ i + ( i / j ) ] = cost[ i ] + 1 ; 
            }
        }
    }    
	int t ; cin >> t ;
	while ( t -- ) {
		input ( ) ;
		solve ( ) ;
	}
	return 0 ;
}