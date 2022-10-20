#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n , k ;
int a[ MAXN ] ;

int cnt[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        cnt[ a[ i ] ] = 1 ;
    }
}

void solve ( ) {
    int diff = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        diff += cnt[ i ] ;
    }
    if ( diff > k ) {
        printf ( "-1\n" ) ;
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( cnt[ i ] == 0 && diff < k ) {
            cnt[ i ] = 1 ;
            ++ diff ;
        }
    }
    printf ( "%d\n" , n * k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( cnt[ j ] == 0 ) { continue ; }
            printf ( "%d " , j ) ;
        }
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}