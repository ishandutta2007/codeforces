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
using namespace std ;

int n ;
string a ;

int f[ 2 ] ;
int pref , suff ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int ans = 0 ;
    int i ;
    f[ 0 ] = f[ 1 ] = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        int val ;
        if ( a[ i ] == 'b' ) { val = 0 ; }
        else { val = 1 ; }
        f[ val ] = f[ (val^1) ] + 1 ;
        f[ (val^1) ] = 0 ;
        if ( ans < f[ val ] ) { ans = f[ val ] ; }
        if ( i == ( n - 1 ) ) { suff = f[ val ] ; }
        if ( f[ val ] == ( i + 1 ) ) { pref = ( i + 1 ) ; }
    }
    if ( a[ n - 1 ] != a[ 0 ] ) {
        if ( pref + suff <= n ) { ans = max ( ans , pref + suff ) ; }
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