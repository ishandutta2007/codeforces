#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 1000007

int n , m ;
string a[ MAXN ] ;
vector < int > pref[ 2 ][ MAXN ] ;
vector < int > init[ MAXN ] ;

int get_sm ( int stx , int sty , int enx , int eny , int id ) {
    if ( stx < 1 ) { stx = 1 ; }
    if ( sty < 1 ) { sty = 1 ; }
    if ( enx > n ) { enx = n ; }
    if ( eny > m ) { eny = m ; }
    return ( pref[ id ][ enx ][ eny ] - pref[ id ][ stx - 1 ][ eny ] - pref[ id ][ enx ][ sty - 1 ] + pref[ id ][ stx - 1 ][ sty - 1 ] ) ;
}

bool f ( long long x ) {
    long long area = 2 * x + 1 ;
    area *= area ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            init[ i ][ j ] = 0 ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            int h = get_sm ( i - x , j - x , i + x , j + x , 0 ) ;
            if ( h == area ) { init[ i ][ j ] = 1 ; }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            pref[ 1 ][ i ][ j ] = init[ i ][ j ] + pref[ 1 ][ i - 1 ][ j ] + pref[ 1 ][ i ][ j - 1 ] - pref[ 1 ][ i - 1 ][ j - 1 ] ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            int h = get_sm ( i - x , j - x , i + x , j + x , 1 ) ;
            if ( a[ i ][ j ] == '.' && h > 0 ) { return false ; }
            if ( a[ i ][ j ] == 'X' && h == 0 ) { return false ; }
        }
    }
    return true ;
}

void input ( ) {
    cin >> n >> m ;
    init[ 0 ].resize ( m + 1 ) ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        pref[ 0 ][ i ].resize ( m + 1 ) ;
        pref[ 1 ][ i ].resize ( m + 1 ) ;
        for ( int j = 0 ; j <= m ; ++ j ) {
            pref[ 0 ][ i ][ j ] = pref[ 1 ][ i ][ j ] = 0 ;
        }
    }
    for ( int i = 0 ; i <= m ; ++ i ) {
        a[ 0 ] += '#' ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        init[ i ].resize ( m + 1 ) ;
        cin >> a[ i ] ;
        a[ i ] = '#' + a[ i ] ;
        for ( int j = 0 ; j <= m ; ++ j ) {
            init[ i ][ j ] = 0 ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            pref[ 0 ][ i ][ j ] = ( a[ i ][ j ] == 'X' ) + pref[ 0 ][ i - 1 ][ j ] + pref[ 0 ][ i ][ j - 1 ] - pref[ 0 ][ i - 1 ][ j - 1 ] ;
        }
    }
    int l , r ;
    l = 0 ;
    r = min ( n , m ) + 1 ;
    while ( r - l > 2 ) {
        int mid = ( ( l + r ) >> 1 ) ;
        if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    while ( f ( r ) == false ) { -- r ; }
    cout << r << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i , cout << "\n" ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( init[ i ][ j ] == 1 ) { cout << 'X' ; }
            else { cout << '.' ; }
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