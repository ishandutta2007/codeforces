#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
vector < pair < int , int > > v[ MAXN ] ;

int mxdepth[ MAXN ] ;
int up[ MAXN ] ;
int dp[ MAXN ] ;


void dfs_down ( int vertex , int prv ) {
    for ( auto [ x , y ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dfs_down ( x , vertex ) ;
        mxdepth[ vertex ] = max ( mxdepth[ vertex ] , mxdepth[ x ] + y ) ;
    }
}

void dfs_up ( int vertex , int prv ) {
    int cand1 , id1 ;
    int cand2 , id2 ;
    cand1 = id1 = cand2 = id2 = 0 ;
    for ( auto [ x , y ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        int sr = mxdepth[ x ] + y ;
        if ( cand1 < sr ) {
            cand2 = cand1 ; id2 = id1 ;
            cand1 = sr ; id1 = x ;
        }
        else if ( cand2 < sr ) {
            cand2 = sr ; id2 = x ;
        }
    }
    for ( auto [ x , y ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        up[ x ] = up[ vertex ] + y ;
        if ( x == id1 ) {
            up[ x ] = max ( up[ x ] , cand2 + y ) ;
        }
        else {
            up[ x ] = max ( up[ x ] , cand1 + y ) ;
        }
        dfs_up ( x , vertex ) ;
    }
}

void calc_dp ( int vertex , int prv , int sr ) {
    for ( auto [ x , y ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        calc_dp ( x , vertex , sr ) ;
    }
    if ( mxdepth[ vertex ] <= sr ) {
        dp[ vertex ] = 1 ;
        return ;
    }
    int cnt = 0 ;
    int id = 0 ;
    for ( auto [ x , y ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        if ( dp[ x ] == -1 ) { dp[ vertex ] = -1 ; return ; }
        if ( mxdepth[ x ] + y > sr ) {
            ++ cnt ;
            id = x ;
            if ( cnt == 2 ) {
                dp[ vertex ] = -1 ;
                return ;
            }
        }
    }
    dp[ vertex ] = dp[ id ] + 1 ;
}

bool check ( int vertex , int prv , int sr ) {
    if ( up[ vertex ] > sr ) { return false ; }
    for ( auto [ x , y ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        if ( check ( x , vertex , sr ) == true ) { return true ; }
    }
    int cnt = 0 ;
    int sm = 1 ;
    for ( auto [ x , y ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        if ( mxdepth[ x ] + y <= sr ) { continue ; }
        if ( dp[ x ] == -1 ) { return false ; }
        ++ cnt ;
        sm += dp[ x ] ;
        if ( cnt > 2 || sm > k ) { return false ; }
    }
    return true ;
}


bool f ( int sr ) {
    calc_dp ( 1 , -1 , sr ) ;
    return check ( 1 , -1 , sr ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( { y , z } ) ;
        v[ y ].push_back ( { x , z } ) ;
    }
}

void solve ( ) {
    dfs_down ( 1 , -1 ) ;
    dfs_up ( 1 , -1 ) ;
    int l , r , mid ;
    l = 0 ; r = 1e9 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { ++ l ; }
    printf ( "%d\n" , l ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}