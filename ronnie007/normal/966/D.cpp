#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 300007

int n , m ;
vector < int > v[ MAXN ] ;
bool fl[ MAXN ] ;

int dist[ MAXN ] ;
int prv[ MAXN ] ;

int cnt_v , cnt_e ;
vector < int > comp ;

void bfs ( int ori ) {
    queue < int > q ;
    dist[ ori ] = 0 ;
    q.push ( ori ) ;
    cnt_v = cnt_e = 0 ;
    comp.clear ( ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        comp.push_back ( x ) ;
        ++ cnt_v ;
        for ( auto y : v[ x ] ) {
            if ( ori != 1 && y == 1 ) { continue ; }
            ++ cnt_e ;
            if ( dist[ y ] == MAXN ) {
                dist[ y ] = dist[ x ] + 1 ;
                prv[ y ] = x ;
                q.push ( y ) ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( auto x : v[ 1 ] ) { fl[ x ] = true ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ i ] = MAXN ;
        prv[ i ] = -1 ;
    }
    bfs ( 1 ) ;
    if ( dist[ n ] <= 4 ) {
        printf ( "%d\n" , dist[ n ] ) ;
        vector < int > ret ;
        int x = n ;
        while ( x > 0 ) {
            ret.push_back ( x ) ;
            x = prv[ x ] ;
        }
        for ( auto it = ret.rbegin ( ) ; it != ret.rend ( ) ; ++ it ) {
            printf ( "%d " , (*it ) ) ;
        }
        printf ( "\n" ) ;
        return ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( dist[ i ] == 2 ) {
            printf ( "4\n" ) ;
            printf ( "1 %d %d 1 %d\n" , prv[ i ] , i , n ) ;
            return ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ i ] = MAXN ;
        prv[ i ] = -1 ;
    }
    for ( auto x : v[ 1 ] ) {
        if ( dist[ x ] == MAXN ) {
            bfs ( x ) ;
            if ( 1LL * cnt_v * ( cnt_v - 1 ) == cnt_e ) { continue ; }
            int ori = 0 ;
            for ( auto i : comp ) {
                if ( v[ i ].size ( ) - fl[ i ] < cnt_v - 1 ) {
                    ori = i ;
                    break ;
                }
            }
            for ( auto i : comp ) { dist[ i ] = MAXN ; }
            bfs ( ori ) ;
            for ( auto i : comp ) {
                if ( dist[ i ] == 2 ) {
                    printf ( "5\n" ) ;
                    printf ( "1 %d %d %d %d %d\n" , ori , prv[ i ] , i , ori , n ) ;
                    return ;
                }
            }
        }
    }
    printf ( "-1\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}