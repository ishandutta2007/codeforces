#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 1000007

int n ;
int a[ MAXN ] ;

int dp[ MAXN ][ 2 ][ 2 ] ;
pair < int , int > prv[ MAXN ][ 2 ][ 2 ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                dp[ i ][ j ][ t ] = MAXN ;
                prv[ i ][ j ][ t ] = { -1 , -1 } ;
            }
        }
    }
    dp[ 1 ][ 0 ][ 0 ] = dp[ 1 ][ 0 ][ 1 ] = -MAXN ;
    for ( int i = 1 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                if ( dp[ i ][ j ][ t ] == MAXN ) { continue ; }
                int x , y ;
                if ( j == 0 ) {
                    y = dp[ i ][ j ][ t ] ;
                    if ( t == 0 ) { x = -a[ i ] ; }
                    else { x = a[ i ] ; }
                }
                else {
                    x = dp[ i ][ j ][ t ] ;
                    if ( t == 0 ) { y = -a[ i ] ; }
                    else { y = a[ i ] ; }
                }
                for ( int nw = 0 ; nw < 2 ; ++ nw ) {
                    int val = a[ i + 1 ] ;
                    if ( nw == 0 ) { val = -a[ i + 1 ] ; }

                    if ( val > x ) {
                        if ( dp[ i + 1 ][ 0 ][ nw ] > y ) {
                            dp[ i + 1 ][ 0 ][ nw ] = y ;
                            prv[ i + 1 ][ 0 ][ nw ] = { j , t } ;
                        }
                    }
                    else if ( val > y ) {
                        if ( dp[ i + 1 ][ 1 ][ nw ] > x ) {
                            dp[ i + 1 ][ 1 ][ nw ] = x ;
                            prv[ i + 1 ][ 1 ][ nw ] = { j , t } ;
                        }
                    }
                }
            }
        }
    }
    pair < int , int > act = { -1 , -1 } ;
    for ( int j = 0 ; j < 2 ; ++ j ) {
        for ( int t = 0 ; t < 2 ; ++ t ) {
            if ( dp[ n ][ j ][ t ] != MAXN ) {
                act = { j , t } ;
            }
        }
    }
    if ( act.first == -1 ) {
        cout << "NO\n" ;
        return ;
    }
    cout << "YES\n" ;
    for ( int i = n ; i >= 1 ; -- i ) {
        auto [ hh1 , hh2 ] = act ;
        if ( hh2 == 0 ) { a[ i ] = -a[ i ] ; }
        act = prv[ i ][ hh1 ][ hh2 ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << a[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}