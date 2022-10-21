#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
bool used[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    int ans = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans ^= b[ i ] ;
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            int x = i ;
            ++ cnt ;
            while ( 1 ) {
                if ( used[ x ] == true ) { break ; }
                used[ x ] = true ;
                x = a[ x ] ;
            }
        }
    }
    if ( cnt > 1 ) { ans += cnt ; }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}