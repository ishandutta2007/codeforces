#include<bits/stdc++.h>
using namespace std ;

#define MAXN 3007

int n , k ;
int len[ MAXN ] ;
vector < int > v[ MAXN ] ;
vector < long long > pref[ MAXN ] ;

long long dp[ MAXN ] ;
long long hist[ MAXN ][ MAXN ] ;
int tpsz ;

long long ans = 0 ;

void undo ( ) {
    -- tpsz ;
    for ( int i = 0 ; i <= k ; ++ i ) {
        dp[ i ] = hist[ tpsz ][ i ] ;
    }
}

void add ( long long x , int w ) {
    for ( int i = 0 ; i <= k ; ++ i ) {
        hist[ tpsz ][ i ] = dp[ i ] ;
    }
    ++ tpsz ;

    for ( int i = k - w ; i >= 0 ; -- i ) {
        dp[ i + w ] = max ( dp[ i + w ] , dp[ i ] + x ) ;
    }
}

void f ( int l , int r ) {
    if ( l == r ) {
        for ( int i = 0 ; i <= len[ l ] ; ++ i ) {
            if ( i > k ) { break ; }
            ans = max ( ans , pref[ l ][ i ] + dp[ k - i ] ) ;
        }
        return ;
    }
    else {
        int mid = ( l + r ) / 2 ;
        for ( int i = mid + 1 ; i <= r ; ++ i ) {
            add ( pref[ i ].back ( ) , len[ i ] ) ;
        }
        f ( l , mid ) ;
        for ( int i = mid + 1 ; i <= r ; ++ i ) { undo ( ) ; }

        for ( int i = l ; i <= mid ; ++ i ) {
            add ( pref[ i ].back ( ) , len[ i ] ) ;
        }
        f ( mid + 1 , r ) ;
        for ( int i = l ; i <= mid ; ++ i ) { undo ( ) ; }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &len[ i ] ) ;
        v[ i ].resize ( len[ i ] ) ;
        pref[ i ].resize ( len[ i ] + 1 ) ;
        pref[ i ][ 0 ] = 0 ;
        for ( int j = 0 ; j < len[ i ] ; ++ j ) {
            scanf ( "%d" , &v[ i ][ j ] ) ;
            pref[ i ][ j + 1 ] = pref[ i ][ j ] + v[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    f ( 1 , n ) ;
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}