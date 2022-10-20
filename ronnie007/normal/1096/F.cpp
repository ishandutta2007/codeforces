#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007
#define MOD 998244353

int n ;
int a[ MAXN ] , sm[ MAXN ] ;
int after[ MAXN ] ;
bool used[ MAXN ] ;
int cnt ;

long long st ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            ++ tr[ where ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        if ( a[ i ] == -1 ) { ++ cnt ; }
        else { used[ a[ i ] ] = true ; }
    }
    int hh = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( a[ i ] == -1 ) { ++ hh ; }
        else { after[ a[ i ] ] = hh ; }
    }
    hh = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) { ++ hh ; }
        else { sm[ i ] = hh ; }
    }
}


void solve ( ) {
    long long ans = 0 ;
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == -1 ) { continue ; }
        ans += w.query ( 1 , 1 , n , a[ i ] , n ) ;
        w.update ( 1 , 1 , n , a[ i ] ) ;
    }
    
    long long tot = ( 1LL * cnt * ( cnt - 1 ) / 2 ) % MOD ;
    ans = ( ans + ( tot * fastpow ( 2 , MOD - 2 ) ) ) % MOD ;

    long long inv = fastpow ( cnt , MOD - 2 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) { continue ; }
        long long aux = ( 1LL * after[ i ] * sm[ i ] ) % MOD ;
        aux = ( aux * inv ) % MOD ;
        ans = ( ans + aux ) % MOD ;

        aux = ( 1LL * ( cnt - after[ i ] ) * ( cnt - sm[ i ] ) ) % MOD ;
        aux = ( aux * inv ) % MOD ;
        ans = ( ans + aux ) % MOD ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}