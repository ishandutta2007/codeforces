#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 300007

int n , k ;
int a[ MAXN ] ;

pair < int , int > w[ MAXN ] ;
int mx[ MAXN ] ;

int get ( int sr ) {
    int l , r , mid ;
    l = 1 ;
    r = k ;
    if ( w[ r ].first < sr ) { return -1 ; }
    while ( r - l > 3 ) {
        mid = ( ( l + r ) >> 1 ) ;
        if ( w[ mid ].first >= sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( w[ l ].first < sr ) { ++ l ; }
    return l ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &k ) ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        scanf ( "%d%d" , &w[ i ].first , &w[ i ].second ) ;
    }
    sort ( w + 1 , w + k + 1 ) ;
    mx[ k + 1 ] = 0 ;
    for ( int i = k ; i >= 1 ; -- i ) {
        mx[ i ] = max ( mx[ i + 1 ] , w[ i ].second ) ;
    }
}

void solve ( ) {
    int st = 1 ;
    int ans = 0 ;
    while ( st <= n ) {
        int val = -1 ;
        int aux ;
        for ( aux = st ; aux <= n ; ++ aux ) {
            val = max ( val , a[ aux ] ) ;
            int id = get ( val ) ;
            if ( id == -1 ) { break ; }
            if ( mx[ id ] < aux - st + 1 ) { break ; }
        }
        ++ ans ;
        if ( aux == st ) { printf ( "-1\n" ) ; return ; }
        st = aux ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}