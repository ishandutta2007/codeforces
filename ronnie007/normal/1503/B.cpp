#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n ;

vector < pair < int , int > > even , odd ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( ( i + j ) % 2 ) == 0 ) {
                even.push_back ( { i , j } ) ;
            }
            else {
                odd.push_back ( { i , j } ) ;
            }
        }
    }
}

void solve ( ) {
    int pos1 , pos2 ;
    int sz1 , sz2 ;
    sz1 = even.size ( ) ;
    sz2 = odd.size ( ) ;
    pos1 = pos2 = 0 ;
    int tot = 0 ;
    while ( pos1 < sz1 && pos2 < sz2 ) {
        ++ tot ;
        int ban ;
        cin >> ban ;
        if ( ban != 1 ) {
            cout << "1 " << even[ pos1 ].first << " " << even[ pos1 ].second << "\n" ;
            fflush ( stdout ) ;
            ++ pos1 ;
        }
        else {
            cout << "2 " << odd[ pos2 ].first << " " << odd[ pos2 ].second << "\n" ;
            fflush ( stdout ) ;
            ++ pos2 ;
        }
    }
    int lim = n * n ; 
    if ( pos1 < sz1 ) {
        while ( tot < lim ) {
            ++ tot ;
            int ban ; cin >> ban ;
            int dig = 1 ;
            if ( ban == 1 ) { dig = 3 ; }
            cout << dig << " " << even[ pos1 ].first << " " << even[ pos1 ].second << "\n" ;
            fflush ( stdout ) ;
            ++ pos1 ;
        }
    }
    else {
        while ( tot < lim ) {
            ++ tot ;
            int ban ; cin >> ban ;
            int dig = 2 ;
            if ( ban == 2 ) { dig = 3 ; }
            cout << dig << " " << odd[ pos2 ].first << " " << odd[ pos2 ].second << "\n" ;
            fflush ( stdout ) ;
            ++ pos2 ;
        }        
    }
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}