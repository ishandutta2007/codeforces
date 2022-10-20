#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 1000000007


int n ;
int a[ MAXN ] ;

int pos[ MAXN ] ;
int st[ MAXN ] , en[ MAXN ] , spec[ MAXN ] ;

class fenwick {
public :
    int tr[ MAXN ] ;
    void init ( ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            tr[ i ] = 0 ;
        }
    }
    void update ( int wh , int x ) {
        for ( int i = wh ; i <= n ; i += ( i & (-i) ) ) {
            tr[ i ] = ( tr[ i ] + x ) % MOD ;
        }
    }
    int query ( int wh ) {
        int ret = 0 ;
        for ( int i = wh ; i >= 1 ; i -= ( i & (-i) ) ) {
            ret = ( ret + tr[ i ] ) % MOD ;
        }
        return ret ;
    }
};
fenwick w ;


pair < int , int > srt[ MAXN ] ;
void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        srt[ i ] = { a[ i ] , -i } ;
    }
    sort ( srt + 1 , srt + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ -srt[ i ].second ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        pos[ a[ i ] ] = i ;
    }
}


void solve ( ) {
    w.init ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        st[ i ] = ( w.query ( a[ i ] ) + 1 ) % MOD ;
        w.update ( a[ i ] , st[ i ] ) ;
    }
    w.init ( ) ;
    for ( int i = n ; i >= 1 ; -- i ) {
        en[ i ] = ( w.query ( n ) - w.query ( a[ i ] ) + MOD + 1 ) % MOD ;
        w.update ( a[ i ] , en[ i ] ) ;
    }
    w.init ( ) ;
    int mx = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( mx > a[ i ] ) { continue ; }
        int prv = mx ;
        mx = a[ i ] ;
        w.update ( i , 1 ) ;
        spec[ i ] = 1 ;
        for ( int j = mx - 1 ; j > prv ; -- j ) {
            int wh = pos[ j ] ;
            spec[ wh ] = ( w.query ( n ) - w.query ( wh ) + MOD ) % MOD ;
            w.update ( wh , spec[ wh ] ) ;
        }
        for ( int j = mx - 1 ; j > prv ; -- j ) {
            int wh = pos[ j ] ;
            w.update ( wh , MOD - spec[ wh ] ) ;
        }
        w.update ( i , -1 ) ;
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += ( 1LL * st[ i ] * ( ( en[ i ] - spec[ i ] + MOD ) % MOD ) ) % MOD ;
        ans %= MOD ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}