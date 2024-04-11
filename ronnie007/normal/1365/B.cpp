#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int cnt ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
        cnt += b[ i ] ;
    }
}

void solve ( ) {
    if ( cnt != 0 && cnt != n ) { printf ( "Yes\n" ) ; return ; }
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] < a[ i - 1 ] ) { printf ( "No\n" ) ; return ; }
    }
    printf ( "Yes\n" ) ;
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