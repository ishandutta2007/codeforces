#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;

struct edge {
    int x , y ;
    int nw ;
    edge ( ) { x = y = nw = 0 ; }
    edge ( int _x , int _y , int _nw ) {
        x = _x ; y = _y ;
        nw = _nw ;
    }
};

vector < edge > ans ;
int used[ MAXN ] ;
int subtree[ MAXN ] ;
int mx_sub[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    subtree[ vertex ] = 1 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dfs ( x , vertex ) ;
        subtree[ vertex ] += subtree[ x ] ;
        mx_sub[ vertex ] = max ( mx_sub[ vertex ] , subtree[ x ] ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

vector < int > all ;
int par[ MAXN ] ;
int depth[ MAXN ] ;


void get_all ( int vertex , int prv ) {
    all.push_back ( vertex ) ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        depth[ x ] = depth[ vertex ] + 1 ;
        par[ x ] = vertex ;
        get_all ( x , vertex ) ;
    }
}

void calc ( int vertex , int ori ) {
    depth[ vertex ] = 0 ;
    all.clear ( ) ;
    get_all ( vertex , ori ) ;
    int lst = vertex ;
    for ( auto x : all ) {
        if ( depth[ x ] <= 1 ) { continue ; }
        ans.push_back ( edge ( ori , lst , x ) ) ;
        ans.push_back ( edge ( x , par[ x ] , vertex ) ) ;
        lst = x ;
    }
    if ( lst != vertex ) {
        ans.push_back ( edge ( ori , lst , vertex ) ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    vector < int > aux ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( 2 * max ( mx_sub[ i ] , n - subtree[ i ] ) <= n ) {
            aux.push_back ( i ) ;
            used[ i ] = 1 ;
        }
    }
    for ( auto x : aux ) {
        for ( auto y : v[ x ] ) {
            if ( used[ y ] == 0 ) {
                calc ( y , x ) ;
            }
        }
    }
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d %d\n" , ans[ i ].x , ans[ i ].y , ans[ i ].nw ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}