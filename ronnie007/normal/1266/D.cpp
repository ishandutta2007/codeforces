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

int n , m ;
long long f[ MAXN ] ;

struct edge {
    int x , y ;
    long long cost ;
    edge ( ) { x = y = cost = 0 ; }
    edge ( int _x , int _y , long long _cost ) {
        x = _x ;
        y = _y ;
        cost = _cost ;
    }
};

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        f[ x ] -= z , f[ y ] += z ;
    }
}

void solve ( ) {
    vector < int > v , w ;
    vector < edge > ret ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( f[ i ] > 0 ) { v.push_back ( i ) ; }
        else { w.push_back ( i ) ; }
    }
    while ( v.empty ( ) == false && w.empty ( ) == false ) {
        int x = v.back ( ) , y = w.back ( ) ;
        long long h = min ( f[ x ] , - f[ y ] ) ;
        if ( h != 0 ) {
            f[ x ] -= h ;
            f[ y ] += h ;
            ret.push_back ( edge ( y , x , h ) ) ;
        }
        while ( v.empty ( ) == false && f[ v.back ( ) ] == 0 ) { v.pop_back ( ) ; }
        while ( w.empty ( ) == false && f[ w.back ( ) ] == 0 ) { w.pop_back ( ) ; }
    }
    int sz = ret.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d %I64d\n" , ret[ i ].x , ret[ i ].y , ret[ i ].cost ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}