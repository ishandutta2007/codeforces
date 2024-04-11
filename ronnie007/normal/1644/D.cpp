#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 998244353

set < int > rows , cols ;

int n , m , k , q ;
pair < int , int > a[ MAXN ] ;

bool covered_row ( int x ) {
    if ( rows.find ( x ) != rows.end ( ) ) { return true ; }
    if ( cols.size ( ) == m ) { return true ; }
    return false ;
}

bool covered_col ( int y ) {
    if ( cols.find ( y ) != cols.end ( ) ) { return true ; }
    if ( rows.size ( ) == n ) { return true ; }
    return false ;
}

void input ( ) {
    cin >> n >> m >> k >> q ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
    }
}

void solve ( ) {
    long long ans = 1 ;
    for ( int i = q ; i >= 1 ; -- i ) {
        int x = a[ i ].first , y = a[ i ].second ;
        if ( covered_row ( x ) == false || covered_col ( y ) == false ) {
            ans = ( ans * k ) % MOD ;
        }
        rows.insert ( x ) ;
        cols.insert ( y ) ;
    }
    cout << ans << "\n" ;
    rows.clear ( ) ;
    cols.clear ( ) ;
}

int main ( ) {
    /// freopen ( "in.txt" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}