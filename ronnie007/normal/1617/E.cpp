#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007

int n ;
int a[ MAXN ] ;

int mx = 0 ;
pair < int , int > ans ;

map < int , int > w ;

struct el {
    int dist , ori , nxt ;
    el ( ) { dist = -1 ; ori = nxt = 0 ; }
    el ( int _dist , int _ori , int _nxt ) {
        dist = _dist , ori = _ori , nxt = _nxt ;
    }
};

el d[ 30 * MAXN ][ 2 ] ;

void update ( int wh , int val , int id , int nxt ) {
    if ( d[ wh ][ 0 ].nxt != nxt && d[ wh ][ 1 ].nxt != nxt ) {
        if ( d[ wh ][ 0 ].dist < val ) {
            d[ wh ][ 1 ] = d[ wh ][ 0 ] ;
            d[ wh ][ 0 ] = el ( val , id , nxt ) ;
        }
        else if ( d[ wh ][ 1 ].dist < val ) {
            d[ wh ][ 1 ] = el ( val , id , nxt ) ;
        }
    }
    else if ( d[ wh ][ 0 ].nxt == nxt ) {
        if ( d[ wh ][ 0 ].dist < val ) {
            d[ wh ][ 0 ].dist = val ;
            d[ wh ][ 0 ].ori = id ;
        }
    }
    else {
        if ( d[ wh ][ 1 ].dist < val ) {
            d[ wh ][ 1 ].dist = val ;
            d[ wh ][ 1 ].ori = id ;
        }
        if ( d[ wh ][ 1 ].dist > d[ wh ][ 0 ].dist ) {
            swap ( d[ wh ][ 0 ] , d[ wh ][ 1 ] ) ;
        }
    }
    if ( d[ wh ][ 1 ].ori != 0 ) {
        if ( mx < d[ wh ][ 0 ].dist + d[ wh ][ 1 ].dist ) {
            mx = d[ wh ][ 0 ].dist + d[ wh ][ 1 ].dist ;
            ans = { d[ wh ][ 0 ].ori , d[ wh ][ 1 ].ori } ;
        }
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        w[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    int tp = n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int st = 1 ;
        int x = a[ i ] ;
        while ( st < x ) { st *= 2 ; }
        int aux = 0 ;
        update ( i , 0 , i , -1 ) ;

        while ( x > 0 ) {
            while ( 2 * x <= st ) { st /= 2 ; }
            int nxt = st - x ;
            if ( w.find ( nxt ) == w.end ( ) ) {
                w[ nxt ] = ++ tp ;
            }
            ++ aux ;
            int wh = w[ nxt ] ;

            update ( wh , aux , i , x ) ;

            x = nxt ;
        }
    }
    cout << ans.first << " " << ans.second << " " << mx << "\n" ;
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