#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std ;

#define MAXN 100007

int n ;
string a ;

class Tree {
    public :
    int tr[ 3 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IR < IL ) { return ; }
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) { tr[ where ] += val ; return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

vector < Tree > w[ 11 ][ 4 ] ;
int trsz[ 11 ][ 11 ] ;

int trpos[ MAXN ][ 11 ] ;

char change ( char c ) {
    if ( c == 'A' ) { return '0' ; }
    if ( c == 'T' ) { return '1' ; }
    if ( c == 'G' ) { return '2' ; }
    if ( c == 'C' ) { return '3' ; }
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        a[ i ] = change ( a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j , t ;
    int pos ;
    for ( i = 1 ; i <= 10 ; i ++ ) {
        for ( t = 0 ; t < 4 ; t ++ ) {
            w[ i ][ t ].resize ( i ) ;
        }
        for ( j = 0 ; j < i ; j ++ ) {
            trsz[ i ][ j ] = 0 ;
            for ( pos = j ; pos < n ; pos += i ) {
                trsz[ i ][ j ] ++ ;
                trpos[ pos ][ i ] = trsz[ i ][ j ] ;
            }
            for ( t = 0 ; t < 4 ; t ++ ) {
                w[ i ][ t ][ j ].init ( 1 , 1 , trsz[ i ][ j ] ) ;
            }
            for ( pos = j ; pos < n ; pos += i ) {
                int id = ( a[ pos ] - '0' ) ;
                w[ i ][ id ][ j ].update ( 1 , 1 , trsz[ i ][ j ] , trpos[ pos ][ i ] , 1 ) ;
            }
        }
    }
    int q ;
    cin >> q ;
    char c ;
    string s ;
    while ( q != 0 ) {
        q -- ;
        int type ;
        cin >> type ;
        if ( type == 1 ) {
            cin >> pos >> c ;
            pos -- ;
            c = change ( c ) ;
            for ( i = 1 ; i <= 10 ; i ++ ) {
                int ost = ( pos % i ) ;
                w[ i ][ ( a[ pos ] - '0' ) ][ ost ].update ( 1 , 1 , trsz[ i ][ ost ] , trpos[ pos ][ i ] , -1 ) ;
                w[ i ][ ( c - '0' ) ][ ost ].update ( 1 , 1 , trsz[ i ][ ost ] , trpos[ pos ][ i ] , 1 ) ;
            }
            a[ pos ] = c ;
        }
        else {
            int l , r ;
            cin >> l >> r >> s ;
            l -- ;
            r -- ;
            int len = ( s.size ( ) ) ;
            for ( i = 0 ; i < len ; i ++ ) {
                s[ i ] = change ( s[ i ] ) ;
            }
            int aux = r ;
            while ( ( aux % len ) != ( l % len ) ) { aux -- ; }
            int st = l ;
            int ans = 0 ;
            for ( i = 0 ; i < len ; i ++ ) {
                ans += w[ len ][ ( s[ i ] - '0' ) ][ ( st % len ) ].query ( 1 , 1 , trsz[ len ][ ( st % len ) ] , trpos[ st ][ len ] , trpos[ aux ][ len ] ) ;
                st ++ ;
                aux ++ ;
                if ( aux > r ) { aux -= len ; }
                if ( aux < st ) { break ; }
            }
            printf ( "%d\n" , ans ) ;
        }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}