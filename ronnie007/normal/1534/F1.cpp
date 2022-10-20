#include<bits/stdc++.h>
using namespace std ;

#define MAXN 400007

int n , m ;
vector < string > a ;
vector < int > need ;

vector < vector < int > > wh ;
int revwh[ MAXN ] ;
vector < int > lims ;

vector < int > lst_row ;
vector < int > gr[ MAXN ] ;
vector < int > revgr[ MAXN ] ;

vector < int > v[ MAXN ] ;
int mxvert , mxcomp ;
int comp[ MAXN ] ;
bool used[ MAXN ] ;
bool spec_vert[ MAXN ] ;
bool spec_comp[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    a.resize ( n ) ; wh.resize ( n ) , lims.resize ( m ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    need.resize ( m ) ;
    for ( int i = 0 ; i < m ; ++ i ) {
        cin >> need[ i ] ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        wh[ i ].resize ( m ) ;
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == '#' ) {
                wh[ i ][ j ] = ++ mxvert ;
                revwh[ mxvert ] = j ;
            }
            else {
                wh[ i ][ j ] = 0 ; 
            }
        }
    }
    lst_row.resize ( m ) ;
    for ( int i = 0 ; i < m ; ++ i ) {
        lst_row[ i ] = -1 ;
    }
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] != '#' ) { continue ; }
            if ( lst_row[ j ] != -1 ) {
                gr[ wh[ i ][ j ] ].push_back ( wh[ lst_row[ j ] ][ j ] ) ;
            }
            lst_row[ j ] = i ;            
        }
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] != '#' ) { continue ; }
            if ( i > 0 && a[ i - 1 ][ j ] == '#' ) {
                gr[ wh[ i ][ j ] ].push_back ( wh[ i - 1 ][ j ] ) ;
            }
            if ( j > 0 && lst_row[ j - 1 ] != -1 ) {
                gr[ wh[ i ][ j ] ].push_back ( wh[ lst_row[ j - 1 ] ][ j - 1 ] ) ;
            }
            if ( j < m - 1 && lst_row[ j + 1 ] != -1 ) {
                gr[ wh[ i ][ j ] ].push_back ( wh[ lst_row[ j + 1 ] ][ j + 1 ] ) ;
            }
        }
    }
    for ( int i = 1 ; i <= mxvert ; ++ i ) {
        for ( auto x : gr[ i ] ) {
            revgr[ x ].push_back ( i ) ;
        }
    }
    for ( int j = 0 ; j < m ; ++ j ) {
        int lft = need[ j ] ;
        for ( int i = n - 1 ; i >= 0 ; -- i ) {
            if ( a[ i ][ j ] != '#' ) { continue ; }
            if ( lft == 0 ) { break ; }
            if ( lft == 1 ) {
                spec_vert[ wh[ i ][ j ] ] = true ;
            }
            -- lft ;
            if ( lft == 0 ) { break ; }
        }
    }
}

stack < int > s ;

void dfs ( int vertex ) {
    used[ vertex ] = true ;
    for ( auto x : gr[ vertex ] ) {
        if ( used[ x ] == false ) {
            dfs ( x ) ;
        }
    }
    s.push ( vertex ) ;
}

void rev_dfs ( int vertex , int id ) {
    comp[ vertex ] = id ;
    for ( auto x : revgr[ vertex ] ) {
        if ( comp[ x ] == 0 ) {
            rev_dfs ( x , id ) ;
        }
    }
}

set < int > act_edges[ MAXN ] ;
int indeg[ MAXN ] ;


void build_scc ( ) {
    for ( int i = 1 ; i <= mxvert ; ++ i ) {
        if ( used[ i ] == false ) {
            dfs ( i ) ;
        }
    }
    while ( s.empty ( ) == false ) {
        int x = s.top ( ) ;
        s.pop ( ) ;
        if ( comp[ x ] > 0 ) { continue ; }
        rev_dfs ( x , ++ mxcomp ) ;
    }
    for ( int i = 1 ; i <= mxvert ; ++ i ) {
        spec_comp[ comp[ i ] ] |= spec_vert[ i ] ;
        for ( auto x : gr[ i ] ) {
            if ( comp[ i ] == comp[ x ] ) { continue ; }
            act_edges[ comp[ i ] ].insert ( comp[ x ] ) ;
        }
    }
    for ( int i = 1 ; i <= mxcomp ; ++ i ) {
        for ( auto x : act_edges[ i ] ) {
            v[ i ].push_back ( x ) ;
            ++ indeg[ x ] ;
        }
    }
}

vector < pair < int , int > > srt ;
int mncol[ MAXN ] ;

int spec_revid[ MAXN ] , bad[ MAXN ] ;

pair < int , int > intervals[ MAXN ] ;

void obtain ( int vertex ) {
    used[ vertex ] = true ;
    intervals[ vertex ] = { MAXN , -MAXN } ;
    if ( spec_comp[ vertex ] == true && bad[ vertex ] == false ) {
        intervals[ vertex ] = { spec_revid[ vertex ] , spec_revid[ vertex ] } ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( used[ x ] == false ) { obtain ( x ) ; }
        intervals[ vertex ].first = min ( intervals[ vertex ].first , intervals[ x ].first ) ;
        intervals[ vertex ].second = max ( intervals[ vertex ].second , intervals[ x ].second ) ;
    }
}

vector < int > stlines[ MAXN ] ;

void bfs ( ) {
    queue < int > q ;
    for ( int i = 1 ; i <= mxcomp ; ++ i ) {
        if ( indeg[ i ] == 0 ) { q.push ( i ) ; }
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( auto y : v[ x ] ) {
            -- indeg[ y ] ;
            if ( indeg[ y ] == 0 ) { q.push ( y ) ; }
            if ( bad[ x ] == true || spec_comp[ x ] == true ) {
                bad[ y ] = true ;
            }
        }
    }
}

void solve ( ) {
    build_scc ( ) ;
    for ( int i = 1 ; i <= mxcomp ; ++ i ) {
        mncol[ i ] = MAXN ;
    }
    for ( int i = 1 ; i <= mxvert ; ++ i ) {
        if ( spec_vert[ i ] == true ) {
            mncol[ comp[ i ] ] = min ( mncol[ comp[ i ] ] , revwh[ i ] ) ;
        }
    }
    for ( int i = 1 ; i <= mxcomp ; ++ i ) {
        used[ i ] = false ;
    }
    bfs ( ) ;
    for ( int i = 1 ; i <= mxcomp ; ++ i ) {
        if ( spec_comp[ i ] == true && bad[ i ] == false ) {
            srt.push_back ( { mncol[ i ] , i } ) ;
        }
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    int sz = srt.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        spec_revid[ srt[ i ].second ] = i + 1 ;
    }

    for ( int i = 1 ; i <= mxcomp ; ++ i ) {
        used[ i ] = false ;
    }
    for ( int i = 1 ; i <= mxcomp ; ++ i ) {
        if ( used[ i ] == true ) { continue ; }
        obtain ( i ) ;
    }
    for ( int i = 1 ; i <= mxcomp ; ++ i ) {
        if ( intervals[ i ].first != MAXN ) {
            stlines[ intervals[ i ].first ].push_back ( intervals[ i ].second ) ;
        }
    }
    int ans = 0 ;
    int mxcovered = 0 ;
    int mxend = 0 ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        for ( auto x : stlines[ i ] ) {
            mxend = max ( mxend , x ) ;
        }
        if ( mxcovered < i ) {
            ++ ans ;
            mxcovered = mxend ;
        }
    }

    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}