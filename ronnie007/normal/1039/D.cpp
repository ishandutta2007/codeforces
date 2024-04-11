#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 100007


int n ;
vector < int > v[ MAXN ] ;
int sz[ MAXN ] ;
int ans[ MAXN ] ;

pair < int , int > dp[ MAXN ] ;

vector < pair < int , int > > ord ;

void init ( int vertex , int prv ) {
    for ( int i = 0 ; i < sz[ vertex ] ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        init ( v[ vertex ][ i ] , vertex ) ;
    }
    ord.push_back ( { vertex , prv } ) ;
}

int f ( int x ) {
    for ( int j = 0 ; j < n ; ++ j ) {
        int vertex = ord[ j ].first ;
        int prv = ord[ j ].second ;
        int aux[ 2 ] = { 0 , 0 } ;
        dp[ vertex ] = { 0 , 0 } ;
        for ( int i = 0 ; i < sz[ vertex ] ; ++ i ) {
            if ( v[ vertex ][ i ] == prv ) { continue ; }
            dp[ vertex ].first += dp[ v[ vertex ][ i ] ].first ;
            int len = dp[ v[ vertex ][ i ] ].second ;
            if ( len > aux[ 0 ] ) {
                aux[ 1 ] = aux[ 0 ] ;
                aux[ 0 ] = len ;
            }
            else if ( len > aux[ 1 ] ) {
                aux[ 1 ] = len ;
            }
        }
        if ( aux[ 0 ] + aux[ 1 ] + 1 >= x ) {
            ++ dp[ vertex ].first , dp[ vertex ].second = 0 ;
        }
        else {
            dp[ vertex ].second = aux[ 0 ] + 1 ;
        }
    }
    return dp[ 1 ].first ;
}

void rec ( int l , int r , int hi , int lo ) {
    if ( l > r ) { return ; }
    if ( hi == lo ) {
        for ( int i = l ; i <= r ; ++ i ) {
            ans[ i ] = lo ;
        }
        return ;
    }
    int mid = ( l + r ) / 2 ;
    int ret = f ( mid ) ;
    ans[ mid ] = ret ;
    rec ( l , mid - 1 , hi , ret ) ;
    rec ( mid + 1 , r , ret , lo ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) { sz[ i ] = v[ i ].size ( ) ; }
    init ( 1 , -1 ) ;
}

void solve ( ) {
    rec ( 1 , n , n , 0 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d\n" , ans[ i ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}