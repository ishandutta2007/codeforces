#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , d , m ;
int a[ MAXN ] ;

long long ans ;

vector < int > sm , lg ;

long long pref_sm[ MAXN ] ;
long long pref_lg[ MAXN ] ;

void input ( ) {
    cin >> n >> d >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        if ( a[ i ] <= m ) {
            sm.push_back ( a[ i ] ) ;
        }
        else {
            lg.push_back ( a[ i ] ) ;
        }
    }
    sort ( sm.begin ( ) , sm.end ( ) ) ;
    sort ( lg.begin ( ) , lg.end ( ) ) ;
    pref_sm[ 0 ] = 0 ;
    int sz = sm.size ( ) ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        pref_sm[ i ] = ( pref_sm[ i - 1 ] + sm[ i - 1 ] ) ;
    }
    sz = lg.size ( ) ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        pref_lg[ i ] = ( pref_lg[ i - 1 ] + lg[ i - 1 ] ) ;
    }
}

void solve ( ) {
    int sz = lg.size ( ) ;
    int len = sm.size ( ) ;
    for ( int i = 0 ; i <= sz ; ++ i ) {
        if ( i > 0 && 1LL * ( i - 1 ) * ( d + 1 ) + 1 > n ) { break ; }
        int lft = ( i - 1 ) * d ;
        if ( i == 0 ) { lft = 0 ; }
        long long aux = pref_lg[ sz ] - pref_lg[ sz - i ] ;
        if ( lft >= ( sz - i ) ) {
            lft -= ( sz - i ) ;
        }
        else { lft = 0 ; }

        aux += pref_sm[ len ] - pref_sm[ lft ] ;
        ans = max ( ans , aux ) ;
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