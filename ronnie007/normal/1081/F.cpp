#include<bits/stdc++.h>
using namespace std ;

#define MAXN 307

int n ;
vector < int > v ;

int pref[ MAXN ] ;

int get ( int l , int r ) {
    printf ( "? %d %d\n" , l , r ) ; fflush ( stdout ) ;
    int ret ; scanf ( "%d" , &ret ) ;
    int lst = v.back ( ) ;
    v.push_back ( ret ) ;
    if ( ret % 2 == lst % 2 ) {
        if ( r % 2 == 0 ) { return 0 ; }
        return 1 ;
    }
    else {
        if ( r % 2 == 0 ) { return 1 ; }
        return 0 ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    scanf ( "%d" , &pref[ n ] ) ;
    v.push_back ( pref[ n ] ) ;
}

void solve ( ) {
    int stat[ 2 ] ;
    if ( ( n % 2 ) == 0 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            stat[ 0 ] = stat[ 1 ] = 0 ;
            while ( stat[ 0 ] != 1 || stat[ 1 ] != 0 ) {
                int hh = get ( i , i ) ;
                stat[ hh ] ^= 1 ;
            }
            int lst = v.back ( ) ;
            pref[ i ] = ( pref[ n ] + i - lst ) / 2 ;
            while ( stat[ 0 ] != 0 || stat[ 1 ] != 0 ) {
                int hh = get ( i , i ) ;
                stat[ hh ] ^= 1 ;
            }
        }
    }
    else {
        if ( n == 1 ) {
            printf ( "! %d\n" , pref[ n ] ) ;
            fflush ( stdout ) ;
            return ;
        }
        for ( int i = 2 ; i <= n ; ++ i ) {
            stat[ 0 ] = stat[ 1 ] = 0 ;
            while ( stat[ 0 ] != 1 || stat[ 1 ] != 0 ) {
                int hh = get ( i - 1 , i ) ;
                stat[ hh ] ^= 1 ;
            }
            int lst = v.back ( ) ;
            pref[ i ] = ( pref[ n ] + i - lst ) / 2 ;
            while ( stat[ 0 ] != 0 || stat[ 1 ] != 0 ) {
                int hh = get ( i - 1 , i ) ;
                stat[ hh ] ^= 1 ;
            }            
        }
        stat[ 0 ] = stat[ 1 ] = 0 ;
        while ( stat[ 0 ] != 0 || stat[ 1 ] != 1 ) {
            int hh = get ( 2 , n ) ;
            stat[ hh ] ^= 1 ;
        }
        int lst = v.back ( ) ;
        pref[ 1 ] = ( pref[ n ] + lst - n + 1 ) / 2 ;
        while ( stat[ 0 ] != 0 || stat[ 1 ] != 0 ) {
            int hh = get ( 2 , n ) ;
            stat[ hh ] ^= 1 ;
        }                    
    }
    printf ( "! " ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d" , pref[ i ] - pref[ i - 1 ] ) ;
    }
    printf ( "\n" ) ;
    fflush ( stdout ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}