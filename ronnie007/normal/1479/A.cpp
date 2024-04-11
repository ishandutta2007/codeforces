#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

int ask ( int x ) {
    cout << "? " << x << "\n" ;
    fflush ( stdout ) ;
    cin >> a[ x ] ;
    return a[ x ] ;
}

bool ok ( int pos ) {
    if ( a[ pos ] == 0 ) { ask ( pos ) ; }
    if ( a[ pos - 1 ] == 0 ) { ask ( pos - 1 ) ; }
    if ( a[ pos + 1 ] == 0 ) { ask ( pos + 1 ) ; }
    if ( a[ pos ] < a[ pos - 1 ] && a[ pos ] < a[ pos + 1 ] ) { return true ; }
    return false ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    a[ 0 ] = MAXN ;
    a[ n + 1 ] = MAXN ;

    while ( r > l ) {
        mid = ( l + r ) / 2 ;
        ask ( mid ) ; ask ( mid + 1 ) ;
        if ( a[ mid ] < a[ mid + 1 ] ) { r = mid ; }
        else { l = mid + 1 ; }
    }
    cout << "! " << l << "\n" ;
    fflush ( stdout ) ;
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}