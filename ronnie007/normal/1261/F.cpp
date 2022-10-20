#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 107 ;
const int MOD = 998244353 ;
const ll mx_coord = ( 1LL << 60 ) - 1 ;
#define fi first
#define se second

int n , m ;
pair < ll , ll > a[ MAXN ] , b[ MAXN ] ;

struct node {
    ll l , r ;
    bool targ ;
    node *pl , *pr ;
    node ( ) { l = r = 0 ; pl = pr = NULL ; targ = false ; }
    node ( ll _l , ll _r ) {
        l = _l , r = _r ;
        targ = false ;
        pl = pr = NULL ;
    }
};

node *root_a , *root_b ;

vector < pair < ll , ll > > act[ 2 ][ 63 ] ;
vector < pair < ll , ll > > aux[ 2 ][ 63 ] ;

void upd ( node *wh , ll st , ll en , int id , int lvl ) {
    if ( st <= wh->l && wh->r <= en ) {
        wh->targ = true ;
        return ;
    }
    ll mid = ( wh->l + wh->r ) / 2 ;
    if ( st <= mid ) {
        if ( wh->pl == NULL ) {
            wh->pl = new node ( wh->l , mid ) ;
        }
        upd ( wh->pl , st , en , id , lvl - 1 ) ;
    }
    if ( mid + 1 <= en ) {
        if ( wh->pr == NULL ) {
            wh->pr = new node ( mid + 1 , wh->r ) ;
        }
        upd ( wh->pr , st , en , id , lvl - 1 ) ;
    }
}
void extr ( node *wh , int id , int lvl ) {
    aux[ id ][ lvl ].push_back ( { wh->l , wh->r } ) ;
    if ( wh->targ == true ) {
        act[ id ][ lvl ].push_back ( { wh->l , wh->r } ) ;
    }
    if ( wh->pl != NULL ) {
        extr ( wh->pl , id , lvl - 1 ) ;
    }
    if ( wh->pr != NULL ) {
        extr ( wh->pr , id , lvl - 1 ) ;
    }
}

void input ( ) {
    root_a = new node ( 0 , mx_coord ) ;
    root_b = new node ( 0 , mx_coord ) ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].fi >> a[ i ].se ;
        upd ( root_a , a[ i ].fi , a[ i ].se , 0 , 60 ) ;
    }
    cin >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> b[ i ].fi >> b[ i ].se ;
        upd ( root_b , b[ i ].fi , b[ i ].se , 1 , 60 ) ;
    }
    extr ( root_a , 0 , 60 ) ;
    extr ( root_b , 1 , 60 ) ;
}

vector < pair < ll , ll > > srt ;

ll inv2 = ( MOD + 1 ) / 2 ;

ll up_to ( ll x ) {
    if ( x <= 0 ) { return 0 ; }
    ll ret = ( x % MOD ) ;
    ret = ( ret * ( ( x + 1 ) % MOD ) ) % MOD ;
    ret = ( ret * inv2 ) % MOD ;
    return ret ;
}

ll calc ( ll up , ll down ) {
    return ( up_to ( up ) - up_to ( down - 1 ) + MOD ) % MOD ;
}

void solve ( ) {
    for ( int lvl = 60 ; lvl >= 0 ; -- lvl ) {
        for ( int tp : { 0 , 1 } ) {
            for ( auto hh1 : act[ tp ][ lvl ] ) {
                for ( auto hh2 : aux[ tp ^ 1 ][ lvl ] ) {
                    ll pos = hh1.fi ^ hh2.fi ;
                    srt.push_back ( { pos , pos + (1LL << lvl ) - 1 } ) ;
                }
            }
        }

    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    ll mx_sel = -1 ;
    ll ans = 0 ;
    for ( auto hh : srt ) {
        if ( hh.se > mx_sel ) {
            ans += calc ( hh.se , max ( mx_sel + 1 , hh.fi ) ) ;
            mx_sel = hh.se ;
        }
    }
    cout << ( ans % MOD ) << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// scanf ( "%d" , &t ) ;
    t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}