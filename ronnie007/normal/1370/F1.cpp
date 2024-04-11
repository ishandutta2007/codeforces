#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
vector < int > v[ MAXN ] ;

int lvl[ MAXN ] ;
int prv[ MAXN ] ;

vector < int > _aux ;

pair < int , int > ask ( int sr , int w ) {
    _aux.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == w ) { continue ; }
        if ( sr == lvl[ i ] ) { _aux.push_back ( i ) ; }
    }
    int sz = _aux.size ( ) ;
    if ( sz == 0 ) { return { 0 , 0 } ; }
    cout << "? " << sz ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << " " << _aux[ i ] ;
    }
    cout << "\n" ;
    fflush ( stdout ) ;
    pair < int , int > ret ;
    cin >> ret.first >> ret.second ;
    return ret ;
}

void dfs ( int vertex , int lst ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == lst ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        prv[ v[ vertex ][ i ] ] = vertex ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        lvl[ i ] = 0 ;
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    pair < int , int > ret = ask ( 0 , -1 ) ;
    dfs ( ret.first , -1 ) ;
    int l , r , mid ;
    r = ret.second + 1 ;
    l = ( ret.second + 1 ) / 2 ;
    if ( ret.second < 10 ) { l = 0 ; }
    int mx = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        mx = max ( mx , lvl[ i ] ) ;
    }
    if ( r > mx + 1 ) { r = mx + 1 ; }
    int ans1 = 0 ;
    while ( 1 ) {
        mid = ( l + r ) / 2 ;
        pair < int , int > aux = ask ( mid , -1 ) ;
        if ( aux.second == ret.second ) {
            l = mid ;
            ans1 = aux.first ;
        }
        else {
            r = mid ;
            // if ( l + 1 == r ) { ans1 = prv[ aux.first ] ; }
        }
        if ( l + 1 == r ) { break ; }
    }
    if ( ans1 == 0 ) {
        pair < int , int > q = ask ( l , -1 ) ;
        ans1 = q.first ;
    }
    int lft = ret.second - lvl[ ans1 ] ;
    if ( lft == 0 ) {
        cout << "! " << ans1 << " " << ret.first << "\n" ;
        fflush ( stdout ) ;
        return ;
    }
    int hh = ans1 ;
    while ( lvl[ hh ] > lft ) { hh = prv[ hh ] ; }
    pair < int , int > aux = ask ( lft , hh ) ;
    cout << "! " << ans1 << " " << aux.first << "\n" ;
    fflush ( stdout ) ;
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    string ret ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
        cin >> ret ;
        // if ( ret == "Incorrect" ) { return 0 ; }
    }
    return 0 ;
}