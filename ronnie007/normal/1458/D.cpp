#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
string a ;

int cnt[ MAXN ] ;

string ans ;

void dfs ( int aux ) {
    if ( aux > 0 ) {
        while ( cnt[ aux - 1 ] > 0 ) {
            -- cnt[ aux - 1 ] ;
            dfs ( aux - 1 ) ;
            ans += '0' ;
        }
    }
    if ( aux < 2 * n ) {
        while ( cnt[ aux ] > 0 ) {
            -- cnt[ aux ] ;
            dfs ( aux + 1 ) ;
            ans += '1' ;
        }
    }
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int aux = n ;
    ans.clear ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == '0' ) { -- aux ; ++ cnt[ aux ] ; }
        else { ++ cnt[ aux ] ; ++ aux ; }
    }
    dfs ( n ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        cout << ans[ i ] ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}