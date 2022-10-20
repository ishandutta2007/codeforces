#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2e5 + 7 ;
const int MOD[ 2 ] = { 1000000007 , 998244353 } ;
const int BASE = 17 ;

int n ;
string a ;

ll pw[ 2 ][ MAXN ] ;

struct node {
    int pref , suff ;
    ll val[ 2 ] ;
    int len , tot ;
    node ( ) {
        pref = suff = 0 ;
        val[ 0 ] = val[ 1 ] = 0 ;
        len = tot = 0 ;
    }
    node ( int x ) {
        tot = 1 ;
        if ( x == 0 ) { len = 1 ; pref = suff = 0 ; }
        else { len = 0 ; pref = suff = 1 ; }
        val[ 0 ] = val[ 1 ] = 0 ;
    }
};

node unite ( node p1 , node p2 ) {
    if ( p1.tot == 0 ) { return p2 ; }
    if ( p2.tot == 0 ) { return p1 ; }
    node ret ;
    ret.tot = p1.tot + p2.tot ;
    if ( p1.pref != p1.tot ) { ret.pref = p1.pref ; }
    else { ret.pref = p1.tot + p2.pref ; }

    if ( p2.suff != p2.tot ) { ret.suff = p2.suff ; }
    else { ret.suff = p2.tot + p1.suff ; }

    ret.len = p1.len + p2.len ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        int wh = p1.len ;
        ret.val[ i ] = p1.val[ i ] ;
        if ( p1.len > 0 && p2.len ) {
            ret.val[ i ] = ( ret.val[ i ] + pw[ i ][ p1.len - 1 ] * ( ( p1.suff + p2.pref ) % 2 + 1 ) ) % MOD[ i ] ;
            ++ wh ;
        }
        ll coef = 1 ;
        if ( wh >= 1 ) { coef = pw[ i ][ wh - 1 ] ; }
        ret.val[ i ] = ( ret.val[ i ] + coef * p2.val[ i ] ) % MOD[ i ] ;
    }
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = node ( a[ IL - 1 ] - '0' ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return node ( ) ; }
        if ( IR < CURL || CURR < IL ) { return node ( ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return unite ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

bool eq ( node p1 , node p2 ) {
    if ( p1.tot != p2.tot || p1.len != p2.len ) { return false ; }
    if ( p1.val[ 0 ] != p2.val[ 0 ] || p1.val[ 1 ] != p2.val[ 1 ] ) { return false ; }
    if ( ( p1.pref % 2 ) != ( p2.pref % 2 ) ) { return false ; }
    if ( ( p1.suff % 2 ) != ( p2.suff % 2 ) ) { return false ; }
    return true ;
}

void solve ( ) {
    cin >> n >> a ;
    pw[ 0 ][ 0 ] = pw[ 1 ][ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pw[ 0 ][ i ] = ( pw[ 0 ][ i - 1 ] * BASE ) % MOD[ 0 ] ;
        pw[ 1 ][ i ] = ( pw[ 1 ][ i - 1 ] * BASE ) % MOD[ 1 ] ;
    }
    w.init ( 1 , 1 , n ) ;
    int q ; cin >> q ;
    while ( q -- ) {
        int st1 , st2 , len ;
        cin >> st1 >> st2 >> len ;
        node aux1 = w.query ( 1 , 1 , n , st1 , st1 + len - 1 ) ;
        node aux2 = w.query ( 1 , 1 , n , st2 , st2 + len - 1 ) ;
        if ( eq ( aux1 , aux2 ) == true ) { cout << "Yes\n" ; }
        else { cout << "No\n" ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}