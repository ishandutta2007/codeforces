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
using namespace std ;

#define MAXN 5007
#define MOD 1000000007

int n ;
char a[ MAXN ] ;
long long dp[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
    a[ 0 ] = 's' ;
}

void solve ( ) {
    int i , j ;
    dp[ 0 ][ 0 ] = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i - 1 ] != 'f' ) {
            long long sm = 0 ;
            for ( j = n ; j >= 0 ; j -- ) {
                if ( a[ i ] == 'f' && j == 0 ) { dp[ i ][ j ] = 0 ; break ; }
                sm += dp[ i - 1 ][ j ] ;
                if ( sm >= MOD ) { sm -= MOD ; }
                dp[ i ][ j ] = sm ;
                if ( a[ i ] == 'f' && j != 0 ) {
                    dp[ i ][ j ] += dp[ i - 1 ][ j - 1 ] ;
                    if ( dp[ i ][ j ] >= MOD ) { dp[ i ][ j ] -= MOD ; }
                }
            }
        }
        else {
            for ( j = n ; j >= 0 ; j -- ) {
                if ( a[ i ] == 'f' ) {
                    if ( j == 0 ) { dp[ i ][ j ] = 0 ; break ; }
                    dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] ;
                }
                else {
                    dp[ i ][ j ] = dp[ i - 1 ][ j ] ;
                }
            }
        }
    }
    long long ans = 0 ;
    for ( i = 0 ; i <= n ; i ++ ) {
        ans += dp[ n ][ i ] ;
        if ( ans >= MOD ) { ans -= MOD ; }
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