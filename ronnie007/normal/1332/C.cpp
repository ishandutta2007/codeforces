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

#define MAXN 200007

int n , k ;
string a ;

int cnt[ MAXN ][ 26 ] ;
int tot[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    for ( int i = 0 ; i < k ; ++ i ) {
        for ( int j = 0 ; j < 26 ; ++ j ) {
            cnt[ i ][ j ] = tot[ i ] = 0 ;
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        int id = ( i % k ) ;
        int h = ( a[ i ] - 'a' ) ;
        ++ cnt[ id ][ h ] ;
        ++ tot[ id ] ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i < k ; ++ i ) {
        int h = ( k - i - 1 ) ;
        if ( h < i ) { break ; }
        int mn = MAXN ; 
        for ( int j = 0 ; j < 26 ; ++ j ) {
            int sr ;
            if ( i != h ) {
                sr = tot[ i ] + tot[ h ] - cnt[ i ][ j ] - cnt[ h ][ j ] ;
            }
            else {
                sr = tot[ i ] - cnt[ i ][ j ] ;
            }
            if ( mn > sr ) {
                mn = sr ;
            }
        }
        ans += mn ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}