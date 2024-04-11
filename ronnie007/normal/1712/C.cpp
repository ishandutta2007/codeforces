#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 1e5 + 7 ;

int n ;
int a[ MAXN ] ;
int fst[ MAXN ] , lst[ MAXN ] ;

int ch[ MAXN ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fst[ i ] = lst[ i ] = -1 ;
        ch[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        if ( fst[ a[ i ] ] == -1 ) {
            fst[ a[ i ] ] = i ;
        }
        lst[ a[ i ] ] = i ;
    }
    int ans = 0 , tot = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fst[ i ] == -1 ) { continue ; }
        ++ tot ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        int j = i ;
        while ( j > 1 && a[ j - 1 ] == a[ i ] ) { -- j ; }
        if ( j == fst[ a[ i ] ] ) {
            ++ ans ;
            i = j ;
            if ( i > 1 && a[ i - 1 ] > a[ i ] ) { break ; }
        }
        else {
            break ;
        }
    }
    cout << tot - ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}