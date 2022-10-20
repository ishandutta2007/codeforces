#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = ( 1 << 18 ) ;

int k , n ;
vector < int > v[ MAXN ] ;
int deg[ MAXN ] ;

vector < int > spec ;
bool fl[ MAXN ] ;
int root , cand_parent ;
int prv[ MAXN ] ;
int dep[ MAXN ] ;

void dfs ( int vertex , int lst ) {
    prv[ vertex ] = lst ;
    int cnt = 0 ;
    fl[ vertex ] = true ;
    int hh = -1 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == lst ) { continue ; }
        ++ cnt ;
        dfs ( x , vertex ) ;
        if ( fl[ x ] == false ) {
            fl[ vertex ] = false ;
        }
        else {
            if ( hh < 0 ) { hh = dep[ x ] ; }
            else {
                if ( hh != dep[ x ] ) {
                    fl[ vertex ] = false ; 
                }
            }
        }
    }
    if ( cnt != 2 && cnt != 0 ) {
        fl[ vertex ] = false ;
    }
    if ( fl[ vertex ] == true ) { 
        if ( cnt == 0 ) {
            dep[ vertex ] = 1 ;
        }
        else {
            dep[ vertex ] = hh + 1 ;
        }
    }
}

bool f ( ) {
    if ( deg[ root ] != 2 ) { return false ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        fl[ i ] = false ;
    }
    dfs ( root , -1 ) ;
    int lft = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fl[ i ] == false ) { ++ lft ; }
    }
    int wh = cand_parent ;
    while ( wh != root ) {
        if ( fl[ wh ] == false ) { -- lft ; }
        wh = prv[ wh ] ;
    }
    if ( fl[ wh ] == false ) { -- lft ; }
    return ( lft == 0 ) ;
}

int lft[ MAXN ] ;
int at_dist[ MAXN ][ 19 ] ;
set < pair < int , int > > edgelist ;
set < int > updated[ MAXN ] ;

void solve ( ) {
    cin >> k ;
    n = ( 1 << k ) - 2 ;
    for ( int i = 1 , x , y ; i <= n - 1 ; ++ i ) {
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        edgelist.insert ( { x , y } ) ;
        edgelist.insert ( { y , x } ) ;
        ++ deg[ x ] , ++ deg[ y ] ;
    }
    if ( k == 2 ) {
        cout << "2\n" ;
        cout << "1 2\n" ;
        return ;
    }
    int cnt1 = 0 , cnt2 = 0 , cnt4 = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( deg[ i ] > 4 ) {
            cout << "0\n" ;
            return ;
        }
        if ( deg[ i ] == 1 ) { ++ cnt1 ; }
        if ( deg[ i ] == 2 ) {
            ++ cnt2 ;
            spec.push_back ( i ) ;
        }
        if ( deg[ i ] == 4 ) {
            ++ cnt4 ;
            spec.push_back ( i ) ;
        }
    }
    queue < int > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        at_dist[ i ][ 0 ] = 1 ;
        lft[ i ] = deg[ i ] - 1 ;
        if ( deg[ i ] == 1 ) {
            q.push ( i ) ;
            lft[ i ] = -2 ;
        }
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( auto y : v[ x ] ) {
            -- lft[ y ] ;
            if ( updated[ y ].find ( x ) == updated[ y ].end ( ) ) {
                for ( int i = 1 ; i < k ; ++ i ) {
                    at_dist[ y ][ i ] += at_dist[ x ][ i - 1 ] ;
                }
                updated[ x ].insert ( y ) ;
            }
            if ( lft[ y ] == 0 ) {
                q.push ( y ) ;
                lft[ y ] = -2 ;
            }
        }
    }
    if ( cnt2 + cnt4 > 0 ) {
        if ( cnt2 == 0 ) {
            cout << "0\n" ;
            return ;
        }
        if ( cnt2 + cnt4 > 2 ) {
            cout << "0\n" ;
            return ;
        }
        int sr = ( 1 << ( k - 1 ) ) ;
        if ( cnt1 != sr ) {
            if ( cnt1 != sr - 1 ) {
                cout << "0\n" ;
                return ;
            }
            if ( cnt2 != 2 ) {
                cout << "0\n" ;
                return ;
            }
        }
        else {
            if ( cnt4 != 1 ) {
                cout << "0\n" ;
                return ;
            }
        }
        vector < int > ans ;
        for ( int i = 0 ; i < 2 ; ++ i ) {
            root = spec[ i ] ;
            cand_parent = spec[ i ^ 1 ] ;
            if ( f ( ) == true && at_dist[ root ][ k - 1 ] > sr / 2 ) {
                ans.push_back ( cand_parent ) ;
            }
        }
        cout << ans.size ( ) << "\n" ;
        if ( ans.size ( ) > 0 ) {
            for ( auto x : ans ) {
                cout << x << " " ;
            }
            cout << "\n" ;
        }
        return ;
    }
    int sr = ( 1 << ( k - 1 ) ) ;
    if ( cnt1 != sr ) {
        cout << "0\n" ;
        return ;
    }
    vector < int > ans ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( at_dist[ i ][ k - 2 ] >= sr / 2 ) {
            ans.push_back ( i ) ;
        }
    }
    if ( ans.size ( ) == 2 ) {
        if ( edgelist.find ( { ans[ 0 ] , ans[ 1 ] } ) != edgelist.end ( ) ) {
            if ( at_dist[ ans[ 0 ] ][ k - 2 ] == sr / 2 && at_dist[ ans[ 1 ] ][ k - 2 ] == sr / 2 + sr / 4 ) {
                cout << "2\n" ;
                cout << ans[ 0 ] << " " << ans[ 1 ] << "\n" ;
                return ;
            }
            if ( at_dist[ ans[ 0 ] ][ k - 2 ] == sr / 2 + sr / 4 && at_dist[ ans[ 1 ] ][ k - 2 ] == sr / 2 ) {
                cout << "2\n" ;
                cout << ans[ 0 ] << " " << ans[ 1 ] << "\n" ;
                return ;
            }            
        }
    }
    cout << "0\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}