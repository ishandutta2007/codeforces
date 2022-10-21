#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 5007

int n , q ;
map < string , int > ZX ;
struct tuhla {
    bool fl ;
    int x , y ;
    int type ;
};
tuhla a[ MAXN ] ;
string uval[ MAXN ] ;

int bit[ MAXN ] ;

void input ( ) {
    cin >> q >> n ;
}

void solve ( ) {
    int i , j , t ;
    string cur ;
    int id = 1 ;
    ZX[ "?" ] = 0 ;
    for ( id = 1 ; id <= q ; id ++ ) {
        string varname ;
        string foo ;
        cin >> varname >> foo ;
        getline ( cin , cur ) ;
        int sz = cur.size ( ) ;
        string aux ;
        for ( i = 1 ; i < sz ; i ++ ) {
            if ( cur[ i ] != '0' && cur[ i ] != '1' ) { break ; }
        }
        if ( i == sz ) { ZX[ varname ] = id ; a[ id ].fl = true ; uval[ id ] = cur ; continue ; }
        a[ id ].fl = false ;
        for ( i = 1 ; i < sz ; i ++ ) {
            if ( cur[ i ] == ' ' ) { break ; }
            aux += cur[ i ] ;
        }
        a[ id ].x = ZX[ aux ] ;
        for ( ; i < sz ; i ++ ) {
            if ( cur[ i ] >= 'A' && cur[ i ] <= 'Z' ) {
                if ( cur[ i ] == 'A' ) { a[ id ].type = 1 ; }
                else if ( cur[ i ] == 'O' ) { a[ id ].type = 2 ; }
                else { a[ id ].type = 3 ; }
                break ;
            }
        }
        aux.clear ( ) ;
        for ( ; i < sz ; i ++ ) {
            if ( cur[ i ] >= 'A' && cur[ i ] <= 'Z' ) { continue ; }
            if ( cur[ i ] == ' ' ) { continue ; }
            aux += cur[ i ] ;
        }
        a[ id ].y = ZX[ aux ] ;
        ZX[ varname ] = id ;
    }
    string ret1 , ret2 ;
    for ( j = 0 ; j < n ; j ++ ) {
        int br[ 2 ] ;
        br[ 0 ] = br[ 1 ] = 0 ;
        for ( t = 0 ; t < 2 ; t ++ ) {
            for ( i = 1 ; i <= q ; i ++ ) {
                if ( a[ i ].fl == true ) {
                    br[ t ] += ( uval[ i ][ j + 1 ] == '1' ) ;
                    bit[ i ] = ( uval[ i ][ j + 1 ] - '0' ) ;
                    continue ;
                }
                int h1 , h2 ;
                if ( a[ i ].x == 0 ) { h1 = t ; }
                else { h1 = bit[ a[ i ].x ] ; }
                if ( a[ i ].y == 0 ) { h2 = t ; }
                else { h2 = bit[ a[ i ].y ] ; }
                if ( a[ i ].type == 1 ) { h1 = (h1&h2) ; }
                else if ( a[ i ].type == 2 ) { h1 = (h1|h2) ; }
                else { h1 = (h1^h2) ; }
                br[ t ] += h1 ;
                bit[ i ] = h1 ;
            }
        }
        if ( br[ 0 ] == br[ 1 ] ) {
            ret1 += '0' ;
            ret2 += '0' ;
        }
        else if ( br[ 0 ] < br[ 1 ] ) {
            ret1 += '0' ;
            ret2 += '1' ;
        }
        else {
            ret1 += '1' ;
            ret2 += '0' ;
        }
    }
    cout << ret1 << "\n" ;
    cout << ret2 << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}