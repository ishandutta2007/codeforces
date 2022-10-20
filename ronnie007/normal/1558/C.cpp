#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2027

int n ;
int a[ MAXN ] ;
vector < int > v ;

void rev ( int x ) {
    v.push_back ( x ) ;
    for ( int i = 1 ; i <= ( x / 2 ) ; ++ i ) {
        swap ( a[ i ] , a[ x - i + 1 ] ) ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ( a[ i ] % 2 ) != ( i % 2 ) ) {
            cout << "-1\n" ;
            return ;
        }
    }
    v.clear ( ) ;
    for ( int x = n ; x > 1 ; x -= 2 ) {
        int y = x - 1 ;
        if ( a[ x ] == x && a[ y ] == y ) { continue ; }
        for ( int j = 1 ; j <= x ; ++ j ) {
            if ( a[ j ] == x ) {
                rev ( j ) ;
                break ;
            }
        }
        for ( int j = 1 ; j < x ; ++ j ) {
            if ( a[ j + 1 ] == y ) {
                rev ( j ) ;
                rev ( j + 2 ) ;
                break ;
            }
        }
        rev ( 3 ) ;
        rev ( x ) ;
    }
    int sz = v.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << v[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}