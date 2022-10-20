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

#define MAXN 500007
#define inf (1LL<<60)
#define eps 0.0001

namespace cht {
    int sz = 0 ;
    pair < long long , long long > lines[ MAXN ] ;
    long long frm[ MAXN ] ;
    void reset ( ) {
        sz = 0 ;
    }
    long long intersect ( pair < long long , long long > p1 , pair < long long , long long > p2 ) {
        if ( p1.first == p2.first ) {
            if ( p1.second < p2.second ) { return inf ; }
            return -inf ;
        }
        long long h1 = ( p2.second - p1.second )  ;
        long long h2 = ( p1.first - p2.first ) ;
        if ( ( h1 % h2 ) == 0 ) { return ( h1 / h2 ) ; }
        return ( h1 / h2 + 1 ) ;
    }
    void add_line ( long long coef , long long add ) {
        if ( sz >= 1 && lines[ sz - 1 ].first == coef && lines[ sz - 1 ].second < add ) { return ; }
        while ( sz >= 1 ) {
            if ( intersect ( lines[ sz - 1 ] , { coef , add } ) < frm[ sz - 1 ] ) {
                -- sz ;
            }
            else { break ; }
        }
        lines[ sz ++ ] = { coef , add } ;
        if ( sz > 1 ) {
            frm[ sz - 1 ] = intersect ( lines[ sz - 2 ] , lines[ sz - 1 ] ) ;
        }
        else { frm[ sz - 1 ] = -inf ; }
    }
    long long get_val ( long long pos ) {
        if ( sz == 0 ) { return inf ; }
        int l , r , mid ;
        l = 0 ;
        r = ( sz - 1 ) ;
        while ( r - l > 2 ) {
            mid = ( l + r ) / 2 ;
            if ( frm[ mid ] <= pos ) { l = mid ; }
            else { r = mid ; }
        }
        while ( frm[ r ] > pos ) { -- r ; }
        return lines[ r ].first * pos + lines[ r ].second ;
    }
}

int n ;
vector < int > v[ MAXN ] ;
long long subtree[ MAXN ] ;
long long mnchain[ MAXN ] ;

long long ans = -1 ;

void init ( int where , int prv ) {
    int sz = v[ where ].size ( ) ;
    subtree[ where ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ where ][ i ] == prv ) { continue ; }
        init ( v[ where ][ i ] , where ) ;
        subtree[ where ] += subtree[ v[ where ][ i ] ] ;
    }
}

void dfs ( int where , int prv ) {
    int sz = v[ where ].size ( ) ;
    mnchain[ where ] = -1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ where ][ i ] == prv ) { continue ; }
        dfs ( v[ where ][ i ] , where ) ;
        long long aux = mnchain[ v[ where ][ i ] ] +
            1LL * ( subtree[ where ] - subtree[ v[ where ][ i ] ] ) *
            ( subtree[ where ] - subtree[ v[ where ][ i ] ] - 1 ) / 2 ;

        if ( mnchain[ where ] == -1 || mnchain[ where ] > aux ) {
            mnchain[ where ] = aux ;
        }
        long long f = mnchain[ v[ where ][ i ] ] +
            1LL * ( n - subtree[ v[ where ][ i ] ] ) *
            ( n - subtree[ v[ where ][ i ] ] - 1 ) / 2 ;

        if ( ans > f || ans == -1 ) { ans = f ; }
    }
    if ( mnchain[ where ] == -1 ) {
        mnchain[ where ] = 0 ;
    }
    vector < int > aux = v[ where ] ;
    auto cmp = [](int x , int y ) {
        return subtree[ x ] > subtree[ y ] ;
    };
    sort ( aux.begin ( ) , aux.end ( ) , cmp ) ;
    int hh = aux.size ( ) ;
    for ( int i = 0 ; i < hh ; ++ i ) {
        if ( aux[ i ] == prv ) { continue ; }
        if ( i > 0 ) {
            long long ret = cht :: get_val ( subtree[ aux[ i ] ] ) ;
            long long sm = mnchain[ aux[ i ] ] + 1LL * n * ( n - 1 ) / 2 + 1LL * subtree[ aux[ i ] ]  * ( subtree[ aux[ i ] ] + 1 ) / 2 - 1LL * n * subtree[ aux[ i ] ] ;
            sm += ret ;
            if ( ans > sm || ans == -1 ) { ans = sm ; }
        }
        cht :: add_line ( subtree[ aux[ i ] ] ,
            mnchain[ aux[ i ] ] +
            1LL * subtree[ aux[ i ] ] * (  subtree[ aux[ i ] ] + 1 ) / 2 -
            1LL * n * subtree[ aux[ i ] ] ) ;
    }
    cht :: reset ( ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ; scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) , v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    init ( 1 , -1 ) ;
    dfs ( 1 , -1 ) ;
    long long tot = 1LL * n * ( n - 1 ) - ans ;
    printf ( "%I64d\n" , tot ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}