#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;


int prefa[ MAXN ] ;
int prefb[ MAXN ] ;

bool f ( int sr ) {
    int cnt = sr - ( sr / 4 ) ;
    int full = sr - n ;

    long long cand1 , cand2 ;
    cand2 = prefb[ min ( n , cnt ) ] ;

    if ( full >= cnt ) {
        cand1 = 100LL * cnt ;
    }
    else {
        cand1 = 100LL * full ;
        cand1 += prefa[ cnt - full ] ;
    }
    return ( cand1 >= cand2 ) ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
    sort ( a + 1 , a + n + 1 , greater < int > ( ) ) ;
    sort ( b + 1 , b + n + 1 , greater < int > ( ) ) ;

    for ( int i = 1 ; i <= n ; ++ i ) {
        prefa[ i ] = ( prefa[ i - 1 ] + a[ i ] ) ;
        prefb[ i ] = ( prefb[ i - 1 ] + b[ i ] ) ;
    }
}

void solve ( ) {
    int l , r , mid ;
    l = n ;
    r = ( 1 << 23 ) ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { ++ l ; }
    cout << l - n << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}