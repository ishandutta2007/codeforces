#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;
long long k ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;

bool f ( long long x ) {
    int i ;
    long long sm = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        long long sr = x * a[ i ] ;
        if ( sr > b[ i ] ) {
            sm += ( sr - b[ i ] ) ;
            if ( sm > k ) { return false ; }
        }
    }
    return true ;
}

void input ( ) {
    cin >> n >> k ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    long long l , r , mid ;
    l = 0 ;
    r = 2 ;
    int i ;
    for ( i = 1 ; i <= 9 ; i ++ ) { r *= 10 ; }
    r += 17 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == false ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( r ) == false ) { r -- ; }
    cout << r << "\n" ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}