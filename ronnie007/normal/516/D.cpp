#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define LOG 19


int n ;
long long dp[ MAXN ] ;

vector < pair < int , int > > v[ MAXN ] ;

int LCA[ MAXN ][ LOG ] ;

int coef[ MAXN ] ;
int max_ans ;

void init_down ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int c = v[ vertex ][ i ].second ;
        if ( h == prv ) { continue ; }
        init_down ( h , vertex ) ;
        dp[ vertex ] = max ( dp[ vertex ] , dp[ h ] + c ) ;
    }
}

void init_up ( int vertex , int prv , long long up ) {
    dp[ vertex ] = max ( dp[ vertex ] , up ) ;
    int sz = v[ vertex ].size ( ) ;
    long long mx1 = 0 ; int id = 0 ;
    long long mx2 = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int c = v[ vertex ][ i ].second ;
        if ( h == prv ) { continue ; }
        if ( mx1 < dp[ h ] + c ) {
            mx1 = dp[ h ] + c ; id = h ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int c = v[ vertex ][ i ].second ;
        if ( h == prv || h == id ) { continue ; }
        if ( mx2 < dp[ h ] + c ) {
            mx2 = dp[ h ] + c ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int c = v[ vertex ][ i ].second ;
        if ( h == prv ) { continue ; }
        if ( h != id ) {
            init_up ( h , vertex , max ( up , mx1 ) + c ) ;
        }
        else {
            init_up ( h , vertex , max ( up , mx2 ) + c ) ;
        }
    }
}

void init_lca ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    if ( prv != -1 ) {
        for ( int i = 1 ; i < LOG ; ++ i ) {
            LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int c = v[ vertex ][ i ].second ;
        if ( h == prv ) { continue ; }
        LCA[ h ][ 0 ] = vertex ;
        init_lca ( h , vertex ) ;
    }
}

void dfs ( int vertex , int prv , long long sr ) {
    int sz = v[ vertex ].size ( ) ;
    int aux = vertex ;
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( LCA[ aux ][ i ] != 0 ) {
            if ( dp[ vertex ] - dp[ LCA[ aux ][ i ] ] <= sr ) {
                aux = LCA[ aux ][ i ] ;
            }
        }
    }
    -- coef[ LCA[ aux ][ 0 ] ] ;
    ++ coef[ vertex ] ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        if ( h == prv ) { continue ; }
        dfs ( h , vertex , sr ) ;
    }
}

void suffix_close ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        if ( h == prv ) { continue ; }
        suffix_close ( h , vertex ) ;
        coef[ vertex ] += coef[ h ] ;
    }
    max_ans = max ( max_ans , coef[ vertex ] ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( { y , z } ) ;
        v[ y ].push_back ( { x , z } ) ;
    }
}

void solve ( ) {
    init_down ( 1 , -1 ) ;
    init_up ( 1 , -1 , 0 ) ;

    int root = 1 ;
    long long mn = dp[ 1 ] ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mn > dp[ i ] ) {
            mn = dp[ i ] ; root = i ;
        }
    }
    init_lca ( root , -1 ) ;
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        long long x ;
        scanf ( "%I64d" , &x ) ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            coef[ i ] = 0 ;
        }
        max_ans = 0 ;
        dfs ( root , -1 , x ) ;
        suffix_close ( root , -1 ) ;
        printf ( "%d\n" , max_ans ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}