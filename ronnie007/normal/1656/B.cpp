#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

#define MAXN 200007

int n , targ ;
int a[ MAXN ] ;

set < int > s ;

void input ( ) {
    cin >> n >> targ ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}


void solve ( ) {
    s.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( s.find ( a[ i ] - targ ) != s.end ( ) ) {
            cout << "YES\n" ;
            return ;
        }
        if ( s.find ( a[ i ] + targ) != s.end ( ) ) {
            cout << "YES\n" ;
            return ;
        }
        s.insert ( a[ i ] ) ;
    }
    cout << "NO\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}