#include<bits/stdc++.h>
using namespace std ;

#define MAXN 4007

int n ;
int a[ MAXN ] ;
vector < int > v ;
bool f[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int pos = 1 ;
    v.clear ( ) ;
    for ( int i = 0 ; i <= 2 * n ; ++ i ) {
        f[ i ] = false ;
    }
    while ( pos <= 2 * n ) {
        for ( int i = pos + 1 ; i <= 2 * n + 1 ; ++ i ) {
            if ( a[ i ] > a[ pos ] || i == 2 * n + 1 ) {
                v.push_back ( i - pos ) ;
                pos = i ;
                break ;
            }
        }
    }
    int sz = v.size ( ) ;
    f[ 0 ] = true ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        for ( int j = n - v[ i ] ; j >= 0 ; -- j ) {
            if ( f[ j ] == true ) {
                f[ j + v[ i ] ] = true ;
            }
        }
    }
    if ( f[ n ] == true ) { cout << "YES\n" ; }
    else { cout << "NO\n" ; }
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