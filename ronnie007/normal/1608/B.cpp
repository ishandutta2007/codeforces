#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , a , b ;
int ans[ MAXN ] ;


void input ( ) {
    cin >> n >> a >> b ;
}

void solve ( ) {
    if ( a + b > n - 2 ) {
        cout << "-1\n" ;
        return ;
    }
    if ( max ( a , b ) - min ( a , b ) > 1 ) {
        cout << "-1\n" ;
        return ;
    }
    int turn = 1 ;
    int l , r ;
    l = 1 , r = n ;
    if ( a >= b ) {
        ans[ 1 ] = 1 ;
        turn = 1 ;
        l = 2 , r = n ;
    }
    else {
        ans[ 1 ] = n ;
        turn = 2 ;
        l = 1 , r = n - 1 ;
    }
    int lst = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a + b == 0 ) { break ; }
        if ( turn == 1 ) {
            -- a ;
            ans[ i ] = r -- ;
        }
        else {
            -- b ;
            ans[ i ] = l ++ ;
        }
        turn = 3 - turn ;
        lst = i ;
    }
    if ( turn == 1 ) {
        for ( int i = lst + 1 ; i <= n ; ++ i ) {
            ans[ i ] = l ++ ; 
        }
    }
    else {
        for ( int i = lst + 1 ; i <= n ; ++ i ) {
            ans[ i ] = r -- ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}