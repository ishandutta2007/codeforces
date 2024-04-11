#include<bits/stdc++.h>
using namespace std ;

#define MAXN 18

int n , k ;
bool fl[ ( 1 << MAXN ) ] ;

int dp[ ( 1 << MAXN ) ][ 2 ][ 2 ] ;

void f ( int where , int IL , int IR ) {
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            dp[ where ][ i ][ j ] = -1 ;
        }
    }
    if ( IL == IR ) { return ; }
    int mid = ( IL + IR ) / 2 ;
    f ( 2 * where , IL , mid ) ;
    f ( 2 * where + 1 , mid + 1 , IR ) ;
    if ( IL == IR - 1 ) {
        dp[ where ][ fl[ IL ] ][ fl[ IR ] ] = dp[ where ][ fl[ IR ] ][ fl[ IL ] ] = ( fl[ IL ] || fl[ IR ] ) ;
        return ;
    }
    for ( int win1 = 0 ; win1 < 2 ; ++ win1 ) {
        for ( int lose1 = 0 ; lose1 < 2 ; ++ lose1 ) {
            if ( dp[ 2 * where ][ win1 ][ lose1 ] < 0 ) { continue ; }
            for ( int win2 = 0 ; win2 < 2 ; ++ win2 ) {
                /// if ( win1 == lose1 ) { continue ; }
                for ( int lose2 = 0 ; lose2 < 2 ; ++ lose2 ) {
                    if ( dp[ 2 * where + 1 ][ win2 ][ lose2 ] < 0 ) { continue ; }
                    /// if ( win2 == lose2 ) { continue ; }
                    int aux = dp[ 2 * where ][ win1 ][ lose1 ] + dp[ 2 * where + 1 ][ win2 ][ lose2 ] ;
                    ///aux += ( fl[ win1 ] || fl[ lose1 ] ) ;
                    ///aux += ( fl[ win2 ] || fl[ lose2 ] ) ;
                    aux += ( win1 || win2 ) ;
                    aux += ( lose1 || lose2 ) ;
                    /// win1 > win2
                    dp[ where ][ win1 ][ win2 ] = max ( dp[ where ][ win1 ][ win2 ] , aux + ( lose1 || lose2 || win2 ) ) ;
                    dp[ where ][ win1 ][ lose1 ] = max ( dp[ where ][ win1 ][ lose1 ] , aux + ( lose1 || win2 ) ) ;
                    dp[ where ][ win1 ][ lose2 ] = max ( dp[ where ][ win1 ][ lose2 ] , aux + ( lose2 || win2 ) ) ;

                    /// win2 > win1
                    dp[ where ][ win2 ][ win1 ] = max ( dp[ where ][ win2 ][ win1 ] , aux + ( lose1 || lose2 || win1 ) ) ;
                    dp[ where ][ win2 ][ lose1 ] = max ( dp[ where ][ win2 ][ lose1 ] , aux + ( lose1 || win1 ) ) ;
                    dp[ where ][ win2 ][ lose2 ] = max ( dp[ where ][ win2 ][ lose2 ] , aux + ( lose2 || win1 ) ) ;
                }
            }
        }
    }
    /**
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            printf ( "dp[ %d ][ %d ][ %d ] = %d\n" , where , i , j , dp[ where ][ i ][ j ] ) ;
        }
    }
    **/
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int x ;
        cin >> x ;
        fl[ x ] = true ;
    }
}

void solve ( ) {
    f ( 1 , 1 , ( 1 << n ) ) ;
    int ans = 0 ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            ans = max ( ans , dp[ 1 ][ i ][ j ] + ( i || j ) ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}