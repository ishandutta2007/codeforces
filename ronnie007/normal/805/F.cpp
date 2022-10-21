#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 100007

int n , m , q ;
vector < int > v[ MAXN ] ;

int prv[ MAXN ] ;

int dist[ MAXN ] ;

int diam[ MAXN ] ;
int r[ MAXN ] ;
int compsz[ MAXN ] ;
vector < int > srt[ MAXN ] ;
vector < long long > pref[ MAXN ] ;

map < pair < int , int > , double > ZX ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    prv[ k1 ] = k2 ;
}

int bfs ( int vertex ) {
    queue < int > q ;
    vector < int > vis ;
    dist[ vertex ] = 0 ;
    q.push ( vertex ) ;
    int i ;
    while ( q.empty ( ) == false ) {
        int u = q.front ( ) ;
        vis.push_back ( u ) ;
        r[ u ] = max ( r[ u ] , dist[ u ] ) ;
        q.pop ( ) ;
        int sz = v[ u ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
            int h = v[ u ][ i ] ;
            if ( dist[ h ] == 0 && h != vertex ) {
                q.push ( h ) ;
                dist[ h ] = dist[ u ] + 1 ;
            }
        }
    }
    int sz = vis.size ( ) ;
    int compid = find ( vertex ) ;
    srt[ compid ].clear ( ) ;
    compsz[ compid ] = sz ;
    int mx = 0 ;
    int id = vertex ;
    for ( i = 0 ; i < sz ; i ++ ) {
        srt[ compid ].push_back ( r[ vis[ i ] ] ) ;
        if ( dist[ vis[ i ] ] > mx ) {
            mx = dist[ vis[ i ] ] ;
            id = vis[ i ] ;
        }
        dist[ vis[ i ] ] = 0 ;
    }
    return id ;
}

void calc_diam ( int vertex ) {
    int h = bfs ( vertex ) ;
    int u = bfs ( h ) ;
    bfs ( u ) ;
    diam[ vertex ] = r[ u ] ;
    sort ( srt[ vertex ].begin ( ) , srt[ vertex ].end ( ) ) ;
    int sz = srt[ vertex ].size ( ) ;
    pref[ vertex ].resize ( sz + 1 ) ;
    pref[ vertex ][ 0 ] = 0 ;
    int i ;
    for ( i = 1 ; i <= sz ; i ++ ) {
        pref[ vertex ][ i ] = pref[ vertex ][ i - 1 ] + srt[ vertex ][ i - 1 ] ;
    }
}

double calc ( int x , int y ) {
    int i ;
    long long totbr = 1LL * compsz[ x ] * compsz[ y ] ;
    int sz1 , sz2 ;
    sz1 = srt[ x ].size ( ) ;
    sz2 = srt[ y ].size ( ) ;
    long long br = 0 ;
    long long sm = 0 ;
    int j = sz2 - 1 ;
    long long sr = max ( diam[ x ] , diam[ y ] ) ;
    for ( i = 0 ; i < sz1 ; i ++ ) {
        int lo , hi , mid ;
        lo = 0 ;
        hi = sz2 -1 ;
        while ( hi - lo > 3 ) {
            mid = ( lo + hi ) / 2 ;
            if ( srt[ x ][ i ] + srt[ y ][ mid ] + 1 >= sr ) {
                hi = mid ;
            }
            else {
                lo = mid ;
            }
        }
        while ( hi >= 0 && srt[ x ][ i ] + srt[ y ][ hi ] + 1 >= sr ) { hi -- ; }
        // 0 -- j incl.
        br += ( hi + 1 ) ;
        // j + 1 -- sz2 - 1 incl
        sm += pref[ y ][ sz2 ] - pref[ y ][ hi + 1 ] ;
        sm += 1LL * ( sz2 - hi - 1 ) * ( srt[ x ][ i ] + 1 ) ;
    }
    br *= sr ;
    double totval = br + sm ;
    totval /= totbr ;
    return totval ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        prv[ i ] = -1 ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        UNITE ( x , y ) ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( prv[ i ] == -1 ) {
            calc_diam ( i ) ;
        }
    }
    int x , y ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%d%d" , &x , &y ) ;
        int k1 = find ( x ) ;
        int k2 = find ( y ) ;
        if ( compsz[ k1 ] > compsz[ k2 ] ) {
            swap ( k1 , k2 ) ;
        }
        if ( k1 == k2 ) {
            printf ( "-1\n" ) ;
            continue ;
        }
        else {
            if ( ZX.find ( make_pair ( k1 , k2 ) ) == ZX.end ( ) ) {
                double ret = calc ( k1 , k2 ) ;
                ZX[ make_pair ( k1 , k2 ) ] = ZX[ make_pair ( k2 , k1 ) ] = ret ;
            }
            printf ( "%.12lf\n" , ZX[ make_pair ( k1 , k2 ) ] ) ;
        }
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}