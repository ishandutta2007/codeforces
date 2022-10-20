#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std ;

#define MAXN 100007

int n , k ;
string a ;

int pref[ 2 ][ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        pref[ 0 ][ i ] = pref[ 0 ][ i - 1 ] + ( a[ i - 1 ] == 'a' ) ;
        pref[ 1 ][ i ] = pref[ 1 ][ i - 1 ] + ( a[ i - 1 ] == 'b' ) ;
    }
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 0 ; j < 2 ; j ++ ) {
            int l , r , mid ;
            l = i ;
            r = n ;
            while ( r - l > 3 ) {
                mid = ( l + r ) / 2 ;
                if ( ( pref[ j ][ mid ] - pref[ j ][ i - 1 ] <= k ) ) { l = mid ; }
                else { r = mid ; }
            }
            while ( ( pref[ j ][ r ] - pref[ j ][ i - 1 ] > k ) ) { r -- ; }
            if ( ans < ( r - i + 1 ) ) { ans = ( r - i + 1 ) ; }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}