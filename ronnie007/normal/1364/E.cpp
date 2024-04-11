#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2057
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
int ans[ MAXN ] ;
int pos[ MAXN ] ;


int ask ( int x , int y ) {
    cout << "? " << x << " " << y << "\n" ;
    fflush ( stdout ) ;
    int ret ; cin >> ret ;
    return ret ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) { pos[ i ] = i ; }
    random_shuffle ( pos + 1 , pos + n + 1 ) ;
}

void solve ( ) {
    int cand1 = pos[ 1 ] , cand2 = pos[ 2 ] ;
    int sr = ask ( cand1 , cand2 ) ;
    for ( int i = 3 ; i <= n ; ++ i ) {
        int nw = ask ( pos[ i ] , cand2 ) ;
        if ( nw < sr ) {
            cand1 = pos[ i ] ; sr = nw ;
        }
        else if ( nw == sr ) {
            cand2 = pos[ i ] ;
            sr = ask ( cand1 , cand2 ) ;
        }
    }
    int act ;
    while ( 1 ) {
        int id = rng ( ) % n + 1 ;
        if ( id == cand1 || id == cand2 ) { continue ; }
        int ret1 = ask ( cand1 , id ) ;
        int ret2 = ask ( cand2 , id ) ;
        if ( ret1 < ret2 ) { act = cand1 ; break ; }
        if ( ret1 > ret2 ) { act = cand2 ; break ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == act ) { continue ; }
        ans[ i ] = ask ( i , act ) ;
    }
    cout << "!" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << " " << ans[ i ] ; 
    }
    cout << "\n" ;
    fflush ( stdout ) ;
}


int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
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