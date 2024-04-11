#include<bits/stdc++.h>
using namespace std ;

int n , k ;


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    int st = 1 ;
    int add = 1 ;
    while ( 1 ) {
        printf ( "? %d\n" , st ) ;
        fflush ( stdout ) ;
        long long ret ;
        scanf ( "%lld" , &ret ) ;
        if ( ret == k ) {
            st += add ;
            ++ add ;
            if ( st > n ) { st -= n ; }
            continue ;
        }
        if ( ret < k ) {
            while ( 1 ) {
                ++ st ;
                if ( st > n ) { st = 1 ; }
                printf ( "? %d\n" , st ) ;
                fflush ( stdout ) ;
                scanf ( "%lld" , &ret ) ;
                if ( ret == k ) {
                    printf ( "! %d\n" , st ) ;
                    fflush ( stdout ) ;
                    return ;
                }
            }
        }
        else {
            while ( 1 ) {
                -- st ;
                if ( st < 1 ) { st = n ; }
                printf ( "? %d\n" , st ) ;
                fflush ( stdout ) ;
                scanf ( "%lld" , &ret ) ;
                if ( ret == k ) {
                    printf ( "! %d\n" , st ) ;
                    fflush ( stdout ) ;
                    return ;
                }
            }            
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}