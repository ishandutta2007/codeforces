#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 1e5 + 7 ;

int n , m , k ;

struct event {
    int x , type ;
    int id ;
    event ( int _x , int _type , int _id ) {
        x = _x , type = _type , id = _id ;
    }
};
vector < event > v ;
int coord[ 2 * MAXN ] ;
int at_pos[ MAXN ] ;

int dp[ 2 ][ 307 ] ;
int cnt[ 307 ] ;

void solve ( ) {
    cin >> n >> m >> k ;
    for ( int i = 1 , l , r ; i <= n ; ++ i ) {
        cin >> l >> r ;
        v.push_back ( event ( l , 1 , i ) ) ;
        v.push_back ( event ( r + 1 , -1 , i ) ) ;
    }
    auto cmp = [ & ] ( event p1 , event p2 ) {
        if ( p1.x != p2.x ) { return ( p1.x < p2.x ) ; }
        if ( p1.type != p2.type ) { return ( p1.type < p2.type ) ; }
        return ( p1.id < p2.id ) ;
    };
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
    v.push_back ( event ( m + 1 , 0 , 0 ) ) ;
    int prv = 0 , nxt = 1 ;
    for ( int i = 0 ; i < ( 1 << k ) ; ++ i ) {
        int x = i ;
        while ( x > 0 ) {
            cnt[ i ] ^= 1 ;
            x = ( x & ( x - 1 ) ) ;
        }
    }
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < ( 1 << k ) ; ++ j ) {
            dp[ i ][ j ] = -1 ;
        }
    }
    dp[ prv ][ 0 ] = 0 ;
    int sz = v.size ( ) ;
    for ( int it = 0 ; it < sz - 1 ; ++ it ) {
        event p = v[ it ] ;
        if ( p.type == 1 ) {
            bool fl[ 8 ] ;
            for ( int i = 0 ; i < k ; ++ i ) { fl[ i ] = false ; }
            for ( int i = 0 ; i < ( 1 << k ) ; ++ i ) {
                if ( dp[ prv ][ i ] >= 0 ) {
                    for ( int j = 0 ; j < k ; ++ j ) {
                        if ( ( i & ( 1 << j ) ) > 0 ) { fl[ j ] = true ; }
                    }
                }
            }

            for ( int i = 0 ; i < k ; ++ i ) {
                if ( fl[ i ] == false ) {
                    at_pos[ p.id ] = i ;
                    break ;
                }
            }
        }
        int wh = at_pos[ p.id ] ;
        for ( int i = 0 ; i < ( 1 << k ) ; ++ i ) {
            if ( dp[ prv ][ i ] == -1 ) { continue ; }
            if ( p.type == 1 ) {
                if ( ( i & ( 1 << wh ) ) == 0 ) {
                    dp[ nxt ][ i + ( 1 << wh ) ] = max ( dp[ nxt ][ i + ( 1 << wh ) ] , dp[ prv ][ i ] + cnt[ i + ( 1 << wh ) ] * ( v[ it + 1 ].x - p.x ) ) ;
                }
                dp[ nxt ][ i ] = max ( dp[ nxt ][ i ] , dp[ prv ][ i ] + cnt[ i ] * ( v[ it + 1 ].x - p.x ) ) ;
            }
            else {
                if ( ( i & ( 1 << wh ) ) > 0 ) {
                    dp[ nxt ][ i - ( 1 << wh ) ] = max ( dp[ nxt ][ i - ( 1 << wh ) ] , dp[ prv ][ i ] + cnt[ i - ( 1 << wh ) ] * ( v[ it + 1 ].x - p.x ) ) ;
                }
                else {
                    dp[ nxt ][ i ] = max ( dp[ nxt ][ i ] , dp[ prv ][ i ] + cnt[ i ] * ( v[ it + 1 ].x - p.x ) ) ;
                }
            }
        }
        for ( int i = 0 ; i < ( 1 << k ) ; ++ i ) {
            dp[ prv ][ i ] = -1 ;
        }
        prv ^= 1 , nxt ^= 1 ;
    }
    cout << dp[ prv ][ 0 ] << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}