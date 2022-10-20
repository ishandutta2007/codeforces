#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2e5 + 7 ;

int n ;
string a ;
int cnt[ 26 ] ;

int eval ( ) {
    int mx = 0 ;
    int sm = 0 ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        sm += cnt[ i ] ;
        mx = max ( mx , cnt[ i ] ) ;
    }
    return max ( mx , ( sm + 1 ) / 2 ) ;
}

bool f ( int x , int y ) {
    if ( x == y ) { return false ; }
    int sr = eval ( ) ;
    -- cnt[ x ] , -- cnt[ y ] ;
    int nw = eval ( ) ;
    ++ cnt[ x ] , ++ cnt[ y ] ;
    if ( nw == sr - 1 ) { return true ; }
    return false ;
}

class fenw {
public :
    int tr[ MAXN ] ;
    void init ( ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            tr[ i ] = 0 ;
        }
    }
    void upd ( int wh , int val ) {
        for ( int i = wh ; i <= n ; i += ( i & ( -i ) ) ) {
            tr[ i ] += val ;
        }
    }
    int query ( int wh ) {
        int ret = 0 ;
        for ( int i = wh ; i > 0 ; i -= ( i & ( -i ) ) ) {
            ret += tr[ i ] ;
        }
        return ret ;
    }
};
fenw w ;
set < int > s ;

void solve ( ) {
    cin >> a ;
    n = a.size ( ) ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        if ( a[ i ] == a[ i + 1 ] ) {
            ++ cnt[ ( a[ i ] - 'a' ) ] ;
        }
    }
    vector < pair < int , int > > v ;
    vector < pair < int , int > > ans ;
    int tp = 0 ;
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        if ( a[ i ] != a[ i + 1 ] ) { continue ; }
        if ( tp > 0 && f ( v[ tp - 1 ].second , a[ i ] - 'a' ) == true ) {
            pair < int , int > aux = v[ tp - 1 ] ;
            v.pop_back ( ) , -- tp ;
            ans.push_back ( { aux.first + 1 , i } ) ;
            -- cnt[ aux.second ] , -- cnt[ ( a[ i ] - 'a' ) ] ;
        }
        else {
            v.push_back ( { i , a[ i ] - 'a' } ) ;
            ++ tp ;
        }
    }
    for ( auto aux : v ) {
        ans.push_back ( { 0 , aux.first } ) ;
    }
    ans.push_back ( { 0 , n - 1 } ) ;
    w.init ( ) ;
    s.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        w.upd ( i , 1 ) ;
        s.insert ( i ) ;
    }
    cout << (int) ans.size ( ) << "\n" ;
    for ( auto [ l , r ] : ans ) {
        int hh1 = w.query ( l ) ;
        int hh2 = w.query ( r + 1 ) ;
        while ( 1 ) {
            auto it = s.lower_bound ( l + 1 ) ;
            if ( it == s.end ( ) || (*it) > r + 1 ) { break ; }
            w.upd ( (*it) , -1 ) ;
            s.erase ( (*it) ) ;
        }
        cout << hh1 + 1 << " " << hh2 << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}