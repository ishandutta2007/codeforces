#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std ;

#define inf 1000000007
#define MAXN 300007
int n ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

int mx = 0 ;

map < int , int > ZX ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    mx = -inf ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        ZX[ a[ i ] ] ++ ;
        if ( mx < a[ i ] ) { mx = a[ i ] ; }
    }
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    int i , j ;
    int br1 , br2 ;
    int ans = inf ;
    int exp1 , exp2 ;
    exp1 = ZX[ mx ] ;
    exp2 = ZX[ mx - 1 ] ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int sz = v[ i ].size ( ) ;
        br1 = br2 = 0 ;
        int coef1 , coef2 ;
        coef1 = coef2 = 0 ;
        if ( a[ i ] == mx ) { coef1 = 1 ; }
        if ( a[ i ] == mx - 1 ) { coef2 = 1 ; }
        for ( j = 0 ; j < sz ; j ++ ) {
            if ( a[ v[ i ][ j ] ] == mx ) { br1 ++ ; }
            if ( a[ v[ i ][ j ] ] == mx - 1 ) { br2 ++ ; }
        }
        if ( br1 != exp1 - coef1 ) { ans = min ( ans , mx + 2 ) ; }
        else if ( br2 != exp2 - coef2 ) { ans = min ( ans , mx + 1 ) ; }
        else if ( br1 != 0 ) { ans = min ( ans , mx + 1 ) ; }
        else { ans = min ( ans , mx ) ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}