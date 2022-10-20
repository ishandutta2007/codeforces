#include<bits/stdc++.h>
using namespace std ;

#define MAXN 20
#define MAXLEN 400007

int n ;
string a[ MAXN ] ;
int sm[ MAXN ] ;
int mn[ MAXN ] ;

int dp[ ( 1 << MAXN ) ][ 2 ] ;
int tot[ ( 1 << MAXN ) ] ;

vector < int > ch[ MAXN ] ;

vector < int > cnt[ MAXN ] ;
int offset[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
        int aux = 0 ;
        int sz = a[ i ].size ( ) ;
        cnt[ i ].resize ( 2 * sz + 1 ) ;
        for ( int j = 0 ; j < 2 * sz + 1 ; ++ j ) {
            cnt[ i ][ j ] = 0 ;
        }
        offset[ i ] = sz ;
        mn[ i ] = 1000007 ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( a[ i ][ j ] == '(' ) { ++ aux ; }
            else { -- aux ; }
            if ( mn[ i ] > aux ) {
                mn[ i ] = aux ;
            }
            if ( mn[ i ] == aux ) { ++ cnt[ i ][ offset[ i ] + aux ] ; }
        }
        sm[ i ] = aux ;
    }
}


void solve ( ) {
    for ( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
        dp[ i ][ 0 ] = dp[ i ][ 1 ] = -1 ;
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( ( i & ( 1 << j ) ) != 0 ) {
                tot[ i ] += sm[ j ] ;
            }
        }
    }
    dp[ 0 ][ 0 ] = 0 ;
    int ans = 0 ;
    for ( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
        for ( int t = 0 ; t < 2 ; ++ t ) {
            if ( dp[ i ][ t ] == -1 ) { continue ; }
            ans = max ( ans , dp[ i ][ t ] ) ;
            if ( t == 1 ) { continue ; }
            for ( int j = 0 ; j < n ; ++ j ) {
                if ( ( i & ( 1 << j ) ) != 0 ) { continue ; }
                int nw = t ;
                if ( tot[ i ] + mn[ j ] < 0 ) { nw = 1 ; }
                if ( offset[ j ] - tot[ i ] >= 0 && offset[ j ] - tot[ i ] < 2 * (int)a[ j ].size ( ) + 1 ) {
                    dp[ i + ( 1 << j ) ][ nw ] = max ( dp[ i + ( 1 << j ) ][ nw ] , dp[ i ][ t ] + cnt[ j ][ offset[ j ] - tot[ i ] ] ) ;
                }
                else {
                    dp[ i + ( 1 << j ) ][ nw ] = max ( dp[ i + ( 1 << j ) ][ nw ] , dp[ i ][ t ] ) ;
                }
            }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}