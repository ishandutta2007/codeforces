#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
#define MAXK 20

int n , m , k ;
string a , b ;
int aux[ MAXN ][ MAXK ] ;

int stval[ MAXN ] ;
int enval[ MAXN ] ;

int dp[ 1 << MAXK ] ;
int nw[ 1 << MAXK ] ;

void input ( ) {
    cin >> n >> m >> k ;
    cin >> a >> b ;
    for ( int i = 0 ; i < k ; ++ i ) {
        aux[ 0 ][ i ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x , y ; cin >> x >> y ;
        -- x , -- y ; 
        for ( int j = 0 ; j < k ; ++ j ) {
            aux[ i ][ j ] = aux[ i - 1 ][ j ] ;
        }
        swap ( aux[ i ][ x ] , aux[ i ][ y ] ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < k ; ++ j ) {
            stval[ i ] += ( ( a[ j ] - '0' ) << aux[ i ][ j ] ) ;
            enval[ i ] += ( ( b[ j ] - '0' ) << aux[ i ][ j ] ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ enval[ i ] ] = nw[ enval[ i ] ] = i ;
    }
    for ( int ans = k ; ans >= 0 ; -- ans ) {
        for ( int i = 0 ; i + m <= n ; ++ i ) {
            if ( i + m <= dp[ stval[ i ] ] ) {
                cout << ans << "\n" ;
                cout << i + 1 << " " << dp[ stval[ i ] ] << "\n" ;
                return ;
            }
        }
        for ( int i = 0 ; i < ( 1 << k ) ; ++ i ) {
            for ( int j = 0 ; j < k ; ++ j ) {
                nw[ i ^ ( 1 << j ) ] = max ( nw[ i ^ ( 1 << j ) ] , dp[ i ] ) ;
            }
        }
        for ( int i = 0 ; i < ( 1 << k ) ; ++ i ) {
            dp[ i ] = nw[ i ] ;
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