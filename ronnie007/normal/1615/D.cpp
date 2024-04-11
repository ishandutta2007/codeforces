#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 400007

int n , m ;
struct edge {
    int x , y ;
    int cost ;
};
edge w[ MAXN ] ;
vector < pair < int , int > > aux[ MAXN ] ;

pair < int , int > prv[ MAXN ] ;

vector < int > v[ MAXN ] ;
vector < int > rv[ MAXN ] ;

void dfs ( int vertex , int lst ) {
    for ( auto [ x , id ] : aux[ vertex ] ) {
        if ( x == lst ) { continue ; }
        prv[ x ] = { vertex , id } ;
        dfs ( x , vertex ) ;
    }
}

int get ( int x ) {
    return __builtin_popcount ( x ) % 2 ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        v[ i ].clear ( ) ;
        rv[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        cin >> w[ i ].x >> w[ i ].y >> w[ i ].cost ;
        aux[ w[ i ].x ].push_back ( { w[ i ].y , i } ) ;
        aux[ w[ i ].y ].push_back ( { w[ i ].x , i } ) ;
    }
    dfs ( 1 , -1 ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , z ;
        cin >> x >> y >> z ;
        if ( z == 0 ) {
            v[ x ].push_back ( y ) ;
            v[ y ].push_back ( x ) ;

            v[ n + x ].push_back ( n + y ) ;
            v[ n + y ].push_back ( n + x ) ;
        }

        else {
            v[ x ].push_back ( n + y ) ;
            v[ n + y ].push_back ( x ) ;

            v[ n + x ].push_back ( y ) ;
            v[ y ].push_back ( n + x ) ;
        }
    }
}

stack < int > s ;
bool used[ MAXN ] ;
int comp[ MAXN ] ;

void dfs_fw ( int vertex ) {
    used[ vertex ] = true ;
    for ( auto x : v[ vertex ] ) {
        if ( used[ x ] == true ) { continue ; }
        dfs_fw ( x ) ;
    }
    s.push ( vertex ) ;
}

void dfs_rv ( int vertex , int val ) {
    comp[ vertex ] = val ;
    for ( auto x : rv[ vertex ] ) {
        if ( comp[ x ] != 0 ) { continue ; }
        dfs_rv ( x , val ) ;
    }
}

int final_col[ MAXN ] ;

void solve ( ) {
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x = prv[ i ].first , y = i ;
        int id = prv[ i ].second ;
        if ( w[ id ].cost == -1 ) { continue ; }
        if ( get ( w[ id ].cost ) == 0 ) {
            v[ x ].push_back ( y ) ;
            v[ y ].push_back ( x ) ;

            v[ n + x ].push_back ( n + y ) ;
            v[ n + y ].push_back ( n + x ) ;
        }
        else {
            v[ x ].push_back ( n + y ) ;
            v[ n + y ].push_back ( x ) ;

            v[ n + x ].push_back ( y ) ;
            v[ y ].push_back ( n + x ) ;            
        }
    }
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        for ( auto x : v[ i ] ) {
            rv[ x ].push_back ( i ) ;
        }
    }
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        used[ i ] = false , comp[ i ] = 0 ; 
    }
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        if ( used[ i ] == false ) {
            dfs_fw ( i ) ;
        }
    }
    int tp = 0 ;
    while ( s.empty ( ) == false ) {
        int x = s.top ( ) ;
        s.pop ( ) ;
        if ( comp[ x ] != 0 ) { continue ; }
        dfs_rv ( x , ++ tp ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( comp[ i ] == comp[ n + i ] ) {
            cout << "NO\n" ;
            return ;
        }
        if ( comp[ i ] > comp[ n + i ] ) {
            final_col[ i ] = 0 ;
        }
        else {
            final_col[ i ] = 1 ;
        }
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x = prv[ i ].first , id = prv[ i ].second ;
        if ( w[ id ].cost != -1 ) { continue ; }
        if ( final_col[ x ] != final_col[ i ] ) {
            w[ id ].cost = 1 ;
        }
        else {
            w[ id ].cost = 0 ;
        }
    }
    cout << "YES\n" ;
    for ( int i = 1 ; i < n ; ++ i ) {
        cout << w[ i ].x << " " << w[ i ].y << " " << w[ i ].cost << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}