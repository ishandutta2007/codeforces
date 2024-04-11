#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 5007

int n ;
int a[ MAXN ] ;
long long pref[ MAXN ] ;

int dp[ MAXN ][ MAXN ] ;

int f[ MAXN ][ MAXN ] ;

int getr ( long long sr , int id ) {
    int l , r , mid ;
    l = 1 ;
    r = id - 1 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        long long aux = ( pref[ id - 1 ] - pref[ mid - 1 ] ) ;
        if ( aux <= sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( r >= 1 ) {
        long long aux = ( pref[ id - 1 ] - pref[ r - 1 ] ) ;
        if ( aux <= sr ) { r -- ; }
        else { break ; }
    }
    return r ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        pref[ i ] = ( pref[ i - 1 ] + a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        dp[ 1 ][ i ] = ( i - 1 ) ;
    }
    for ( j = 2 ; j <= n ; j ++ ) {
        for ( i = 2 ; i <= j ; i ++ ) {
            int ret = getr ( pref[ j ] - pref[ i - 1 ] , i ) ;
            if ( ret == i - 1 ) { dp[ i ][ j ] = MAXN ; }
            else {
                dp[ i ][ j ] = f[ i - 1 ][ ret + 1 ] + ( j - i ) ;
            }
        }
        f[ j ][ j + 1 ] = MAXN ;
        for ( i = j ; i >= 0 ; i -- ) {
            f[ j ][ i ] = min ( f[ j ][ i + 1 ] , dp[ i ][ j ] ) ;
        }
    }
    printf ( "%d\n" , f[ n ][ 1 ] ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}