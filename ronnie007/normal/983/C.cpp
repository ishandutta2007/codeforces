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

#define MAXN 2007
#define inf 1000000007
#define lim 10000
int n ;
pair < int , int > a[ MAXN ] ;

int dp[ lim + 1 ] ;
int memo[ lim + 1 ] ;
int aux[ lim + 1 ] ;

bool extr ( int &x , int &y , int &z , int &t , int val ) {
    x = ( val / 1000 ) ;
    y = ( val / 100 ) % 10 ;
    z = ( val / 10 ) % 10 ;
    t = val % 10 ;
    if ( x > y || y > z || z > t ) { return false ; }
    return true ;
}

void sort4 ( int &x , int &y , int &z , int &t ) {
    if ( x > y ) { swap ( x , y ) ; }
    if ( z > t ) { swap ( z , t ) ; }
    if ( y > t ) { swap ( y , t ) ; }
    if ( x > z ) { swap ( x , z ) ; }
    if ( y > z ) { swap ( y , z ) ; }
}

bool ins ( int &x , int &y , int &z , int &t , int sr ) {
    if ( x == 0 ) { x = sr ; return true ; }
    if ( y == 0 ) { y = sr ; return true ; }
    if ( z == 0 ) { z = sr ; return true ; }
    if ( t == 0 ) { t = sr ; return true ; }
    return false ;
}

int query ( int st , vector < int > eval , int en ) {
    if ( eval.size ( ) == 0 ) { return abs ( st - en ) + 1 ; }
    int ret = eval.size ( ) + 1 ;
    ret += min ( abs ( eval[ 0 ] - st ) + eval.back ( ) - eval[ 0 ] + abs ( eval.back ( ) - en ) ,
                 abs ( eval.back ( ) - st ) + eval.back ( ) - eval[ 0 ] + abs ( en - eval[ 0 ] ) ) ;
    return ret ;
}

int encode ( int x , int y , int z , int t ) {
    return ( x * 1000 + y * 100 + z * 10 + t ) ;
}

void advance ( int id ) {
    int x , y , z , t ;
    for ( int i = lim - 1 ; i >= 0 ; -- i ) {
        aux[ i ] = inf ;
    }
    for ( int i = lim - 1 ; i >= 0 ; -- i ) {
        if ( extr ( x , y , z , t , i ) == false ) { continue ; }
        if ( dp[ i ] == inf ) { continue ; }
        for ( int mask = 0 ; mask < 16 ; ++ mask ) {
            if ( ( mask & 1 ) > 0 && x == 0 ) { continue ; }
            if ( ( mask & 2 ) > 0 && y == 0 ) { continue ; }
            if ( ( mask & 4 ) > 0 && z == 0 ) { continue ; }
            if ( ( mask & 8 ) > 0 && t == 0 ) { continue ; }
            vector < int > eval ;
            eval.clear ( ) ;
            int pt1 , pt2 , pt3 , pt4 ;
            pt1 = x ; pt2 = y ; pt3 = z ; pt4 = t ;
            if ( ( mask & 1 ) > 0 ) { eval.push_back ( x ) ; pt1 = 0 ; }
            if ( ( mask & 2 ) > 0 ) { eval.push_back ( y ) ; pt2 = 0 ; }
            if ( ( mask & 4 ) > 0 ) { eval.push_back ( z ) ; pt3 = 0 ; }
            if ( ( mask & 8 ) > 0 ) { eval.push_back ( t ) ; pt4 = 0 ; }
            if ( ins ( pt1 , pt2 , pt3 , pt4 , a[ id ].second ) == false ) { continue ; }
            sort4 ( pt1 , pt2 , pt3 , pt4 ) ;
            int add = query ( a[ id - 1 ].first , eval , a[ id ].first ) ;

            int nwid = encode ( pt1 , pt2 , pt3 , pt4 ) ;
            aux[ nwid ] = min ( aux[ nwid ] , dp[ i ] + add ) ;
        }
    }
    for ( int i = 0 ; i < lim ; ++ i ) {
        dp[ i ] = aux[ i ] ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    a[ 0 ].first = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < lim ; ++ i ) {
        dp[ i ] = inf ; 
    }
    dp[ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        advance ( i ) ;
    }
    for ( int i = 0 ; i < lim ; ++ i ) {
        memo[ i ] = dp[ i ] ;
    }
    int ans = inf ;
    for ( int i = 1 ; i <= 9 ; ++ i ) {
        a[ n + 1 ].first = i ;
        a[ n + 1 ].second = 0 ;
        advance ( n + 1 ) ;
        ans = min ( ans , dp[ 0 ] - 1 ) ;
        for ( int j = 0 ; j < lim ; ++ j ) {
            dp[ j ] = memo[ j ] ;
        }
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}