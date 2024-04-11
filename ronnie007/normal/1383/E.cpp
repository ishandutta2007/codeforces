#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
#define MOD 1000000007

int n ;
string a ;
vector < int > v ;

long long dp[ MAXN ] ;
long long pref[ MAXN ] ;

map < int , int > zx ;

void input ( ) {
    cin >> a ;
    int sz = a.size ( ) ;
    int cnt = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( a[ i ] == '1' ) { v.push_back ( cnt ) ; cnt = 0 ; }
        else { ++ cnt ; }
    }
    v.push_back ( cnt ) ;
    n = v.size ( ) ;
}

void solve ( ) {
    if ( n == 1 ) {
        cout << v[ 0 ] << "\n" ;
        return ;
    }
    dp[ 1 ] = v[ 0 ] + 1 ;
    pref[ 1 ] = dp[ 1 ] ; 
    for ( int i = 2 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= v[ i - 1 ] ; ++ j ) {
            auto it = zx.lower_bound ( j ) ;
            dp[ i ] = ( dp[ i ] + pref[ i - 1 ] ) % MOD ;
            if ( i != n && it != zx.end ( ) ) {
                dp[ i ] = ( dp[ i ] - pref[ it->second - 1 ] + MOD ) % MOD ;
            }
        }
        while ( zx.empty ( ) == false && zx.begin ( )->first <= v[ i - 1 ] ) {
            zx.erase ( zx.begin ( ) ) ;
        }
        zx[ v[ i - 1 ] ] = i ;
        pref[ i ] = ( pref[ i - 1 ] + dp[ i ] ) % MOD ;
    }
    cout << dp[ n ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}