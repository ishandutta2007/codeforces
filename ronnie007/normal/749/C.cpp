#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int i ;
    queue < int > p , q ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == 'D' ) { p.push ( i ) ; }
        else { q.push ( i ) ; }
    }
    while ( p.empty ( ) == false && q.empty ( ) == false ) {
        int x = p.front ( ) ;
        p.pop ( ) ;
        int y = q.front ( ) ;
        q.pop ( ) ;
        if ( x < y ) { p.push ( n + x ) ; }
        else { q.push ( n + y ) ; }
    }
    if ( p.empty ( ) == false ) { printf ( "D\n" ) ; }
    else { printf ( "R\n" ) ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}