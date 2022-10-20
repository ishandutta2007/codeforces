#include<bits/stdc++.h>
using namespace std ;
const int MAXN = 2000 ;

int n , m , q ;
bitset < MAXN > a[ MAXN ] ;

set < pair < int , int > > s ;

struct qq {
    int wh1 , wh2 ;
    int l , r ;
    qq ( ) { wh1 = wh2 = l = r = 0 ; }
    qq ( int _wh1 , int _wh2 , int _l , int _r ) {
        wh1 = _wh1 , wh2 = _wh2 ;
        l = _l , r = _r ;
        if ( wh1 > wh2 ) { swap ( wh1 , wh2 ) ; }
        if ( l > r ) { swap ( l , r ) ; }
    }
    bool operator < ( qq other ) const {
        if ( wh1 != other.wh1 ) { return wh1 < other.wh1 ; }
        if ( wh2 != other.wh2 ) { return wh2 < other.wh2 ; }
        if ( l != other.l ) { return l < other.l ; }
        return r < other.r ;
    }
};
set < qq > ret ;

qq f ( int id1 , int id2 ) {
    int l = ( a[ id1 ] & (~a[ id2 ]) )._Find_first ( ) ;
    int r = ( a[ id2 ] & (~a[ id1 ]) )._Find_first ( ) ;
    return qq ( id1 , id2 , l , r ) ;
}

void upd ( int wh , bool fl ) {
    auto it = s.find ( { a[ wh ].count ( ) , wh } ) ;
    if ( it == s.end ( ) ) { return ; }
    bool bt = true ;
    auto prv = it ;
    if ( it != s.begin ( ) ) {
        -- prv ;
        qq aux = f ( prv->second , it->second ) ;
        if ( aux.l != MAXN && aux.r != MAXN ) {
            if ( fl == false ) {
                ret.erase ( aux ) ;
            }
            else {
                ret.insert ( aux ) ;
            }
        }
    }
    else { bt = false ; }
    auto nxt = it ;
    ++ nxt ;
    if ( nxt != s.end ( ) ) {
        qq aux = f ( it->second , nxt->second ) ;
        if ( aux.l != MAXN && aux.r != MAXN ) {
            if ( fl == false ) {
                ret.erase ( aux ) ;
            }
            else {
                ret.insert ( aux ) ;
            }
        }
    }
    else { bt = false ; }

    if ( bt == true ) {
        qq aux = f ( prv->second , nxt->second ) ;
        if ( aux.l != MAXN && aux.r != MAXN ) {
            if ( fl == true ) {
                ret.erase ( aux ) ;
            }
            else {
                ret.insert ( aux ) ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> m >> q ;
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        s.insert ( { 0 , i } ) ;
    }
    while ( q -- ) {
        int wh , l , r ;
        cin >> wh >> l >> r ;
        -- wh , -- l , -- r ;
        upd ( wh , false ) ;
        s.erase ( { a[ wh ].count ( ) , wh } ) ;
        a[ wh ] = ( a[ wh ] ^ ( ( ( ~ bitset < MAXN > ( ) ) << ( MAXN - ( r - l + 1 ) ) ) >> ( MAXN - r - 1 ) ) );
        s.insert ( { a[ wh ].count ( ) , wh } ) ;
        upd ( wh , true ) ;
        if ( ret.empty ( ) == true ) {
            cout << "-1\n" ;
            continue ;
        }
        auto it = ret.begin ( ) ;
        cout << it->wh1 + 1 << " " << it->l + 1 << " " << it->wh2 + 1 << " " << it->r + 1 << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}