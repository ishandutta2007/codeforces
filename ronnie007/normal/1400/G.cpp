#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 3e5 + 7 ;
const int MOD = 998244353 ;

int n , m ;
int l[ MAXN ] , r[ MAXN ] ;
int cont[ MAXN ] ;
pair < int , int > edge_list[ 22 ] ;
vector < int > v[ MAXN ] , aux ;
int used[ MAXN ] ;

ll hh[ 45 ] ;

int tp ; 
vector < int > sz ;
vector < vector < int > > wh ;
vector < vector < vector < int > > > dp ;
vector < vector < int > > non_problematic ;
void create_new ( vector < int > &init ) {
    sz.push_back ( init.size ( ) ) ;
    wh.push_back ( { } ) ;
    wh[ tp ].resize ( sz[ tp ] ) ;
    for ( int i = 0 ; i < sz[ tp ] ; ++ i ) {
        -- cont[ l[ init[ i ] ] ] ;
        ++ cont[ r[ init[ i ] ] + 1 ] ;
        wh[ tp ][ i ] = init[ i ] ;
    }
    dp.push_back ( { } ) ;
    non_problematic.push_back ( { } ) ;
    dp[ tp ].resize ( ( 1 << sz[ tp ] ) ) ;
    for ( int i = 0 ; i < ( 1 << sz[ tp ] ) ; ++ i ) {
        dp[ tp ][ i ].resize ( sz[ tp ] + 1 , 0 ) ;
    }
    for ( int i = 0 ; i < sz[ tp ] ; ++ i ) {
        int nw = 0 ;
        for ( int j = 0 ; j < i ; ++ j ) {
            bool fl = false ;
            for ( int t = 1 ; t <= m ; ++ t ) {
                if ( edge_list[ t ].first == wh[ tp ][ i ] && edge_list[ t ].second == wh[ tp ][ j ] ) {
                    fl = true ; break ;
                }
                if ( edge_list[ t ].second == wh[ tp ][ i ] && edge_list[ t ].first == wh[ tp ][ j ] ) {
                    fl = true ; break ;
                }
            }
            if ( fl == false ) {
                nw += ( 1 << j ) ;
            }
        }
        non_problematic[ tp ].push_back ( nw ) ;
    }
    ++ tp ;
}
void init ( int lvl ) {
    dp[ lvl ][ 0 ][ 0 ] = 1 ;
    for ( int i = 0 ; i < sz[ lvl ] ; ++ i ) {
        for ( int j = 0 ; j < ( 1 << i ) ; ++ j ) {
            int len = __builtin_popcount ( j ) ;
            if ( dp[ lvl ][ j ][ len ] == 0 ) { continue ; }
            if ( ( non_problematic[ lvl ][ i ] & j ) == j ) {
                dp[ lvl ][ j + ( 1 << i ) ][ len + 1 ] += dp[ lvl ][ j ][ len ] ;
            }
        }
    }
    for ( int bit = 0 ; bit < sz[ lvl ] ; ++ bit ) {
        for ( int j = ( 1 << sz[ lvl ] ) - 1 ; j >= 0 ; -- j ) {
            if ( ( j & ( 1 << bit ) ) == 0 ) {
                int mx = __builtin_popcount ( j ) ;
                for ( int t = 0 ; t <= mx ; ++ t ) {
                    dp[ lvl ][ j + ( 1 << bit ) ][ t ] += dp[ lvl ][ j ][ t ] ;
                }
            }
        }
    }
}
int get_supermask ( int lvl , int sr ) {
    int ret = 0 ;
    for ( int i = 0 ; i < sz[ lvl ] ; ++ i ) {
        if ( l[ wh[ lvl ][ i ] ] <= sr && sr <= r[ wh[ lvl ][ i ] ] ) {
            ret += ( 1 << i ) ;
        }
    }
    return ret ;
}
void add_up ( int &ch , int pos , int lvl ) {
    int supermask = get_supermask ( lvl , pos ) ;
    for ( int j = ch ; j >= 0 ; -- j ) {
        for ( int add = 1 ; add <= __builtin_popcount ( supermask ) ; ++ add ) {
            hh[ j + add ] += ( hh[ j ] * dp[ lvl ][ supermask ][ add ] ) % MOD ;
            if ( hh[ j + add ] >= MOD ) {
                hh[ j + add ] -= MOD ;
            }
        }
    }
    ch += __builtin_popcount ( supermask ) ;
}

void dfs ( int vertex ) {
    used[ vertex ] = 1 ;
    aux.push_back ( vertex ) ;
    for ( auto x : v[ vertex ] ) {
        if ( used[ x ] == 0 ) {
            dfs ( x ) ;
        }
    }
}

ll fastpow ( ll x , ll pw ) {
    ll ret = 1 ;
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

ll fac[ MAXN ] , inv[ MAXN ] ;

ll comb ( int up , int down ) {
    if ( up < down || down < 0 ) { return 0 ; }
    ll ret = fac[ up ] ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    ret = ( ret * inv[ down ] ) % MOD ;
    return ret ;
}



void solve ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> l[ i ] >> r[ i ] ;
        ++ cont[ l[ i ] ] ;
        -- cont[ r[ i ] + 1 ] ;
    }
    for ( int i = 1 , x , y ; i <= m ; ++ i ) {
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        edge_list[ i ] = { x , y } ;
    }
    int tot = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            aux.clear ( ) ;
            dfs ( i ) ;
            if ( (int)aux.size ( ) >= 2 ) {
                create_new ( aux ) ;
                tot += (int)aux.size ( ) ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cont[ i ] += cont[ i - 1 ] ;
    }
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
    for ( int i = 0 ; i < tp ; ++ i ) {
        init ( i ) ;
    }
    ll ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= tot ; ++ j ) {
            hh[ j ] = 0 ;
        }
        hh[ 0 ] = 1 ;
        int ch = 0 ;
        for ( int j = 0 ; j < tp ; ++ j ) { 
            add_up ( ch , i , j ) ;
        }
        for ( int j = 0 ; j <= ch ; ++ j ) {
            ll nw = ( hh[ j ] * comb ( cont[ i ] , i - j ) ) % MOD ;
            ans = ( ans + nw ) % MOD ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}