#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
#include<random>
using namespace std ;

#define MAXN 57

int n , k ;
int64_t a[ MAXN ] ;
int64_t pref[ MAXN ] ;

int dp[ MAXN ][ MAXN ] ;

int64_t ans = 0 ;

bool f ( int id ) {
    ans += (1LL<<id) ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= k ; ++ j ) {
            dp[ i ][ j ] = -1 ;
        }
    }
    dp[ 0 ][ 0 ] = 1 ;
    for ( int j = 0 ; j < k ; ++ j ) {
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( dp[ i ][ j ] == -1 ) { continue ; }
            for ( int t = i + 1 ; t <= n ; ++ t ) {
                long long aux = ( pref[ t ] - pref[ i ] ) ;
                if ( ( aux & ans ) == ans ) { dp[ t ][ j + 1 ] = 1 ; }
            }
        }
    }
    ans -= (1LL<<id) ;
    return ( dp[ n ][ k ] == 1 ) ;
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        pref[ i ] = ( pref[ i - 1 ] + a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 60 ; i >= 0 ; -- i ) {
        if ( f ( i ) == true ) {
            ans += (1LL<<i) ;
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