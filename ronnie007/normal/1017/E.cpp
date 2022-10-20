#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 100007
#define inf 1000000007
#define eps 0.001
#define PI 3.14159265359

int n , m ;

struct tuhla {
    long long x , y ;
    tuhla ( ) { x = y = 0 ; }
    tuhla ( long long _x , long long _y ) {
        x = _x ;
        y = _y ;
    }
};
bool cmp ( tuhla p1 , tuhla p2 ) {
    if ( p1.x == p2.x ) { return ( p1.y < p2.y ) ; }
    return ( p1.x < p2.x ) ;
}

vector < tuhla > a , b ;
vector < tuhla > h1 , h2 ;

double text[ 6 * MAXN ] ;
double pattern[ 6 * MAXN ] ;
int fval[ 6 * MAXN ] ;

bool eq ( double p1 , double p2 ) {
    p1 -= p2 ;
    if ( p1 < eps && p1 > -eps ) { return true ; }
    return false ;
}

double slope ( tuhla p1 , tuhla p2 ) {
    double deltax = ( p2.x - p1.x ) ;
    double deltay = ( p2.y - p1.y ) ;
    if ( eq ( deltax , 0 ) == true ) {
        if ( deltay < 0 ) { return -inf ; }
        return inf ;
    }
    return ( deltay / deltax ) ;
}

vector < tuhla > get_hull ( vector < tuhla > v ) {
    vector < tuhla > ret ;
    int i ;
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
    int sz = v.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        while ( ret.size ( ) >= 2 && slope ( ret[ ret.size ( ) - 2 ] , v[ i ] ) >= slope ( ret[ ret.size ( ) - 2 ] , ret[ ret.size ( ) - 1 ] ) ) {
            ret.pop_back ( ) ;
        }
        ret.push_back ( v[ i ] ) ;
    }
    ret.pop_back ( ) ;
    int rem = ret.size ( ) ;
    for ( i = sz - 1 ; i >= 0 ; i -- ) {
        while ( ret.size ( ) >= 2 + rem && slope ( v[ i ] , ret[ ret.size ( ) - 2 ] ) >= slope ( ret[ ret.size ( ) - 1 ] , ret[ ret.size ( ) - 2 ] ) ) {
            ret.pop_back ( ) ;
        }
        ret.push_back ( v[ i ] ) ;
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    a.resize ( n ) ;
    b.resize ( m ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%I64d%I64d" , &a[ i ].x , &a[ i ].y ) ;
    }
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%I64d%I64d" , &b[ i ].x , &b[ i ].y ) ;
    }
}

void solve ( ) {
    h1 = get_hull ( a ) ;
    h2 = get_hull ( b ) ;
    if ( h1.size ( ) != h2.size ( ) ) { printf ( "NO\n" ) ; return ; }
    int i ;
    int sz = h1.size ( ) ;
    int cur = 0 ;
    h1.push_back ( h1[ 1 ] ) ;
    h2.push_back ( h2[ 1 ] ) ;
    for ( i = 0 ; i < sz - 1 ; i ++ ) {
        text[ cur ] = ( h1[ i ].x - h1[ i + 1 ].x ) * ( h1[ i ].x - h1[ i + 1 ].x ) + ( h1[ i ].y - h1[ i + 1 ].y ) * ( h1[ i ].y - h1[ i + 1 ].y ) ;
        pattern[ cur ] = ( h2[ i ].x - h2[ i + 1 ].x ) * ( h2[ i ].x - h2[ i + 1 ].x ) + ( h2[ i ].y - h2[ i + 1 ].y ) * ( h2[ i ].y - h2[ i + 1 ].y ) ;
        cur ++ ;
        double ret1 = atan2 ( h1[ i ].y - h1[ i + 1 ].y , h1[ i ].x - h1[ i + 1 ].x ) ;
        double ret2 = atan2 ( h1[ i + 2 ].y - h1[ i + 1 ].y , h1[ i + 2 ].x - h1[ i + 1 ].x ) ;
        if ( ret2 < ret1 ) { ret2 += 2 * PI ; }
        text[ cur ] = ( ret2 - ret1 ) ;
        ret1 = atan2 ( h2[ i ].y - h2[ i + 1 ].y , h2[ i ].x - h2[ i + 1 ].x ) ;
        ret2 = atan2 ( h2[ i + 2 ].y - h2[ i + 1 ].y , h2[ i + 2 ].x - h2[ i + 1 ].x ) ;
        if ( ret2 < ret1 ) { ret2 += 2 * PI ; }
        pattern[ cur ] = ( ret2 - ret1 ) ;
        cur ++ ;
    }
    for ( i = 0 ; i < cur ; i ++ ) {
        text[ cur + i ] = text[ i ] ;
    }
    fval[ 0 ] = 0 ;
    fval[ 1 ] = 0 ;
    int len = 0 ;
    for ( i = 2 ; i <= cur ; i ++ ) {
        while ( len > 0 && eq ( pattern[ len ] , pattern[ i - 1 ] ) == false ) { len = fval[ len ] ; }
        if ( eq ( pattern[ len ] , pattern[ i - 1 ] ) == true ) { len ++ ; }
        fval[ i ] = len ;
    }
    len = 0 ;
    for ( i = 1 ; i <= 2 * cur ; i ++ ) {
        while ( len > 0 && eq ( pattern[ len ] , text[ i - 1 ] ) == false ) { len = fval[ len ] ; }
        if ( eq ( pattern[ len ] , text[ i - 1 ] ) == true ) { len ++ ; }
        if ( len == cur ) { printf ( "YES\n" ) ; return ; }
    }
    printf ( "NO\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}