#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

int n , m ;
string a[ MAXN ] ;

bool fsym[ MAXN ] ;
bool fdig[ MAXN ] ;
bool flet[ MAXN ] ;

int get ( int x ) {
    return min ( x , m - x ) ;
}

void input ( ) {
    cin >> n >> m ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = 1000000 ;
    int i , j , t , z ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            for ( t = 0 ; t < n ; t ++ ) {
                if ( i == j || i == t || j == t ) { continue ; }
                int aux1 , aux2 , aux3 ;
                aux1 = aux2 = aux3 = 1000000 ;
                for ( z = 0 ; z < m ; z ++ ) {
                    if ( a[ i ][ z ] >= 'a' && a[ i ][ z ] <= 'z' ) { aux1 = min ( aux1 , get ( z ) ) ; }
                    if ( a[ j ][ z ] >= '0' && a[ j ][ z ] <= '9' ) { aux2 = min ( aux2 , get ( z ) ) ; }
                    if ( a[ t ][ z ] == '*' || a[ t ][ z ] == '#' || a[ t ][ z ] == '&' ) { aux3 = min ( aux3 , get ( z ) ) ; }
                }
                if ( aux1 != 1000000 && aux1 != 1000000 && aux3 != 1000000 ) {
                    ans = min ( ans , aux1 + aux2 + aux3 ) ;
                }
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}