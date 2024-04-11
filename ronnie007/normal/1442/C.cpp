#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define LOG 22
#define inf 1000000007
#define MOD 998244353

int n , m ;

vector < int > v[ MAXN ][ 2 ] ;
long long pw[ MAXN ] ;

int dp[ MAXN ][ LOG ] ;

pair < int , int > dist[ MAXN ][ 2 ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ][ 0 ].push_back ( y ) ;
        v[ y ][ 1 ].push_back ( x ) ;
    }
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * 2 ) % MOD ;
    }
}

void dijkstra ( ) {
    priority_queue < pair < pair < int , int > , pair < int , int > > > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ i ][ 0 ] = dist[ i ][ 1 ] = { inf , inf } ;
    }
    dist[ 1 ][ 0 ] = { 0 , 0 } ;
    q.push ( { { 1 , 0 } , { 0 , 0 } } ) ;
    while ( q.empty ( ) == false ) {
        auto data = q.top ( ) ;
        q.pop ( ) ;
        int vertex = data.first.first ;
        int id = data.first.second ;
        pair < int , int > cost = data.second ;
        cost.first = - cost.first ; cost.second = - cost.second ;
        if ( cost != dist[ vertex ][ id ] ) { continue ; }
        int sz = v[ vertex ][ id ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int to = v[ vertex ][ id ][ i ] ;
            pair < int , int > nw = cost ;
            ++ nw.second ;
            if ( dist[ to ][ id ] > nw ) {
                dist[ to ][ id ] = nw ;
                q.push ( { { to , id } , { - nw.first , - nw.second } } ) ;
            }
        }
        pair < int , int > nw = cost ;
        ++ nw.first ;
        if ( dist[ vertex ][ id ^ 1 ] > nw ) {
            dist[ vertex ][ id ^ 1 ] = nw ;
            q.push ( { { vertex , id ^ 1 } , { - nw.first , - nw.second } } ) ;
        }
    }
}

void solve ( ) {
    queue < pair < int , int > > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < LOG ; ++ j ) {
            dp[ i ][ j ] = inf ;
        }
    }
    dp[ 1 ][ 0 ] = 0 ;
    q.push ( { 1 , 0 } ) ;
    while ( q.empty ( ) == false ) {
        auto aux = q.front ( ) ;
        q.pop ( ) ;
        int id = ( aux.second % 2 ) ;
        int sz = v[ aux.first ][ id ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int to = v[ aux.first ][ id ][ i ] ;
            if ( dp[ to ][ aux.second ] == inf ) {
                dp[ to ][ aux.second ] = dp[ aux.first ][ aux.second ] + 1 ;
                q.push ( { to , aux.second } ) ;
            }
        }
        if ( aux.second == LOG - 1 ) { continue ; }
        sz = v[ aux.first ][ id ^ 1 ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int to = v[ aux.first ][ id ^ 1 ][ i ] ;
            if ( dp[ to ][ aux.second + 1 ] == inf ) {
                dp[ to ][ aux.second + 1 ] = dp[ aux.first ][ aux.second ] + 1 ;
                q.push ( { to , aux.second + 1 } ) ;
            }
        }
    }
    long long ans = inf ;
    for ( int i = 0 ; i < LOG ; ++ i ) {
        if ( dp[ n ][ i ] != inf ) {
            ans = min ( ans , 1LL * dp[ n ][ i ] + (1<<i) - 1 ) ;
        }
    }
    if ( ans == inf ) {
        dijkstra ( ) ;
        pair < int , int > ret = min ( dist[ n ][ 0 ] , dist[ n ][ 1 ] ) ;
        ans = ( pw[ ret.first ] + ret.second ) % MOD ;
        ans = ( ans + MOD - 1 ) % MOD ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}