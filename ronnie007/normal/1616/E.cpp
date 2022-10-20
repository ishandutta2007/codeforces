#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 100007

int n ;
string a , b ;

queue < int > q[ 26 ] ;



class fenwick {
public :
    int tr[ MAXN ] ;
    void init ( ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            tr[ i ] = 0 ;
        }
    }
    void update ( int x ) {
        for ( int i = x ; i >= 1 ; i -= ( i & (-i) ) ) {
            ++ tr[ i ] ;
        }
    }
    int query ( int x ) {
        int ret = 0 ;
        for ( int i = x ; i <= n ; i += ( i & (-i) ) ) {
            ret += tr[ i ] ;
        }
        return ret ;
    }
};

fenwick w ;

void input ( ) {
    cin >> n ;
    cin >> a >> b ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        while ( q[ i ].empty ( ) == false ) { q[ i ].pop ( ) ; }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        q[ a[ i ] - 'a' ].push ( i + 1 ) ;
    }
}

void solve ( ) {
    w.init ( ) ;
    long long ans = -1 ;
    long long sm = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int aux = b[ i ] - 'a' ;
        int mnpos = n + 1 ;
        for ( int j = 0 ; j < aux ; ++ j ) {
            if ( q[ j ].empty ( ) == true ) { continue ; }
            mnpos = min ( mnpos , q[ j ].front ( ) ) ;
        }
        if ( mnpos != n + 1 ) {
            int act = mnpos + w.query ( mnpos ) ;
            long long cand = sm + act - ( i + 1 ) ;
            if ( ans < 0 || ans > cand ) { ans = cand ; }
        }

        if ( q[ aux ].empty ( ) == true ) { break ; }
        int x = q[ aux ].front ( ) ;
        q[ aux ].pop ( ) ;
        int act = x + w.query ( x ) ;
        sm += act - ( i + 1 ) ;
        w.update ( x ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}