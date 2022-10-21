#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std ;


#define MAXN 1000007

vector < int > v[ MAXN ] ;

int st , x , k ;

int used[ MAXN ] ;

void init ( ) {
    int i , j ;
    for ( i = 2 ; i < MAXN ; i ++ ) {
        if ( used[ i ] != 0 ) { continue ; }
        for ( j = i ; j < MAXN ; j += i ) {
            used[ j ] = 1 ;
            v[ j ].push_back ( i ) ;
        }
    }
}

bool f ( int sr ) {
    int i , mask ;
    int sz = v[ x ].size ( ) ;
    int tot = 0 ;
    for ( mask = 0 ; mask < (1<<sz) ; mask ++ ) {
        int curval = 1 ;
        int br = 0 ;
        for ( i = 0 ; i < sz ; i ++ ) {
            if ( ( mask & ( 1 << i ) ) != 0 ) { curval *= v[ x ][ i ] ; br ++ ; }
        }
        int add = ( ( sr / curval ) - ( st / curval ) ) ;
        if ( ( br % 2 ) == 0 ) { tot += add ; }
        else { tot -= add ; }
    }
    return ( tot >= k ) ;
}

void input ( ) {
    scanf ( "%d%d%d" , &st , &x , &k ) ;
}


void solve ( ) {
    int l , r , mid ;
    l = st + 1 ;
    r = 1000 * MAXN - 1 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { l ++ ; }
    printf ( "%d\n" , l ) ;
}


int main ( ) {
    init ( ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t != 0 ) {
        t -- ;
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}