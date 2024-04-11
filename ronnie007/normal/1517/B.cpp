#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n , m ;

int a[ MAXN ][ MAXN ] ;
int wh[ MAXN ][ MAXN ] ;

bool done[ MAXN ] ;

struct tuhla {
    int x , y , val ;
    tuhla ( ) { x = y = val = 0 ; }
    tuhla ( int _x , int _y , int _val ) {
        x = _x ; y = _y ; val = _val ;
    }
};
vector < tuhla > v ;

int ans[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    v.clear ( ) ;
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        for ( int j = 0 ; j < MAXN ; ++ j ) {
            ans[ i ][ j ] = 0 ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> a[ i ][ j ] ;
            wh[ i ][ j ] = 0 ;
            v.push_back ( tuhla ( i , j , a[ i ][ j ] ) ) ;
        }
    }
    auto cmp = [ & ] ( tuhla p1 , tuhla p2 ) {
        return ( p1.val < p2.val ) ;
    };
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
}

void solve ( ) {
    for ( int i = 0 ; i < m ; ++ i ) {
        wh[ v[ i ].x ][ v[ i ].y ] = i + 1 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            done[ j ] = false ;
        }
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( wh[ i ][ j ] > 0 ) {
                done[ wh[ i ][ j ] ] = true ;
            }
        }
        int pos = 1 ;
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( wh[ i ][ j ] > 0 ) { continue ; }
            while ( done[ pos ] == true ) { ++ pos ; }
            done[ pos ] = true ;
            wh[ i ][ j ] = pos ;
        }
        for ( int j = 1 ; j <= m ; ++ j ) {
            ans[ i ][ wh[ i ][ j ] ] = a[ i ][ j ] ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cout << ans[ i ][ j ] << " " ;
        }
        cout << "\n" ;
    }
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
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