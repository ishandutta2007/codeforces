#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2007

int n , m ;
int stx , sty ;
int limx , limy ;

string a[ MAXN ] ;

bool vis[ MAXN ][ MAXN ] ;
int dist[ MAXN ][ MAXN ] ;

queue < pair < int , int > > q ;

int dx[ 3 ] = { 1 , -1 , 0 } ;
int dy[ 3 ] = { 0 , 0 , 1 } ;

void add_column ( int x , int y ) {
    for ( int i = 0 ; i < 3 ; ++ i ) {
        int nx , ny ;
        nx = x + dx[ i ] ;
        ny = y + dy[ i ] ;
        if ( nx < 0 || n <= nx ) { continue ; }
        if ( ny < 0 || m <= ny ) { continue ; }
        if ( vis[ nx ][ ny ] == true || a[ nx ][ ny ] == '*' ) { continue ; }
        dist[ nx ][ ny ] = dist[ x ][ y ] ;
        vis[ nx ][ ny ] = true ;
        q.push ( { nx , ny } ) ;
        add_column ( nx , ny ) ;
    }
}

void bfs ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            dist[ i ][ j ] = 4 * MAXN ; 
        }
    }
    dist[ stx ][ sty ] = 0 ;
    vis[ stx ][ sty ] = true ;
    q.push ( { stx , sty } ) ;
    add_column ( stx , sty ) ;
    while ( q.empty ( ) == false ) {
        pair < int , int > aux = q.front ( ) ;
        q.pop ( ) ;
        if ( aux.second > 0 ) {
            if ( a[ aux.first ][ aux.second - 1 ] != '*' && vis[ aux.first ][ aux.second - 1 ] == false ) {
                q.push ( { aux.first , aux.second - 1 } ) ;
                dist[ aux.first ][ aux.second - 1 ] = dist[ aux.first ][ aux.second ] + 1 ;
                vis[ aux.first ][ aux.second - 1 ] = true ;
                add_column ( aux.first , aux.second - 1 ) ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    cin >> stx >> sty ;
    cin >> limx >> limy ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    -- stx ; -- sty ;
}

void solve ( ) {
    bfs ( ) ;
    int ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == '*' ) { continue ; }
            if ( vis[ i ][ j ] == false ) { continue ; }
            int cnt = j - sty + dist[ i ][ j ] ;
            if ( dist[ i ][ j ] <= limx && cnt <= limy ) { ++ ans ; }
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}