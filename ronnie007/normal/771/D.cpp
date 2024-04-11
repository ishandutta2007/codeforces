#include<bits/stdc++.h>
using namespace std ;

#define MAXN 77
#define inf 1000000007

int n ;
string a ;
int tot[ 3 ] ;
vector < int > v[ 3 ] ;

int dp[ MAXN ][ MAXN ][ MAXN ][ 3 ] ;

int cnt_before[ MAXN ][ 3 ] ;

int f ( int i , int j , int t , int sr ) {
    int ret = sr ;
    ret -= min ( cnt_before[ sr ][ 0 ] , i ) ;
    ret -= min ( cnt_before[ sr ][ 1 ] , j ) ;
    ret -= min ( cnt_before[ sr ][ 2 ] , t ) ;
    return ret ;
}

void input ( ) {
    cin >> n ;
    cin >> a ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == 'V' ) { a[ i ] = 'a' ; }
        else if ( a[ i ] == 'K' ) { a[ i ] = 'b' ; }
        else { a[ i ] = 'c' ; }
        ++ tot[ ( a[ i ] - 'a' ) ] ;
        v[ ( a[ i ] - 'a' ) ].push_back ( i ) ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < i ; ++ j ) {
            ++ cnt_before[ i ][ ( a[ j ] - 'a' ) ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= n ; ++ j ) {
            for ( int t = 0 ; t <= n ; ++ t ) {
                for ( int z = 0 ; z < 3 ; ++ z ) {
                    dp[ i ][ j ][ t ][ z ] = inf ;
                }
            }
        }
    }
    dp[ 0 ][ 0 ][ 0 ][ 2 ] = 0 ;
    for ( int i = 0 ; i <= tot[ 0 ] ; ++ i ) {
        for ( int j = 0 ; j <= tot[ 1 ] ; ++ j ) {
            for ( int t = 0 ; t <= tot[ 2 ] ; ++ t ) {
                for ( int z = 0 ; z < 3 ; ++ z ) {
                    if ( dp[ i ][ j ][ t ][ z ] == inf ) { continue ; }
                    if ( i < tot[ 0 ] ) {
                        dp[ i + 1 ][ j ][ t ][ 0 ] = min ( dp[ i + 1 ][ j ][ t ][ 0 ] , dp[ i ][ j ][ t ][ z ] + f ( i , j , t , v[ 0 ][ i ] ) ) ;
                    }
                    if ( j < tot[ 1 ] && z != 0 ) {
                        dp[ i ][ j + 1 ][ t ][ 1 ] = min ( dp[ i ][ j + 1 ][ t ][ 1 ] , dp[ i ][ j ][ t ][ z ] + f ( i , j , t , v[ 1 ][ j ] ) ) ;
                    }
                    if ( t < tot[ 2 ] ) {
                        dp[ i ][ j ][ t + 1 ][ 2 ] = min ( dp[ i ][ j ][ t + 1 ][ 2 ] , dp[ i ][ j ][ t ][ z ] + f ( i , j , t , v[ 2 ][ t ] ) ) ;
                    }
                }
            }
        }
    }
    int ans = inf ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        ans = min ( ans , dp[ tot[ 0 ] ][ tot[ 1 ] ][ tot[ 2 ] ][ i ] ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}