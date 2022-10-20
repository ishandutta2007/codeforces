#include<bits/stdc++.h>
using namespace std ;

pair < long long , int > a[ 4 ] ;

void input ( ) {
    for ( int i = 1 ; i <= 3 ; ++ i ) {
        cin >> a[ i ].first ;
        a[ i ].second = i ;
    }
    sort ( a + 1 , a + 4 ) ;
}

void solve ( ) {
    cout << "First\n" ;
    fflush ( stdout ) ;
    while ( 1 ) {
        long long aux = 2 * a[ 3 ].first - a[ 2 ].first - a[ 1 ].first ;
        cout << aux << "\n" ;
        fflush ( stdout ) ;
        int ret ;
        cin >> ret ;
        if ( ret != a[ 3 ].second ) {
            for ( int i = 1 ; i <= 3 ; ++ i ) {
                if ( a[ i ].second == ret ) {
                    a[ i ].first += aux ;
                    break ;
                }
            }
            sort ( a + 1 , a + 4 ) ;
            cout << a[ 2 ].first - a[ 1 ].first << "\n" ;
            fflush ( stdout ) ;
            cin >> ret ;
            return ;
        }
        else {
            a[ 3 ].first += aux ;
        }
    }
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}