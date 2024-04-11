#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    sort ( a + 1 , a + n + 1 ) ;
    if ( a[ 1 ] == a[ n / 2 + 1 ] ) {
        printf ( "Bob\n" ) ;
    }
    else {
        printf ( "Alice\n" ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}