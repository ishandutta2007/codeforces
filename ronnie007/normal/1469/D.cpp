#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

vector < pair < int , int > > v ;

int f ( int x , int y ) {
    int ret = ( x / y ) ;
    if ( ( x % y ) > 0 ) { ++ ret ; }
    return ret ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = i ;
    }
    v.clear ( ) ;
    for ( int i = n - 1 ; i >= 3 ; -- i ) {
        if ( f ( a[ n ] , a[ i ] ) >= a[ i ] ) {
            v.push_back ( { n , i } ) ;
            a[ n ] = f ( a[ n ] , a[ i ] ) ;
        }
        a[ i ] = 1 ;
        v.push_back ( { i , n } ) ;
    }
    while ( a[ n ] > 1 ) {
        v.push_back ( { n , 2 } ) ;
        a[ n ] = f ( a[ n ] , a[ 2 ] ) ;
    }
    int sz = v.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << v[ i ].first << " " << v[ i ].second << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}