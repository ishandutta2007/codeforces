#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

priority_queue < pair < int , int > > q1 ;
priority_queue < pair < int , int > > q2 ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ; 
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    while ( q1.empty ( ) == false ) { q1.pop ( ) ; }
    while ( q2.empty ( ) == false ) { q2.pop ( ) ; }
    if ( ( n % 2 ) == 1 ) {
        int sr = ( n / 2 ) + ( n % 2 ) ;
        if ( a[ sr ] != b[ sr ] ) {
            cout << "No\n" ;
            return ;
        }
    }
    for ( int i = 1 ; i <= ( n / 2 ) ; ++ i ) {
        pair < int , int > p1 = { a[ i ] , a[ n - i + 1 ] } ;
        if ( p1.first > p1.second ) { swap ( p1.first , p1.second ) ; }
        
        pair < int , int > p2 = { b[ i ] , b[ n - i + 1 ] } ;
        if ( p2.first > p2.second ) { swap ( p2.first , p2.second ) ; }
        q1.push ( p1 ) ;
        q2.push ( p2 ) ;
    }
    while ( q1.empty ( ) == false ) {
        pair < int , int > p1 = q1.top ( ) ;
        q1.pop ( ) ;
        pair < int , int > p2 = q2.top ( ) ;
        q2.pop ( ) ;
        if ( p1 != p2 ) { cout << "No\n" ; return ; }
    }
    cout << "Yes\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}