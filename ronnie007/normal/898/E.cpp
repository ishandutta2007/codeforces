#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std ;

#define MAXN 200007
#define inf 1000000007


int n ;
int a[ MAXN ] ;

int sq[ MAXN ] ;
int non[ MAXN ] ;

vector < int > v ;
int br1 , br2 ;

int getl ( int x ) {
    int l , r , mid ;
    l = 0 ;
    r = v.size ( ) - 1 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( v[ mid ] > x ) { r = mid ; }
        else { l = mid ; }
    }
    while ( v[ r ] > x ) { r -- ; }
    return r ;
}
int getr ( int x ) {
    int l , r , mid ;
    l = 0 ;
    r = v.size ( ) ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( v[ mid ] < x ) { l = mid ; }
        else { r = mid ; }
    }
    while ( v[ l ] < x ) { l ++ ; }
    return l ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i <= 100000 ; i ++ ) {
        int u = ( i * i ) ;
        if ( u > 2 * inf ) { break ; }
        v.push_back ( u ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        int u1 , u2 ;
        u1 = getl ( a[ i ] ) ;
        u2 = getr ( a[ i ] ) ;
        sq[ i ] = min ( a[ i ] - v[ u1 ] , v[ u2 ] - a[ i ] ) ;
        if ( sq[ i ] == 0 ) {
            non[ i ] = 1 ;
            if ( a[ i ] == 0 ) { non[ i ] = 2 ; }
            br1 ++ ;
        }
        else {
            non[ i ] = 0 ;
            br2 ++ ;
        }
    }
}

void solve ( ) {
    int i ;
    if ( br1 == br2 ) {
        printf ( "0\n" ) ;
        return ;
    }
    long long ans = 0 ;
    if ( br1 < br2 ) {
        vector < int > aux ;
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( sq[ i ] != 0 ) {
                aux.push_back ( sq[ i ] ) ;
            }
        }
        sort ( aux.begin ( ) , aux.end ( ) ) ;
        for ( i = 0 ; i < n ; i ++ ) {
            ans += aux[ i ] ;
            br1 ++ ;
            br2 -- ;
            if ( br1 == br2 ) { break ; }
        }
        printf ( "%I64d\n" , ans ) ;
    }
    else {
        vector < int > aux ;
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( non[ i ] != 0 ) {
                aux.push_back ( non[ i ] ) ;
            }
        }
        sort ( aux.begin ( ) , aux.end ( ) ) ;
        for ( i = 0 ; i < n ; i ++ ) {
            ans += aux[ i ] ;
            br1 -- ;
            br2 ++ ;
            if ( br1 == br2 ) { break ; }
        }
        printf ( "%I64d\n" , ans ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}