#include<bits/stdc++.h>
using namespace std ;

int n ;


void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    if ( n % 2 == 0 ) { printf ( "%d\n" , ( n / 2 ) - 1 ) ; }
    else { printf ( "%d\n" , ( n / 2 ) ) ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}