#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

void print_ans ( ) {
    cout << "! " ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << a[ i ] << " " ;
    }
    cout << "\n" ;
    fflush ( stdout ) ;
    exit ( 0 ) ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    for ( int diff = 1 ; diff < n ; ++ diff ) {
        cout << "? " ;
        for ( int i = 1 ; i < n ; ++ i ) {
            cout << "1 " ;
        }
        cout << diff + 1 << "\n" ;
        fflush ( stdout ) ;
        int ret ;
        cin >> ret ;
        if ( ret > 0 ) {
            a[ ret ] = diff ;
        }
        else {
            a[ n ] = n - diff + 1 ;
            for ( int j = 1 ; j < n ; ++ j ) {
                if ( a[ j ] > 0 ) {
                    a[ j ] += a[ n ] ;
                }
            }
            break ;
        }
    }
    if ( a[ n ] == 0 ) {
        a[ n ] = 1 ;
        for ( int j = 1 ; j < n ; ++ j ) {
            ++ a[ j ] ;
        }
        print_ans ( ) ;
    }
    for ( int diff = 1 ; diff < a[ n ] ; ++ diff ) {
        cout << "? " ;
        for ( int i = 1 ; i < n ; ++ i ) {
            cout << diff + 1 << " " ;
        }
        cout << "1\n" ;
        fflush ( stdout ) ;
        int ret ;
        cin >> ret ;
        a[ ret ] = a[ n ] - diff ;
    }
    print_ans ( ) ;
}

int main ( ) {
    /// ios_base :: sync_with_stdio ( false ) ;
    /// cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}