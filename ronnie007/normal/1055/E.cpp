#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1507

int n , m , k , sr ;
int a[ MAXN ] ;
int pref[ MAXN ] ;
pair < int , int > hh[ MAXN ] ;
int mx[ MAXN ] ;

int dp[ 2 ][ MAXN ] ;

bool f ( int x ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] + ( a[ i ] <= x ) ) ;
    }
    int prv = 0 ;
    int nxt = 1 ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j <= n ; ++ j ) {
            dp[ i ][ j ] = 0 ;
        }
    }
    for ( int j = 1 ; j <= k ; ++ j ) {
        int w = dp[ prv ][ 0 ] ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( mx[ i ] > 0 ) {
                int aux = w + ( pref[ mx[ i ] ] - pref[ i - 1 ] ) ;
                dp[ nxt ][ mx[ i ] ] = max ( dp[ nxt ][ mx[ i ] ] , aux ) ;
                if ( dp[ nxt ][ mx[ i ] ] >= sr ) { return true ; }
            }
            w = max ( w , dp[ prv ][ i ] ) ; 
        }
        for ( int i = 0 ; i <= n ; ++ i ) {
            dp[ prv ][ i ] = 0 ;
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    return false ;
}

void input ( ) {
    cin >> n >> m >> k >> sr ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> hh[ i ].first >> hh[ i ].second ;
        for ( int j = hh[ i ].first ; j <= hh[ i ].second ; ++ j ) {
            mx[ j ] = max ( mx[ j ] , hh[ i ].second ) ;
        }
    }
}

void solve ( ) {
    int l , r , mid ;
    l = 1 ;
    r = 1e9 ;
    if ( f ( r ) == false ) {
        cout << "-1\n" ;
        return ;
    }
    while ( r - l > 3 ) {
        int mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { ++ l ; }
    cout << l << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}