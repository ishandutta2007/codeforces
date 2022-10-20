#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

int l , r ;

bool f ( int x ) {
    bool used[ 15 ] ;
    for ( int i = 0 ; i < 10 ; ++ i ) { used[ i ] = false ; }
    while ( x > 0 ) {
        int val = ( x % 10 ) ;
        x /= 10 ;
        if ( used[ val ] == true ) { return false ; }
        used[ val ] = true ;
    }
    return true ;
}

void input ( ) {
    scanf ( "%d%d" , &l , &r ) ;
}

void solve ( ) {
    for ( int i = l ; i <= r ; ++ i ) {
        if ( f ( i ) == true ) { printf ( "%d\n" , i ) ; return ; }
    }
    printf ( "-1\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}