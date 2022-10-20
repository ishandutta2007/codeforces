#include<bits/stdc++.h>
using namespace std ;


// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 607

int n ;
vector < int > v[ MAXN ] ;

bool used[ MAXN ] ;
int col[ MAXN ] ;
int lst[ MAXN ] ;

int ask ( vector < int > &aux ) {
    int sz = aux.size ( ) ;
    if ( sz <= 1 ) { return 0 ; }
    printf ( "? %d\n" , sz ) ;
    fflush ( stdout ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d " , aux[ i ] ) ;
    }
    printf ( "\n" ) ;
    fflush ( stdout ) ;
    int ret ; scanf ( "%d" , &ret ) ;
    return ret ;
}

int proc ( vector < int > &v1 , vector < int > &v2 ) {
    int sz = v1.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) { v2.push_back ( v1[ i ] ) ; }
    int ret = ask ( v2 ) ;
    for ( int i = 0 ; i < sz ; ++ i ) { v2.pop_back ( ) ; }

    if ( v1.size ( ) > 1 ) { ret -= ask ( v1 ) ; }
    if ( v2.size ( ) > 1 ) { ret -= ask ( v2 ) ; }
    return ret ;
}
         
int get ( int vertex , vector < int > aux ) {
    if ( aux.size ( ) == 0 ) { return -1 ; }
    vector < int > dummy ;
    dummy.push_back ( vertex ) ;
    if ( proc ( dummy , aux ) == 0 ) { return -1 ; }
    
    int sz = aux.size ( ) ;
    while ( sz > 1 ) {
        int mid = sz / 2 ;
        vector < int > l , r ;
        for ( int i = 0 ; i < mid ; ++ i ) {
            l.push_back ( aux[ i ] ) ;
        }
        for ( int i = mid ; i < sz ; ++ i ) {
            r.push_back ( aux[ i ] ) ;
        }

        if ( proc ( dummy , l ) > 0 ) { aux = l ; }
        else { aux = r ; }

        sz = aux.size ( ) ;
    }
    return aux[ 0 ] ;
}


void dfs ( int vertex , int prv ) {
    while ( 1 ) {
        vector < int > aux ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( used[ i ] == false ) {
                aux.push_back ( i ) ;
            }
        }
        int ret = get ( vertex , aux ) ;
        if ( ret == -1 ) { break ; }
        used[ ret ] = true ;
        v[ vertex ].push_back ( ret ) ;
        v[ ret ].push_back ( vertex ) ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        col[ x ] = col[ vertex ] ^ 1 ;
        dfs ( x , vertex ) ;
    }
}


pair < int , int > obtain ( vector < int > aux ) {
    int sz = aux.size ( ) ;
    int l , r , mid ;
    l = 1 ; r = sz - 1 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        vector < int > nw ;
        for ( int i = 0 ; i < mid ; ++ i ) { nw.push_back ( aux[ i ] ) ; }

        if ( ask ( nw ) > 0 ) { r = mid ; }
        else { l = mid ; }
    }
    vector < int > nw ;
    while ( 1 ) {
        nw.clear ( ) ;
        for ( int i = 0 ; i < l ; ++ i ) { nw.push_back ( aux[ i ] ) ; }

        if ( ask ( nw ) > 0 ) { break ; }
        else { ++ l ; }
    }
    int hh = nw.back ( ) ;
    nw.pop_back ( ) ;
    return { hh , get ( hh , nw ) } ;
}

void mark ( int vertex , int prv ) {
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        lst[ x ] = vertex ;
        mark ( x , vertex ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    used[ 1 ] = true ;
    dfs ( 1 , -1 ) ;
    vector < int > v1 , v2 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( col[ i ] == 0 ) { v1.push_back ( i ) ; }
        else { v2.push_back ( i ) ; }
    }
    int ret1 = ask ( v1 ) ;
    int ret2 = ask ( v2 ) ;
    if ( ret1 == 0 && ret2 == 0 ) {
        printf ( "Y %d\n" , v2.size ( ) ) ;
        fflush ( stdout ) ;
        for ( auto x : v2 ) {
            printf ( "%d " , x ) ;
        }
        printf ( "\n" ) ;
        fflush ( stdout ) ;
        return ;
    }
    if ( ret2 == 0 ) { swap ( v1 , v2 ) ; }
    
    pair < int , int > bad = obtain ( v2 ) ;
    mark ( bad.first , -1 ) ;
    vector < int > ans ;
    int x = bad.second ;
    while ( x != 0 ) {
        ans.push_back ( x ) ;
        x = lst[ x ] ;
    }
    printf ( "N %d\n" , ans.size ( ) ) ;
    fflush ( stdout ) ;
    for ( auto x : ans ) {
        printf ( "%d " , x ) ;
    }
    printf ( "\n" ) ;
    fflush ( stdout ) ;
}


int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
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