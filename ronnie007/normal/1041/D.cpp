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
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 200007

int n , h ;
pair < int , int > ff[ MAXN ] ;

pair < int , int > a[ MAXN ] ;

int pref[ MAXN ] ;
int ww[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &h ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d" , &ff[ i ].first , &ff[ i ].second ) ;
        a[ i ].first = ( ff[ i ].second - ff[ i ].first ) ;
        if ( i == 1 ) { a[ i ].second = 0 ; }
        else {
            a[ i ].second = ( ff[ i ].first - ff[ i - 1 ].second ) ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        pref[ i ] = ( pref[ i - 1 ] + a[ i ].second ) ;
        ww[ i ] = ( ww[ i - 1 ] + a[ i ].first ) ;
    }
}

void solve ( ) {
    int i ;
    int ans = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int l , r , mid ;
        l = i ;
        r = n ;
        while ( r - l > 3 ) {
            mid = ( l + r ) / 2 ;
            int aux = ( pref[ mid ] - pref[ i ] ) ;
            if ( aux < h ) { l = mid ; }
            else { r = mid ; }
        }
        while ( ( pref[ r ] - pref[ i ] ) >= h ) { r -- ; }
        int cur = ( ff[ r ].second - ff[ i ].first ) ;
        cur += max ( 0 , h - ( pref[ r ] - pref[ i ] ) ) ;
        if ( ans < cur ) { ans = cur ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}