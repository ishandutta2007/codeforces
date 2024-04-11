#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 100007

int n , m ;
int st[ MAXN ] ;
int en[ MAXN ] ;

int add[ MAXN ] ;

int a[ MAXN ] ;

int fst[ MAXN ] ;
int lst[ MAXN ] ;

int br[ MAXN ] ;

int l[ MAXN ] ;
int r[ MAXN ] ;

vector < int > v ;

void addval ( int x ) {
    if ( v.size ( ) == 0 ) {
        v.push_back ( x ) ;
        return ;
    }
    int l , r , mid ;
    l = 0 ;
    r = v.size ( ) - 1 ;
    if ( v[ r ] <= x ) {
        v.push_back ( x ) ;
        return ;
    }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( v[ mid ] <= x ) { l = mid ; }
        else { r = mid ; }
    }
    while ( v[ l ] <= x ) { l ++ ; }
    v[ l ] = x ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d" , &st[ i ] , &en[ i ] ) ;
        add[ st[ i ] ] ++ ;
        add[ en[ i ] + 1 ] -- ;
    }
}

void solve ( ) {
    int cur = 0 ;
    int i , j ;
    for ( i = 1 ; i <= m ; i ++ ) {
        cur += add[ i ] ;
        a[ i ] = cur ;
    }
    v.clear ( ) ;
    for ( i = 1 ; i <= m ; i ++ ) {
        addval ( a[ i ] ) ;
        l[ i ] = v.size ( ) ;
    }
    v.clear ( ) ;
    int ans = 0 ;
    for ( i = m ; i >= 1 ; i -- ) {
        addval ( a[ i ] ) ;
        r[ i ] = v.size ( ) ;
        if ( ans < ( l[ i ] + r[ i ] - 1 ) ) {
            ans = ( l[ i ] + r[ i ] - 1 ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}