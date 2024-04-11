#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

map < pair < pair < int , int > , pair < int , int > > , bool > w ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int x , y ;
    x = y = 0 ;
    int ans = 0 ;
    w.clear ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int prv1 , prv2 ;
        prv1 = x ; prv2 = y ;
        if ( a[ i ] == 'N' ) { ++ x ; }
        else if ( a[ i ] == 'S' ) { -- x ; }
        else if ( a[ i ] == 'E' ) { ++ y ; }
        else { -- y ; }

        if ( w.find ( { { prv1 , prv2 } , { x , y } } ) == w.end ( ) ) { ans += 5 ; }
        else { ++ ans ; }
        w[ { { prv1 , prv2 } , { x , y } } ] = true ;
        w[ { { x , y } , { prv1 , prv2 } } ] = true ;
    }
    cout << ans << "\n" ;
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