#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007

int n ;
struct tuhla {
    long long x , y ;
};

tuhla a[ MAXN ] ;
bool done[ MAXN ] ;

int ord[ MAXN ] ;

long long dist ( tuhla p1 , tuhla p2 ) {
    return ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y ) ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].x >> a[ i ].y ;
    }
}


void solve ( ) {
    ord[ 1 ] = 1 ; done[ 1 ] = true ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        long long sr = -1 ;
        int id = -1 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( done[ j ] == true ) { continue ; }
            long long aux = dist ( a[ ord[ i - 1 ] ] , a[ j ] ) ;
            if ( aux > sr ) {
                sr = aux ; id = j ;
            }
        }
        ord[ i ] = id ; done[ id ] = true ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ord[ i ] << " " ;
    }
    cout << "\n" ;
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