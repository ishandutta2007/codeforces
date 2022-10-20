#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 200007

int n ;
string a ;

vector < int > v[ 26 ] ;
int pos[ 26 ] ;

int aux[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        ++ tr[ where ] ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else { update ( 2 * where + 1 , mid + 1 , IR , pos ) ; }
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR || IL > IR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};

Tree w ;

void input ( ) {
    cin >> n ;
    cin >> a ;
    for ( int i = 0 ; i < n ; ++ i ) {
        v[ a[ i ] - 'a' ].push_back ( i ) ;
    }
}

void solve ( ) {
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        aux[ v[ a[ i ] - 'a' ][ pos[ a[ i ] - 'a' ] ++ ] ] = ( n - 1 ) - i ;
    }
    w.init ( 1 , 1 , n ) ;
    long long ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        ++ aux[ i ] ;
        ans += w.query ( 1 , 1 , n , aux[ i ] , n ) ;
        w.update ( 1 , 1 , n , aux[ i ] ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}