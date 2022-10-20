#include<bits/stdc++.h>
using namespace std ;

#define MAXN 3007

long long inf ;
int n , k ;
int f[ MAXN ] ;
vector < int > v[ MAXN ] ;

pair < int , long long > dp[ MAXN ][ MAXN ] ;

pair < int , long long > nw[ MAXN ] ;
int subtree[ MAXN ] ;

void upd ( pair < int , long long > &w , pair < int , long long > sr ) {
    if ( w.first < sr.first ) {
        w = sr ;
        return ;
    }
    if ( w.first == sr.first && w.second < sr.second ) {
        w = sr ;
    }
}

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        if ( h == prv ) { continue ; }
        dfs ( h , vertex ) ;
        for ( int j = 0 ; j <= subtree[ vertex ] + subtree[ h ] ; ++ j ) {
            nw[ j ] = { - MAXN , - inf } ;
        }
        for ( int j = 0 ; j < subtree[ vertex ] ; ++ j ) {
            for ( int t = 0 ; t <= subtree[ h ] ; ++ t ) {
                pair < int , long long > sr =
                    { dp[ vertex ][ j ].first + dp[ h ][ t ].first , dp[ vertex ][ j ].second + dp[ h ][ t ].second } ;
                upd ( nw[ j + t ] , sr ) ;
                                              
            }
        }
        subtree[ vertex ] += subtree[ h ] ;
        if ( subtree[ vertex ] > k ) { subtree[ vertex ] = k ; }
        for ( int j = 0 ; j < subtree[ vertex ] ; ++ j ) {
            dp[ vertex ][ j ] = nw[ j ] ;
        }
    }
    for ( int i = 0 ; i < subtree[ vertex ] ; ++ i ) {
        dp[ vertex ][ i ].second += f[ vertex ] ;
    }
    dp[ vertex ][ subtree[ vertex ] ] = { - MAXN , - inf } ;
    for ( int i = subtree[ vertex ] ; i >= 1 ; -- i ) {
        pair < int , long long > sr = dp[ vertex ][ i - 1 ] ;
        if ( sr.second > 0 ) { ++ sr.first ; }
        sr.second = 0 ;
        upd ( dp[ vertex ][ i ] , sr ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &f[ i ] ) ;
        f[ i ] = -f[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        f[ i ] += x ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        for ( int j = 0 ; j <= k ; ++ j ) {
            dp[ i ][ j ] = { - MAXN , - inf } ;
        }
        dp[ i ][ 0 ] = { 0 , 0 } ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    printf ( "%d\n" , dp[ 1 ][ k ].first ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    inf = 1 ;
    for ( int i = 1 ; i <= 13 ; ++ i ) {
        inf *= 10 ;
    }
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}