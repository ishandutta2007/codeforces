#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int cnt_neg[ MAXN ] ;
int mnabs[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    int aux = b[ 1 ] ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        aux = __gcd ( aux , b[ i ] ) ;
    }
    long long ans = 0 ;
    if ( aux == 1 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            ans += abs ( a[ i ] ) ;
        }
        cout << ans << "\n" ;
        return ;
    }
    for ( int i = 0 ; i < aux ; ++ i ) {
        mnabs[ i ] = 1e9 + 2 ;
        cnt_neg[ i ] = 0 ;
    }
    long long hh1 , hh2 ;
    hh1 = hh2 = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int pos = ( i % aux ) ;
        if ( a[ i ] < 0 ) {
            ++ cnt_neg[ pos ] ;
        }
        mnabs[ pos ] = min ( mnabs[ pos ] , abs ( a[ i ] ) ) ;
        ans += abs ( a[ i ] ) ;
    }
    for ( int i = 0 ; i < aux ; ++ i ) {
        if ( cnt_neg[ i ] % 2 == 1 ) {
            hh1 += 2 * mnabs[ i ] ;
        }
        else {
            hh2 += 2 * mnabs[ i ] ;
        }
    }
    cout << ans - min ( hh1 , hh2 ) << "\n" ;
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	int t ; cin >> t ;
	while ( t -- ) {
		input ( ) ;
		solve ( ) ;
	}
	return 0 ;
}