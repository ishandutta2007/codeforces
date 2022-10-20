#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , q , len ;
long long a[ MAXN ] ;

int ans ;
bool fl[ MAXN ] ;

void add ( int pos ) {
    if ( a[ pos ] <= len ) { return ; }
    if ( fl[ pos ] == true ) { return ; }
    fl[ pos ] = true ;
    ++ ans ;
    if ( a[ pos - 1 ] > len ) { -- ans ; }
    if ( a[ pos + 1 ] > len ) { -- ans ; }
}

void input ( ) {
    cin >> n >> q >> len ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        add ( i ) ;
    }
}

void solve ( ) {
    while ( q -- ) {
        int type , x , y ;
        cin >> type ;
        if ( type == 0 ) {
            cout << ans << "\n" ;
        }
        else {
            cin >> x >> y ;
            a[ x ] += y ;
            add ( x ) ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}