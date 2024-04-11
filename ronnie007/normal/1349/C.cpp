#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007
#define inf 100000007
int n , m , cnt ;
string a[ MAXN ] ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

int dist[ MAXN ][ MAXN ] ;

queue < pair < int , int > > q ;

bool check ( int x , int y ) {
    if ( x < 0 || n <= x ) { return false ; }
    if ( y < 0 || m <= y ) { return false ; }
    return true ;
}

void proc ( int x , int y ) {
    for ( int i = 0 ; i < 4 ; ++ i ) {
        int nx = x + dx[ i ] ;
        int ny = y + dy[ i ] ;
        if ( check ( nx , ny ) == false ) { continue ; }
        if ( a[ nx ][ ny ] == a[ x ][ y ] ) {
            dist[ x ][ y ] = 0 ;
            q.push ( { x , y } ) ;
            return ;
        }
    }
}

void input ( ) {
    cin >> n >> m >> cnt ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            dist[ i ][ j ] = inf ;
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            proc ( i , j ) ;
        }
    }
    while ( q.empty ( ) == false ) {
        pair < int , int > aux = q.front ( ) ;
        q.pop ( ) ;
        for ( int i = 0 ; i < 4 ; ++ i ) {
            int nx = aux.first + dx[ i ] ;
            int ny = aux.second + dy[ i ] ;
            if ( check ( nx , ny ) == false ) { continue ; }
            if ( dist[ nx ][ ny ] == inf ) {
                dist[ nx ][ ny ] = dist[ aux.first ][ aux.second ] + 1 ;
                q.push ( { nx , ny } ) ;
            }
        }
    }
    while ( cnt -- ) {
        int x , y ;
        long long p ;
        cin >> x >> y >> p ;
        -- x ; -- y ;
        if ( p <= dist[ x ][ y ] || dist[ x ][ y ] == inf ) {
            cout << ( a[ x ][ y ] - '0' ) << "\n" ;
        }
        else {
            p -= dist[ x ][ y ] ;
            p %= 2 ;
            if ( p == 0 ) {
                cout << ( a[ x ][ y ] - '0' ) << "\n" ;
            }
            else {
                int hh = ( a[ x ][ y ] - '0' ) ;
                cout << ( hh ^ 1 ) << "\n" ;
            }
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}