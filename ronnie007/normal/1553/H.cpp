#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1100007

int n , k ;
int a[ MAXN ] ;

struct tuhla {
    int mn , mx , ans ;
    tuhla ( ) { mn = mx = ans = 0 ; }
    tuhla ( int _mn , int _mx , int _ans ) {
         mn = _mn , mx = _mx , ans = _ans ;
    }
};

int lvl[ MAXN ] ;
bool act[ 4 * MAXN ] ;
vector < tuhla > v[ 4 * MAXN ] ;

void add ( int x ) {
    int where = 1 ;
    act[ where ] = true ;
    for ( int i = k - 1 ; i >= 0 ; -- i ) {
        lvl[ where ] = i ;
        where *= 2 ;
        if ( ( x & ( 1 << i ) ) > 0 ) { ++ where ; }
        act[ where ] = true ;
    }
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        add ( a[ i ] ) ;
    }
}

void solve ( ) {
    int lim = ( 1 << ( k + 1 ) ) - 1 ;
    for ( int i = lim ; i >= 1 ; -- i ) {
        if ( act[ i ] == false ) { continue ; }
        if ( 2 * i > lim ) {
            v[ i ].push_back ( tuhla ( 0 , 0 , MAXN ) ) ;
            continue ;
        }
        int add = ( 1 << lvl[ i ] ) ;
        if ( act[ 2 * i ] == true && act[ 2 * i + 1 ] == false ) {
            for ( auto e : v[ 2 * i ] ) {
                v[ i ].push_back ( e ) ;
            }
            for ( auto [ mn , mx , ans ] : v[ 2 * i ] ) {
                v[ i ].push_back ( tuhla ( mn + add , mx + add , ans ) ) ;
            }
            continue ;
        }
        if ( act[ 2 * i ] == false && act[ 2 * i + 1 ] == true ) {

            for ( auto [ mn , mx , ans ] : v[ 2 * i + 1 ] ) {

                v[ i ].push_back ( tuhla ( mn + add , mx + add , ans ) ) ;
            }
            for ( auto e : v[ 2 * i + 1 ] ) {
                v[ i ].push_back ( e ) ;
            }
            continue ;
        }
        int sz = v[ 2 * i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int init = min ( v[ 2 * i ][ j ].ans , v[ 2 * i + 1 ][ j ].ans ) ;
            v[ i ].push_back ( { v[ 2 * i ][ j ].mn , add + v[ 2 * i + 1 ][ j ].mx , min ( init , add + v[ 2 * i + 1 ][ j ].mn - v[ 2 * i ][ j ].mx ) } ) ;
        }
        for ( int j = 0 ; j < sz ; ++ j ) {
            int init = min ( v[ 2 * i ][ j ].ans , v[ 2 * i + 1 ][ j ].ans ) ;
            v[ i ].push_back ( { v[ 2 * i + 1 ][ j ].mn , add + v[ 2 * i ][ j ].mx , min ( init , add + v[ 2 * i ][ j ].mn - v[ 2 * i + 1 ][ j ].mx ) } ) ;
        }
    }

    for ( int i = 0 ; i < ( 1 << k ) ; ++ i ) {
        cout << v[ 1 ][ i ].ans << " " ;
    }
    cout << "\n" ;
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