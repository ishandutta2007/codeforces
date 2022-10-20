#include<bits/stdc++.h>
using namespace std ;

#define MAXN 21
#define inf 1000000007

int n , m ;
string a[ MAXN ] ;
int c[ MAXN ][ MAXN ] ;

int dp[ (1<<MAXN) ] ;

int sm[ MAXN ][ 27 ] ;
int mx[ MAXN ][ 27 ] ;
int mask[ MAXN ][ 27 ] ;


void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            cin >> c[ i ][ j ] ;
        }
    }
    for ( int j = 0 ; j < m ; ++ j ) {
        for ( int i = 0 ; i < n ; ++ i ) {
            int id = ( a[ i ][ j ] - 'a' ) ;
            sm[ j ][ id ] += c[ i ][ j ] ;
            mx[ j ][ id ] = max ( mx[ j ][ id ] , c[ i ][ j ] ) ;
            mask[ j ][ id ] += (1<<i) ;
        }
    }
}

void solve ( ) {
    dp[ 0 ] = 0 ;
    int lim = (1<<n) ;
    
    for ( int i = 1 ; i < lim ; ++ i ) {
        int x = 0 ;
        while ( ( i & (1<<x) ) == 0 ) { ++ x ; }
        
        dp[ i ] = inf ;
        for ( int j = 0 ; j < m ; ++ j ) {
            dp[ i ] = min ( dp[ i ] , dp[ i - (1<<x) ] + c[ x ][ j ] ) ;
            int id = ( a[ x ][ j ] - 'a' ) ;
            dp[ i ] = min ( dp[ i ] , dp[ i & ( i ^ mask[ j ][ id ] ) ] + sm[ j ][ id ] - mx[ j ][ id ] ) ;
        }
    }
    cout << dp[ (1<<n) - 1 ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}