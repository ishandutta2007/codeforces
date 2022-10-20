#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 507

int n ;

int ans[ 5 * MAXN ] ;

int x , y ;
pair < int , int > qq[ MAXN ] ;


void input ( ) {
    cin >> n ;
}

void solve ( ) {
    x = 1 ;
    y = 1 ;
    string ret ;
    int pos = 0 ;
    while ( 1 ) {
        qq[ pos ] = make_pair ( x , y ) ;
        int dist = ( n - x ) + ( n - y ) - 1 ;
        if ( dist < ( n - 1 ) ) { break ; }
        if ( y == n ) { ans[ pos ] = 2 ; x ++ ; pos ++ ; continue ; }
        cout << "? " << x << " " << y + 1 << " " << n << " " << n << "\n" ;
        fflush(stdout);
        cin >> ret ;
        if ( ret == "YES" ) { ans[ pos ] = 1 ; y ++ ; pos ++ ; continue ; }
        else { ans[ pos ] = 2 ; x ++ ; pos ++ ; continue ; }
    }
    pair < int , int > enrem1 = make_pair ( x , y ) ;
    qq[ pos ] = make_pair ( x , y ) ;
    x = n ;
    y = n ;
    pos = 2 * ( n - 1 ) - 1 ;
    while ( 1 ) {
        int dist = ( n - x ) + ( n - y ) + 1 ;
        if ( dist >= ( n - 1 ) ) { break ; }
        if ( y == 1 ) { ans[ pos ] = 2 ; x -- ; pos -- ; continue ; }
        cout << "? " << qq[ pos - n + 1 ].first << " " << qq[ pos - n + 1 ].second << " " << x - 1 << " " << y << "\n" ;
        fflush(stdout);
        cin >> ret ;
        if ( ret == "YES" ) { ans[ pos ] = 2 ; x -- ; pos -- ; continue ; }
        else { ans[ pos ] = 1 ; y -- ; pos -- ; continue ; }
    }
    pair < int , int > enrem2 = make_pair ( x , y ) ;
    string aux ;
    aux.clear ( ) ;
    for ( int i = 0 ; i < 2 * ( n - 1 ) ; i ++ ) {
        if ( ans[ i ] == 1 ) { aux += 'R' ; }
        else { aux += 'D' ; }
    }
    if ( enrem1.first == enrem2.first ) { aux[ n - 1 ] = 'R' ; }
    else { aux[ n - 1 ] = 'D' ; }
    cout << "! " << aux << "\n" ;
    fflush(stdout);
}

int main ( ) {
    ///ios_base :: sync_with_stdio ( false ) ;
    ///cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}