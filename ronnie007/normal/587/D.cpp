#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 500007

int n , m ; 
struct edge {
    int x , y ;
    int c , t ;
    edge ( ) { x = y = c = t = 0 ; }
};

edge hh[ MAXN ] ;

vector < int > init[ MAXN ] ;
int keep[ MAXN ] ;

int w[ MAXN ] ;
int w_aux[ MAXN ] ;
int lst_occ[ MAXN ] ;
int oth[ MAXN ] ;

vector < int > v[ 4 * MAXN ] ;
vector < int > rv[ 4 * MAXN ] ;

int cnt ;

int neg ( int x ) {
    if ( x <= cnt ) { return x + cnt ; }
    return x - cnt ;
}

void add_or_clause ( int x , int y ) {
    v[ neg ( x ) ].push_back ( y ) ;
    rv[ y ].push_back ( neg ( x ) ) ;
    
    v[ neg ( y ) ].push_back ( x ) ;
    rv[ x ].push_back ( neg ( y ) ) ;
}


stack < int > st ;
bool used[ 4 * MAXN ] ;
int comp[ 4 * MAXN ] ;

void dfs ( int vertex ) {
    used[ vertex ] = true ;
    for ( auto x : v[ vertex ] ) {
        if ( used[ x ] == false ) {
            dfs ( x ) ;
        }
    }
    st.push ( vertex ) ;
}

void rev_dfs ( int vertex , int id ) {
    comp[ vertex ] = id ;
    for ( auto x : rv[ vertex ] ) {
        if ( comp[ x ] == 0 ) {
            rev_dfs ( x , id ) ;
        }
    }
}
        

void gen_scc ( ) {
    for ( int i = 1 ; i <= 2 * cnt ; ++ i ) {
        used[ i ] = false , comp[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= 2 * cnt ; ++ i ) {
        if ( used[ i ] == false ) {
            dfs ( i ) ;
        }
    }
    int tpid = 0 ;
    while ( st.empty ( ) == false ) {
        int x = st.top ( ) ;
        st.pop ( ) ;
        if ( comp[ x ] != 0 ) { continue ; }
        rev_dfs ( x , ++ tpid ) ;
    }
}

bool f ( int sr ) {
    cnt = m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = init[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            w_aux[ hh[ init[ i ][ j ] ].c ] = 0 ;
        }
        keep[ i ] = 0 ;
        for ( int j = sz - 1 ; j >= 0 ; -- j ) {
            if ( hh[ init[ i ][ j ] ].t <= sr ) {
                keep[ i ] = j + 1 ;
                cnt += j + 1 ;
                break ;
            }
            if ( w_aux[ hh[ init[ i ][ j ] ].c ] >= 1 ) {
                return false ;
            }
            ++ w_aux[ hh[ init[ i ][ j ] ].c ] ;
        }
    }
    for ( int i = 1 ; i <= 2 * cnt ; ++ i ) {
        v[ i ].clear ( ) ;
        rv[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = init[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            w_aux[ hh[ init[ i ][ j ] ].c ] = 0 ;
        }
        for ( int j = sz - 1 ; j >= 0 ; -- j ) {
            if ( hh[ init[ i ][ j ] ].t <= sr ) {
                break ;
            }
            if ( w_aux[ hh[ init[ i ][ j ] ].c ] >= 1 ) {
                return false ;
            }
            ++ w_aux[ hh[ init[ i ][ j ] ].c ] ;
        }

        for ( int j = 0 ; j < sz ; ++ j ) {
            w[ hh[ init[ i ][ j ] ].c ] = 0 ;
        }
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( hh[ init[ i ][ j ] ].t > sr ) { break ; }
            if ( w[ hh[ init[ i ][ j ] ].c ] >= 2 ) {
                return false ;
            }
            else if ( w[ hh[ init[ i ][ j ] ].c ] == 1 ) {
                if ( w_aux[ hh[ init[ i ][ j ] ].c ] == 1 ) {
                    return false ;
                }
                add_or_clause ( lst_occ[ hh[ init[ i ][ j ] ].c ] , init[ i ][ j ] ) ;
            }
            else {
                lst_occ[ hh[ init[ i ][ j ] ].c ] = init[ i ][ j ] ;
                if ( w_aux[ hh[ init[ i ][ j ] ].c ] == 1 ) {
                    add_or_clause ( init[ i ][ j ] , init[ i ][ j ] ) ;
                }
            }
            ++ w[ hh[ init[ i ][ j ] ].c ] ;
        }
    }
    int tot = m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < keep[ i ] ; ++ j ) {
            add_or_clause ( neg ( init[ i ][ j ] ) , tot + 1 + j ) ;
            if ( j + 1 < keep[ i ] ) {
                add_or_clause ( neg ( tot + 1 + j ) , tot + 1 + j + 1 ) ;
                add_or_clause ( neg ( tot + 1 + j ) , neg ( init[ i ][ j + 1 ] ) ) ;
            }
        }
        tot += keep[ i ] ;
    }
    gen_scc ( ) ;
    for ( int i = 1 ; i <= cnt ; ++ i ) {
        if ( comp[ i ] == comp[ neg ( i ) ] ) {
            return false ;
        }
    }
    return true ;
}



void input ( ) {
    set < int > s ;
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> hh[ i ].x >> hh[ i ].y >> hh[ i ].c >> hh[ i ].t ;
        s.insert ( hh[ i ].c ) ;
        init[ hh[ i ].x ].push_back ( i ) ;
        init[ hh[ i ].y ].push_back ( i ) ;
    }
    map < int , int > trf ;
    int tp = 0 ;
    for ( auto x : s ) {
        trf[ x ] = ++ tp ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        hh[ i ].c = trf[ hh[ i ].c ] ;
    }
    auto cmp = [ & ] ( int x , int y ) {
        return ( hh[ x ].t < hh[ y ].t ) ;
    };
    for ( int i = 1 ; i <= n ; ++ i ) {
        sort ( init[ i ].begin ( ) , init[ i ].end ( ) , cmp ) ;
    }
}

void solve ( ) {
    int l = 0 , r = 1e9 + 3 ;
    if ( f ( r ) == false ) {
        cout << "No\n" ;
        return ;
    }
    while ( r - l > 3 ) {
        int mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { ++ l ; }
    cout << "Yes\n" ;
    cout << l << " " ;
    vector < int > ans ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( hh[ i ].t > l ) { continue ; }
        if ( comp[ i ] > comp[ neg ( i ) ] ) {
            ans.push_back ( i ) ;
        }
    }
    int sz = ans.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
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