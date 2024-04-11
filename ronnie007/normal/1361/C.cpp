#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1500007
#pragma GCC optimize ("O3")

int n ;
pair < int , int > a[ MAXN ] ;
bool sw[ MAXN ] ;

int deg[ MAXN ] ;

vector < pair < int , int > > v[ MAXN ] ;

vector < int > path ;
int used[ MAXN ] ;
int edge[ MAXN ] ;

int list_sz[ MAXN ] ;

int prv[ MAXN ] ;

int tpid ;
vector < int > rem[ MAXN ] ;

int st_pos[ MAXN ] ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        prv[ k1 ] = k2 ;
    }
}

bool close ;
static void dfs ( int vertex , int st , int tpid ) {
    if ( close == true ) { return ; }
    int sz = list_sz[ vertex ] ;        
    for ( int i = st_pos[ vertex ] ; i < sz ; ++ i ) {
        st_pos[ vertex ] = i ;
        if ( edge[ v[ vertex ][ i ].second ] == 1 ) { continue ; }
        edge[ v[ vertex ][ i ].second ] = 1 ;
        -- deg[ vertex ] ;
        -- deg[ v[ vertex ][ i ].first ] ;
        rem[ tpid ].push_back ( v[ vertex ][ i ].second ) ;
        if ( v[ vertex ][ i ].first == st ) { close = true ; return ; }
        dfs ( v[ vertex ][ i ].first , st , tpid ) ;
        if ( close == true ) { return ; }
    }
}

vector < int > ord ;

bool f ( int sr ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ].first %= (1<<sr) ;
        a[ i ].second %= (1<<sr) ;
        deg[ a[ i ].first ] = deg[ a[ i ].second ] = 0 ;
        prv[ a[ i ].first ] = prv[ a[ i ].second ] = -1 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ++ deg[ a[ i ].first ] ;
        ++ deg[ a[ i ].second ] ;
        UNITE ( a[ i ].first , a[ i ].second ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( find ( a[ i ].first ) != find ( a[ 1 ].first ) ) { return false ; }
        if ( find ( a[ i ].second ) != find ( a[ 1 ].first ) ) { return false ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( deg[ a[ i ].first ] % 2 != 0 ) { return false ; }
        if ( deg[ a[ i ].second ] % 2 != 0 ) { return false ; }
    }
    return true ;
}

static void rec ( int id ) {
    int sz = rem[ id ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( i > 0 && a[ rem[ id ][ i ] ].first != a[ rem[ id ][ i - 1 ] ].second ) { sw[ rem[ id ][ i ] ] ^= 1 ; swap ( a[ rem[ id ][ i ] ].first , a[ rem[ id ][ i ] ].second ) ; }
        if ( sw[ rem[ id ][ i ] ] == false ) {
            printf ( "%d %d " , 2 * rem[ id ][ i ] - 1 , 2 * rem[ id ][ i ] ) ;
        }
        else {
            printf ( "%d %d " , 2 * rem[ id ][ i ] , 2 * rem[ id ][ i ] - 1 ) ;
        }
        while ( deg[ a[ rem[ id ][ i ] ].second ] > 0 ) {
            close = false ;
            //path.clear ( ) ;
            dfs ( a[ rem[ id ][ i ] ].second , a[ rem[ id ][ i ] ].second , ++ tpid ) ;
            if ( a[ rem[ tpid ][ 0 ] ].first != a[ rem[ id ][ i ] ].second ) {
                sw[ rem[ tpid ][ 0 ] ] ^= 1 ; swap ( a[ rem[ tpid ][ 0 ] ].first , a[ rem[ tpid ][ 0 ] ].second ) ;
            }
            // rem[ ++ tpid ] = path ;
            rec ( tpid ) ;
        }
    }    
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( ans = 20 ; ans >= 0 ; -- ans ) {
        if ( f ( ans ) == true ) { break ; }
    }
    printf ( "%d\n" , ans ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ a[ i ].first ].push_back ( { a[ i ].second , i } ) ;
        v[ a[ i ].second ].push_back ( { a[ i ].first , i } ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        list_sz[ a[ i ].first ] = v[ a[ i ].first ].size ( ) ;
        list_sz[ a[ i ].second ] = v[ a[ i ].second ].size ( ) ;        
    }
    close = false ;
    dfs ( a[ 1 ].first , a[ 1 ].first , ++ tpid ) ;
    // rem[ ++ tpid ] = path ;
    // path.clear ( ) ;
    rec ( tpid ) ;
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}