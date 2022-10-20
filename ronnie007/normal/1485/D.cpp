#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int magic = 720720 ;
int ans[ 17 ] ;

int n , m ;
int a[ 507 ][ 507 ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    /**
    for ( int i = 1 ; i <= 16 ; ++ i ) {
        for ( int coef = 1 ; coef * i <= 1000000 ; ++ coef ) {
            int lft = abs ( magic - coef * i ) ;
            bool fl = false ;
            for ( int t = 1 ; t <= 35 ; ++ t ) {
                if ( t * t * t * t == lft ) {
                    printf ( "val = %d, coef = %d, tot = %d ---> %d\n" , i , coef , i * coef , t ) ;
                    fl = true ;
                }
            }
            if ( fl == true ) { break ; }
        }
    }
    **/
    ans[ 1 ] = 13439 ;
    ans[ 2 ] = 106064 ;
    ans[ 3 ] = 189279 ;
    ans[ 4 ] = 106064 ;
    ans[ 5 ] = 330095 ;
    ans[ 6 ] = 388944 ;
    ans[ 7 ] = 106064 ;
    ans[ 8 ] = 106064 ;
    ans[ 9 ] = 189279 ;
    ans[ 10 ] = 560720 ;
    ans[ 11 ] = 486464 ;
    ans[ 12 ] = 388944 ;
    ans[ 13 ] = 263744 ;
    ans[ 14 ] = 106064 ;
    ans[ 15 ] = 670095 ;
    ans[ 16 ] = 106064 ;

    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( ( ( i + j ) % 2 ) == 0 ) { cout << magic << " " ; }
            else { cout << ans[ a[ i ][ j ] ] << " " ; }
        }
        cout << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}