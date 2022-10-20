#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m , k ;
vector < int > v[ MAXN ] ;
unordered_set < int > s[ MAXN ] ;
int deg[ MAXN ] ;
bool used[ MAXN ] ;

priority_queue < pair < int , int > > q ;

bool check ( int ori ) {
    vector < int > aux ;
    aux.push_back ( ori ) ;
    for ( auto x : v[ ori ] ) {
        if ( used[ x ] == true ) { aux.push_back ( x ) ; }
    }
    int sz = k ;
    for ( int i = 0 ; i < k ; ++ i ) {
        for ( int j = i + 1 ; j < k ; ++ j ) {
            if ( s[ aux[ i ] ].find ( aux[ j ] ) == s[ aux[ i ] ].end ( ) ) { return false ; }
        }
    }
    printf ( "2\n" ) ;
    for ( int i = 0 ; i < k ; ++ i ) {
        printf ( "%d " , aux[ i ] ) ;
    }
    printf ( "\n" ) ;
    return true ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        s[ i ].clear ( ) ;
        deg[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ; scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ; ++ deg[ x ] ;
        v[ y ].push_back ( x ) ; ++ deg[ y ] ;
        s[ x ].insert ( y ) ; s[ y ].insert ( x ) ;
    }
}

void solve ( ) {
    if ( 1LL * k * ( k - 1 ) > 2 * m ) {
        printf ( "-1\n" ) ;
        return ;
    }
    while ( q.empty ( ) == false ) { q.pop ( ) ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = true ;
        q.push ( { - deg[ i ] , i } ) ;
    }
    while ( q.empty ( ) == false ) {
        auto [ cnt , vertex ] = q.top ( ) ;
        q.pop ( ) ;
        if ( used[ vertex ] == false ) { continue ; }        
        cnt = -cnt ;
        if ( cnt != deg[ vertex ] ) { continue ; }
        if ( cnt == k - 1 ) {
            if ( check ( vertex ) == true ) { return ; }
        }     
        if ( cnt >= k ) { break ; }
        used[ vertex ] = false ;
        for ( auto x : v[ vertex ] ) {
            if ( used[ x ] == true ) {
                -- deg[ x ] ;
                q.push ( { - deg[ x ] , x } ) ;
            }
        }
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += used[ i ] ;
    }
    if ( ans > 0 ) {
        printf ( "1 %d\n" , ans ) ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( used[ i ] == true ) { printf ( "%d " , i ) ; }
        }
        printf ( "\n" ) ;
        return ;
    }
    printf ( "-1\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // t = 1 ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}