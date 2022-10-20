#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007
long long MOD = 998244353LL * 174343 + 2 ;

int BASE[ 2 ] = { 26 , 3257 } ;

struct hsh {
    long long h[ 2 ] ;
    hsh ( ) { h[ 0 ] = h[ 1 ] = 0 ; }
    void advance ( int x ) {
        for ( auto i : { 0 , 1 } ) {
            h[ i ] = ( 1LL * h[ i ] * BASE[ i ] + x ) % MOD ;
        }
    }
    bool operator < ( hsh other ) const {
        return h[ 0 ] < other.h[ 0 ] ;
    }
};

set < hsh > s ;


int n ;
int val[ MAXN ] ;
string a ;
vector < int > v[ MAXN ] ;

int subtree[ MAXN ] ;
hsh path[ MAXN ] ;
int add[ MAXN ] ;

void init ( int vertex , int prv ) {
    subtree[ vertex ] = 1 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        path[ x ] = path[ vertex ] ;
        path[ x ].advance ( a[ x ] - 'a' + 1 ) ;
        init ( x , vertex ) ;
        subtree[ vertex ] += subtree[ x ] ;
    }
}

void rec_add ( int vertex , int prv ) {
    s.insert ( path[ vertex ] ) ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        rec_add ( x , vertex ) ;
    }
}

void dfs ( int vertex , int prv , bool fl ) {
    int mx = 0 ;
    int id = -1 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        if ( mx < subtree[ x ] ) {
            mx = subtree[ x ] ;
            id = x ;
        }
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv || x == id ) { continue ; }
        dfs ( x , vertex , false ) ;
    }
    if ( id > -1 ) {
        dfs ( id , vertex , true ) ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv || x == id ) { continue ; }
        rec_add ( x , vertex ) ;
    }
    s.insert ( path[ vertex ] ) ;
    add[ vertex ] = s.size ( ) ;
    if ( fl == false ) { s.clear ( ) ; }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> val[ i ] ;
    }
    cin >> a ;
    a = '#' + a ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    path[ 1 ] = hsh ( ) ;
    path[ 1 ].advance ( a[ 1 ] - 'a' + 1 ) ;
    init ( 1 , -1 ) ;
    dfs ( 1 , -1 , true ) ;
    int mx = -1 ;
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mx < val[ i ] + add[ i ] ) {
            mx = val[ i ] + add[ i ] ;
            cnt = 0 ;
        }
        cnt += ( mx == ( val[ i ] + add[ i ] ) ) ;
    }
    cout << mx << " " << cnt << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}