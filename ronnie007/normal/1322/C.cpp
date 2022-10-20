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

#define MAXN 500007


int n , m ;
long long a[ MAXN ] ;
vector < int > v[ MAXN ] ;

struct tuhla {
    long long h[ 2 ] ;
    long long MOD[ 2 ] ;
    long long base ;
    long long val ;
    tuhla ( ) {
        h[ 0 ] = h[ 1 ] = 1 ;
        MOD[ 0 ] = 1000003 ;
        MOD[ 1 ] = 1000000007 ;
        base = n + 3 ;        
    }
    tuhla ( long long _val ) {
        h[ 0 ] = h[ 1 ] = 1 ;
        MOD[ 0 ] = 1000003 ;
        MOD[ 1 ] = 1000000007 ;
        base = n + 3 ;
        val = _val ;
    }
    void upd ( int x ) {
        for ( int i = 0 ; i < 2 ; ++ i ) {
            h[ i ] = ( h[ i ] * base + x ) % MOD[ i ] ;
        }
    }
    bool operator < ( tuhla other ) const {
        if ( h[ 0 ] != other.h[ 0 ] ) { return h[ 0 ] < other.h[ 0 ] ; }
        return h[ 1 ] < other.h[ 1 ] ;
    }
};
tuhla p[ MAXN ] ;
vector < tuhla > srt ;


long long w ( long long x , long long y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return w ( y , ( x % y ) ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
        v[ i ].clear ( ) ;
        p[ i ] = tuhla ( a[ i ] ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ y ].push_back ( x ) ;
    }
    srt.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
        int sz = v[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            p[ i ].upd ( v[ i ][ j ] ) ;
        }
        if ( sz > 0 ) { srt.push_back ( p[ i ] ) ; }
    }    
    sort ( srt.begin ( ) , srt.end ( ) ) ;
}

void solve ( ) {
    long long ans = 0 ;
    long long aux = srt[ 0 ].val ;
    int sz = srt.size ( ) ;
    for ( int i = 1 ; i < sz ; ++ i ) {
        if ( srt[ i - 1 ] < srt[ i ] ) {
            ans = w ( ans , aux ) ;
            aux = srt[ i ].val ;
        }
        else { aux += srt[ i ].val ; } 
    }
    ans = w ( ans , aux ) ;
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}