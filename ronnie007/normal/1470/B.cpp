#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
int a[ MAXN ] ;
int eq[ MAXN ] ;


vector < int > v[ MAXN ] ;
bool pr[ MAXN ] ;

void init ( ) {
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        if ( pr[ i ] == true ) { continue ; }
        v[ i ].push_back ( i ) ;
        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            pr[ j ] = true ;
            int aux = 0 ;
            int dummy = j ;
            while ( dummy % i == 0 ) {
                dummy /= i ;
                aux ^= 1 ;
            }
            if ( aux == 1 ) {
                v[ j ].push_back ( i ) ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    auto cmp = [ & ] ( int x , int y ) {
        int sz1 = v[ x ].size ( ) ;
        int sz2 = v[ y ].size ( ) ;
        if ( sz1 != sz2 ) { return ( sz1 < sz2 ) ; }
        for ( int i = 0 ; i < sz1 ; ++ i ) {
            if ( v[ x ][ i ] != v[ y ][ i ] ) {
                return ( v[ x ][ i ] < v[ y ][ i ] ) ;
            }
        }
        return false ;
    };
    sort ( a + 1 , a + n + 1 , cmp ) ;
}

bool same ( int x , int y ) {
    if ( v[ x ].size ( ) != v[ y ].size ( ) ) { return false ; }
    int sz = v[ x ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ x ][ i ] != v[ y ][ i ] ) { return false ; }
    }
    return true ;
}

void solve ( ) {
    int mx = 0 , aux = 0 , sm_even = 0 ;
    aux = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( same ( a[ i - 1 ] , a[ i ] ) == true ) { ++ aux ; }
        else {
            mx = max ( mx , aux ) ;
            if ( aux % 2 == 0 || v[ a[ i - 1 ] ].size ( ) == 0 ) { sm_even += aux ; }
            aux = 1 ;
        }
    }
    mx = max ( mx , aux ) ;
    if ( aux % 2 == 0 || v[ a[ n ] ].size ( ) == 0 ) { sm_even += aux ; }
    aux = 1 ;

    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int x ;
        scanf ( "%d" , &x ) ;
        if ( x == 0 ) { printf ( "%d\n" , mx ) ; }
        else { printf ( "%d\n" , max ( mx , sm_even ) ) ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // t = 1 ;
    init ( ) ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}