#include<bits/stdc++.h>
using namespace std ;

#define MAXN 102 

int n ;
string s ;
int a[ MAXN ] ;

long long dp[ MAXN ][ MAXN ][ MAXN ] ;


void f ( int l , int r , int cnt ) {
    if ( l > r ) { return ; }
    if ( dp[ l ][ r ][ cnt ] > 0 ) { return ; }
    f ( l + 1 , r , 1 ) ;
    dp[ l ][ r ][ cnt ] = dp[ l + 1 ][ r ][ 1 ] + a[ cnt ] ;
    for ( int i = l + 1 ; i <= r ; ++ i ) {
        if ( s[ i - 1 ] == s[ l - 1 ] ) {
            f ( l + 1 , i - 1 , 1 ) ;
            f ( i , r , cnt + 1 ) ;
            long long aux = dp[ l + 1 ][ i - 1 ][ 1 ] + dp[ i ][ r ][ cnt + 1 ] ;
            dp[ l ][ r ][ cnt ] = max ( dp[ l ][ r ][ cnt ] , aux ) ;
        }
    }
}

void input ( ) {
    cin >> n ;
    cin >> s ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    f ( 1 , n , 1 ) ;
    cout << dp[ 1 ][ n ][ 1 ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}