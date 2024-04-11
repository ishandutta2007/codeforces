#include<bits/stdc++.h>
using namespace std ;

#define MAXN 503
#define MOD 998244353

int n ;
int a[ 2 * MAXN ][ MAXN ] ;

int cnt[ MAXN ][ MAXN ] ;
bool f[ 2 * MAXN ][ 2 * MAXN ] ;
bool done[ 2 * MAXN ] ;

void rem ( int pos ) {
    done[ pos ] = true ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        -- cnt[ i ][ a[ pos ][ i ] ] ;
    }
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        if ( f[ pos ][ i ] == true && done[ i ] == false ) {
            for ( int j = 1 ; j <= n ; ++ j ) {
                -- cnt[ j ][ a[ i ][ j ] ] ;
            }
            done[ i ] = true ;
        }
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        done[ i ] = false ;
        for ( int j = 1 ; j <= 2 * n ; ++ j ) {
            f[ i ][ j ] = false ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            cnt[ i ][ j ] = 0 ;
        }
    }
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            cin >> a[ i ][ j ] ;
            ++ cnt[ j ][ a[ i ][ j ] ] ;
        }
    }
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        for ( int j = 1 ; j <= 2 * n ; ++ j ) {
            for ( int t = 1 ; t <= n ; ++ t ) {
                if ( a[ i ][ t ] == a[ j ][ t ] ) {
                    f[ i ][ j ] = f[ j ][ i ] = true ;
                    break ;
                }
            }
        }
    }
}


void solve ( ) {
    vector < int > v ;
    long long ans = 1 ;
    for ( int tm = 0 ; tm < n ; ++ tm ) {
        int wh , dig ;
        wh = dig = -1 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 1 ; j <= n ; ++ j ) {
                if ( cnt[ i ][ j ] == 1 ) {
                    wh = i , dig = j ;
                    break ;
                }
            }
            if ( dig > -1 ) { break ; }
        }
        if ( wh > -1 ) {
            int pos = 0 ;
            for ( int i = 1 ; i <= 2 * n ; ++ i ) {
                if ( done[ i ] == true ) { continue ; }
                if ( a[ i ][ wh ] == dig ) {
                    pos = i ;
                    break ;
                }
            }
            v.push_back ( pos ) ;
            rem ( pos ) ;
        }
        else {
            ans = ( ans * 2 ) % MOD ;
            for ( int i = 1 ; i <= 2 * n ; ++ i ) {
                if ( done[ i ] == true ) { continue ; }
                v.push_back ( i ) ;
                rem ( i ) ;
                break ;
            }
        }
    }
    cout << ans << "\n" ;
    for ( auto x : v ) {
        cout << x << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}