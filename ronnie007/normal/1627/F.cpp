#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 100007
#define MAXK 507

int n , k ;
struct eq {
    int a , b , c , d ;
};
eq w[ MAXN ] ;

int cnt_left[ MAXK ][ MAXK ] ;
int cnt_up[ MAXK ][ MAXK ] ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> w[ i ].a >> w[ i ].b >> w[ i ].c >> w[ i ].d ;
        -- w[ i ].a , -- w[ i ].b , -- w[ i ].c , -- w[ i ].d ;
    }
    for ( int i = 0 ; i <= k + 1 ; ++ i ) {
        for ( int j = 0 ; j <= k + 1 ; ++ j ) {
            cnt_left[ i ][ j ] = cnt_up[ i ][ j ] = 0 ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( w[ i ].a == w[ i ].c ) {
            if ( w[ i ].b > w[ i ].d ) {
                swap ( w[ i ].b , w[ i ].d ) ;
            }
            ++ cnt_up[ w[ i ].a ][ w[ i ].d ] ;
            ++ cnt_up[ k - w[ i ].a - 1 ][ k - w[ i ].d ] ;
        }
        else {
            if ( w[ i ].a > w[ i ].c ) {
                swap ( w[ i ].a , w[ i ].c ) ;
            }
            ++ cnt_left[ w[ i ].c ][ w[ i ].b ] ;
            ++ cnt_left[ k - w[ i ].c ][ k - w[ i ].b - 1 ] ;
        }
    }
}
int dist[ MAXK ][ MAXK ] ;

priority_queue < pair < int , pair < int , int > > > q ;

void solve ( ) {
    for ( int i = 0 ; i <= k ; ++ i ) {
        for ( int j = 0 ; j <= k ; ++ j ) {
            dist[ i ][ j ] = n + 2 ;
        }
    }
    dist[ 0 ][ 0 ] = 0 ;
    q.push ( { 0 , { 0 , 0 } } ) ;
    while ( q.empty ( ) == false ) {
        auto e = q.top ( ) ;
        int cost = -e.first , x = e.second.first , y = e.second.second ;
        q.pop ( ) ;
        if ( cost != dist[ x ][ y ] ) { continue ; }
        if ( x > 1 && dist[ x - 1 ][ y ] > dist[ x ][ y ] + cnt_up[ x - 1 ][ y ] ) {
            dist[ x - 1 ][ y ] = dist[ x ][ y ] + cnt_up[ x - 1 ][ y ] ;
            q.push ( { -dist[ x - 1 ][ y ] , { x - 1 , y } } ) ;
        }
        if ( x < k && dist[ x + 1 ][ y ] > dist[ x ][ y ] + cnt_up[ x ][ y ] ) {
            dist[ x + 1 ][ y ] = dist[ x ][ y ] + cnt_up[ x ][ y ] ;
            q.push ( { -dist[ x + 1 ][ y ] , { x + 1 , y } } ) ;
        }
        if ( y > 1 && dist[ x ][ y - 1 ] > dist[ x ][ y ] + cnt_left[ x ][ y - 1 ] ) {
            dist[ x ][ y - 1 ] = dist[ x ][ y ] + cnt_left[ x ][ y - 1 ] ;
            q.push ( { -dist[ x ][ y - 1 ] , { x , y - 1 } } ) ;
        }
        if ( y < k && dist[ x ][ y + 1 ] > dist[ x ][ y ] + cnt_left[ x ][ y ] ) {
            dist[ x ][ y + 1 ] = dist[ x ][ y ] + cnt_left[ x ][ y ] ;
            q.push ( { -dist[ x ][ y + 1 ] , { x , y + 1 } } ) ;
        }
    }
    cout << n - dist[ ( k / 2 ) ][ ( k / 2 ) ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}