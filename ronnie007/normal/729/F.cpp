#include<bits/stdc++.h>
using namespace std ;

#define MAXN 4007
#define MXK 91
#define inf 1000000007

int n ;
int a[ MAXN ] ;
int pref[ MAXN ] ;

bool vis[ MAXN ][ MXK ][ MXK ] ;
int dp[ MAXN ][ MXK ][ MXK ] ;

void dfs ( int l , int diff , int lst ) {
    if ( vis[ l ][ diff ][ lst ] == true ) {
        return ;
    }
    vis[ l ][ diff ][ lst ] = true ;
    int r = n + 1 - l - diff ;
    dp[ l ][ diff ][ lst ] = -inf ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        int aux = l + lst + i ;
        if ( aux >= r ) { break ; }
        int mn = inf ;
        for ( int j = 0 ; j < 2 ; ++ j ) {
            int sr = r - ( lst + i + j ) ;
            if ( aux >= sr ) { break ; }
            dfs ( aux , diff + j , lst + i + j ) ;
            int sub = pref[ r - 1 ] - pref[ sr - 1 ] ;
            mn = min ( mn , dp[ aux ][ diff + j ][ lst + i + j ] - sub ) ;
        }
        if ( mn == inf ) { mn = 0 ; }
        int add = ( pref[ aux ] - pref[ l ] ) ;
        dp[ l ][ diff ][ lst ] = max ( dp[ l ][ diff ][ lst ] , add + mn ) ;
    }
    if ( dp[ l ][ diff ][ lst ] == - inf ) { dp[ l ][ diff ][ lst ] = 0 ; }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        pref[ i ] = ( pref[ i - 1 ] + a[ i ] ) ;
    }
}

void solve ( ) {
    dfs ( 0 , 0 , 1 ) ;
    printf ( "%d\n" , dp[ 0 ][ 0 ][ 1 ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}