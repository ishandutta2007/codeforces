#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , k ;
int val[ MAXN ] ;
vector < int > v[ MAXN ] ;

int coef[ MAXN ] ;
int subtree[ MAXN ] ;
int good[ MAXN ] ;
int up[ MAXN ] ;

void init ( int vertex , int prv ) {
    subtree[ vertex ] = 1 ;
    good[ vertex ] = coef[ vertex ] ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        init ( x , vertex ) ;
        subtree[ vertex ] += subtree[ x ] ;
        good[ vertex ] += good[ x ] ;
    }
}

void calc_up ( int vertex , int prv , int hh ) {
    int tot = coef[ vertex ] ;
    up[ vertex ] = hh ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        tot += good[ x ] ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        calc_up ( x , vertex , hh + tot - good[ x ] ) ;
    }
}

int dp[ MAXN ] ;

bool dfs ( int vertex , int prv ) {
    dp[ vertex ] = 0 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        if ( dfs ( x , vertex ) == true ) { return true ; }
    }
    if ( coef[ vertex ] == 1 ) {
        int tot = 0 ;
        int add = 0 ;
        if ( up[ vertex ] == n - subtree[ vertex ] ) { add = up[ vertex ] ; }
        for ( auto x : v[ vertex ] ) {
            if ( x == prv ) { continue ; }
            if ( subtree[ x ] == good[ x ] ) { tot += good[ x ] ; }
        }
        dp[ vertex ] = tot + 1 ;
        int mx1 , mx2 ;
        mx1 = mx2 = 0 ;
        for ( auto x : v[ vertex ] ) {
            if ( x == prv ) { continue ; }
            int aux = dp[ x ] ;
            if ( subtree[ x ] == good[ x ] ) { aux -= good[ x ] ; }
            if ( mx1 < aux ) { mx2 = mx1 ; mx1 = aux ; }
            else if ( mx2 < aux ) { mx2 = aux ; }
        }
        dp[ vertex ] += mx1 ;
        if ( dp[ vertex ] + mx2 + add >= k ) { return true ; }
    }
    return false ;
}

bool f ( int sr ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        coef[ i ] = ( val[ i ] >= sr ) ;
    }
    init ( 1 , -1 ) ;
    calc_up ( 1 , -1 , 0 ) ;

    return dfs ( 1 , -1 ) ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &val[ i ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    int l , r , mid ;
    l = 0 ; r = 1000000 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    while ( f ( r ) == false ) { -- r ; }
    printf ( "%d\n" , r ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}