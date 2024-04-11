#include<bits/stdc++.h>
using namespace std ;

#define MAXN 307

int n ;
pair < int , int > a[ MAXN ] ;

long long dp[ MAXN ][ MAXN ][ 6 ] ;

struct edge {
    int x , y ;
    double ang ;
    edge ( ) { x = y = ang = 0 ; }
    edge ( int _x , int _y , double _ang ) {
        x = _x , y = _y ;
        ang = _ang ;
    }
};


vector < edge > v ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( i == j ) { continue ; }
            v.push_back ( edge ( i , j , atan2 ( a[ j ].second - a[ i ].second , a[ j ].first - a[ i ].first ) ) ) ;
        }
    }
    auto cmp = [ & ] ( edge p1 , edge p2 ) {
        return ( p1.ang < p2.ang ) ;
    };
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ i ][ i ][ 0 ] = 1 ;
    }

    for ( auto e : v ) {
        for ( int len = 4 ; len >= 0 ; -- len ) {
            for ( int i = 1 ; i <= n ; ++ i ) {
                dp[ i ][ e.y ][ len + 1 ] += dp[ i ][ e.x ][ len ] ;
            }
        }
    }
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += dp[ i ][ i ][ 5 ] ;
    }
    printf ( "%lld\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}