#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 2e5 + 7 ;

int n ;
int a[ MAXN ] , pref[ MAXN ] ;
vector < int > v[ MAXN ] ;
int subtree[ MAXN ] , heavy[ MAXN ] ;
int block[ MAXN ] ;


void init ( int x , int prv ) {
    pref[ x ] ^= a[ x ] ;
    subtree[ x ] = 1 ;
    int mx = -1 ;
    for ( auto y : v[ x ] ) {
        if ( y == prv ) { continue ; }
        pref[ y ] = pref[ x ] ;
        init ( y , x ) ;
        subtree[ x ] += subtree[ y ] ;
        if ( mx < subtree[ y ] ) {
            mx = subtree[ y ] ;
            heavy[ x ] = y ;
        }
    }
}

map < int , int > w ;
bool clash ;

void check ( int x , int prv , int ori ) {
    if ( block[ x ] == 1 ) { return ; }
    if ( w[ pref[ x ] ^ ori ] > 0 ) {
        clash = true ;
        return ;
    }
    for ( auto y : v[ x ] ) {
        if ( y == prv || block[ y ] == 1 ) { continue ; }
        check ( y , x , ori ) ;
        if ( clash == true ) { return ; }
    }
}

void rec_add ( int x , int prv , int ori ) {
    if ( block[ x ] == 1 ) { return ; }
    ++ w[ pref[ x ] ] ;
    for ( auto y : v[ x ] ) {
        if ( y == prv || block[ y ] == 1 ) { continue ; }
        rec_add ( y , x , ori ) ;
    }
}

void dfs ( int x , int prv , bool rem ) {
    for ( auto y : v[ x ] ) {
        if ( y == prv || y == heavy[ x ] ) { continue ; }
        dfs ( y , x , false ) ;
    }
    if ( heavy[ x ] != 0 ) {
        dfs ( heavy[ x ] , x , true ) ;
    }
    clash = false ;
    for ( auto y : v[ x ] ) {
        if ( y == prv || y == heavy[ x ] ) { continue ; }
        check ( y , x , a[ x ] ) ;
        if ( clash == true ) { break ; }
        rec_add ( y , x , a[ x ] ) ;
    }
    if ( w[ pref[ x ] ^ a[ x ] ] > 0 ) { clash = true ; }
    ++ w[ pref[ x ] ] ;
    if ( clash == true ) {
        block[ x ] = 1 ;
        w.clear ( ) ;
    }
    if ( rem == false ) {
        w.clear ( ) ;
    }
}

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 , x , y ; i < n ; ++ i ) {
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    init ( 1 , -1 ) ;
    dfs ( 1 , -1 , false ) ;
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += block[ i ] ;
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