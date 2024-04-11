#include<bits/stdc++.h>
using namespace std ;

#define MAXN 257

int n , m ;
int a[ MAXN ][ MAXN ] ;

bool mx_row[ MAXN * MAXN ] ;
bool mx_col[ MAXN * MAXN ] ;
bool pushed[ MAXN ][ MAXN ] ;

int ans[ MAXN ][ MAXN ] ;

vector < pair < int , int > > ord ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = 0 ;
        for ( int j = 1 ; j <= m ; ++ j ) {
            aux = max ( aux , a[ i ][ j ] ) ;
        }
        mx_row[ aux ] = true ;
    }
    for ( int j = 1 ; j <= m ; ++ j ) {
        int aux = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            aux = max ( aux , a[ i ][ j ] ) ;
        }
        mx_col[ aux ] = true ;
    }
    int x = n + 1 , y = m + 1 ; 
    for ( int val = n * m ; val >= 1 ; -- val ) {
        if ( mx_row[ val ] == false && mx_col[ val ] == false ) { continue ; }
        if ( mx_row[ val ] == true ) { -- x ; }
        if ( mx_col[ val ] == true ) { -- y ; }
        ans[ x ][ y ] = val ;
        ord.push_back ( { x , y } ) ;
    }
    int tpsz = 0 ;
    queue < pair < int , int > > q ;
    for ( int i = n * m ; i >= 1 ; -- i ) {
        if ( mx_row[ i ] == true || mx_col[ i ] == true ) {
            for ( int hh = ord[ tpsz ].first + 1 ; hh <= n ; ++ hh ) {
                if ( ans[ hh ][ ord[ tpsz ].second ] > 0 ) { continue ; }
                if ( pushed[ hh ][ ord[ tpsz ].second ] == true ) { continue ; }
                pushed[ hh ][ ord[ tpsz ].second ] = true ;
                q.push ( { hh , ord[ tpsz ].second } ) ;
            }
            for ( int hh = ord[ tpsz ].second + 1 ; hh <= m ; ++ hh ) {
                if ( ans[ ord[ tpsz ].first ][ hh ] > 0 ) { continue ; }
                if ( pushed[ ord[ tpsz ].first ][ hh ] == true ) { continue ; }
                pushed[ ord[ tpsz ].first ][ hh ] = true ;
                q.push ( { ord[ tpsz ].first , hh } ) ;
            }
            ++ tpsz ;
        }
        else {
            auto [ nx , ny ] = q.front ( ) ;
            q.pop ( ) ;
            ans[ nx ][ ny ] = i ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            printf ( "%d " , ans[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }
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