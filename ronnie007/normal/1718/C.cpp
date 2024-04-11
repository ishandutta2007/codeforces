#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 2e5 + 7 ;
bool comp[ MAXN ] ;
vector < int > v[ MAXN ] ;

multiset < ll > s[ 7 ] ;

void init ( ) {
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        if ( comp[ i ] == true ) { continue ; }
        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            comp[ j ] = true ;
        }
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            if ( comp[ j / i ] == false ) {
                v[ j ].push_back ( i ) ;
            }
        }
    }
}

int n , q ;
int a[ MAXN ] ;
ll sm[ 7 ][ MAXN ] ;

multiset < ll > act ;

void solve ( ) {
    cin >> n >> q ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    int sz = v[ n ].size ( ) ;
    act.clear ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        s[ i ].clear ( ) ;
        for ( int j = 0 ; j < v[ n ][ i ] ; ++ j ) {
            sm[ i ][ j ] = 0 ;
            for ( int t = j ; t < n ; t += v[ n ][ i ] ) {
                sm[ i ][ j ] += a[ t ] ;
            }
            s[ i ].insert ( sm[ i ][ j ] ) ;
        }
        act.insert ( ( *s[ i ].rbegin ( ) ) * v[ n ][ i ]) ;
    }
    cout << *act.rbegin ( ) << "\n" ;
    while ( q -- ) {
        int wh , nw ; cin >> wh >> nw ;
        -- wh ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int ori = ( wh % v[ n ][ i ] ) ;
            auto it = act.lower_bound ( ( *s[ i ].rbegin ( ) ) * v[ n ][ i ] ) ;
            act.erase ( it ) ;
            it = s[ i ].lower_bound ( sm[ i ][ ori ] ) ;
            s[ i ].erase ( it ) ;
            
            sm[ i ][ ori ] -= a[ wh ] ;
            sm[ i ][ ori ] += nw ;
            s[ i ].insert ( sm[ i ][ ori ] ) ;
            act.insert ( ( *s[ i ].rbegin ( ) ) * v[ n ][ i ] ) ;
        }
        a[ wh ] = nw ;
        
        cout << *act.rbegin ( ) << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}