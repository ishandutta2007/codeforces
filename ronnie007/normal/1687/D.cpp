#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2000007 ;

int n ;
int a[ MAXN ] ;
int prv[ MAXN ] , comp[ MAXN ] ;
vector < int > v[ MAXN ] ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y ) {
    int k1 = get ( x ) , k2 = get ( y ) ;
    if ( k1 != k2 ) {
        if ( comp[ k1 ] >= comp[ k2 ] ) {
            prv[ k2 ] = k1 ;
            comp[ k1 ] += comp[ k2 ] ;
        }
        else {
            prv[ k1 ] = k2 ;
            comp[ k2 ] += comp[ k1 ] ;
        }
    }
}

ll f ( ll x ) {
    ll hh = sqrt ( x ) ;
    if ( x <= hh * hh + hh ) { return hh ; }
    else { return -1 ; }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        prv[ i ] = -1 , comp[ i ] = 1 ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] == a[ i - 1 ] ) { unite ( i , i - 1 ) ; }
        else { v[ a[ i ] - a[ i - 1 ] ].push_back ( i ) ; }
    }
}

void solve ( ) {
    for ( int ans = 1 ; ans < MAXN ; ++ ans ) {
        for ( auto i : v[ ans ] ) {
            unite ( i , i - 1 ) ;
        }
        int wh = 1 ;
        ll l , r ;
        l = max ( 0LL , 1LL * ans * ans - a[ 1 ] ) ;
        r = 1LL * ans * ans + ans - a[ 1 ] ;
        if ( r < 0 ) { continue ; }
        while ( wh <= n ) {
            ll mnval = a[ wh ] , mxval = a[ wh + comp[ get ( wh ) ] - 1 ] ;
            ll root = sqrt ( mnval + r ) ;

            ll auxl = max ( 0LL , root * root - mnval ) ;
            ll auxr = root * root + root - mxval ;

            l = max ( l , auxl ) ;
            r = min ( r , auxr ) ;

            if ( l > r ) { break ; }

            wh += comp[ get ( wh ) ] ;
        }
        if ( wh <= n ) { continue ; }
        cout << l << "\n" ;
        return ;
    }
}

int main ( ) {
    /// freopen ( "in.txt" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}