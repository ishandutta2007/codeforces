#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

int n , m ;
string a[ MAXN ] ;
bool used[ MAXN ][ MAXN ] ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

int sr ;
int cnt1 , cnt2 ;

bool check ( int x , int y ) {
    if ( x < 0 || x >= n ) { return false ; }
    if ( y < 0 || y >= m ) { return false ; }
    return true ;
}

void upd ( int x , int y ) {
    for ( int i = 0 ; i < 4 ; ++ i ) {
        int nx = x + dx[ i ] ;
        int ny = y + dy[ i ] ;
        if ( check ( nx , ny ) == false ) { continue ; }
        if ( a[ nx ][ ny ] == '.' ) {
            a[ nx ][ ny ] = '#' ;
        }
    }
}

void bfs ( int stx , int sty ) {
    queue < pair < int , int > > q ;
    while ( q.empty ( ) == false ) { q.pop ( ) ; }
    q.push ( { stx , sty } ) ;
    if ( a[ stx ][ sty ] == '#' ) { return ; }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            used[ i ][ j ] = false ;
        }
    }
    while ( q.empty ( ) == false ) {
        pair < int , int > aux ;
        aux = q.front ( ) ;
        q.pop ( ) ;
        if ( a[ aux.first ][ aux.second ] == 'B' ) { ++ cnt2 ; }
        if ( a[ aux.first ][ aux.second ] == 'G' ) { ++ cnt1 ; }
        used[ aux.first ][ aux.second ] = true ;
        for ( int i = 0 ; i < 4 ; ++ i ) {
            int nx = aux.first + dx[ i ] ;
            int ny = aux.second + dy[ i ] ;
            if ( check ( nx , ny ) == false ) { continue ; }
            if ( used[ nx ][ ny ] == true ) { continue ; }
            if ( a[ nx ][ ny ] != '#' ) {
                q.push ( { nx , ny } ) ;
                used[ nx ][ ny ] = true ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sr = 0 ;
    cnt1 = cnt2 = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == 'B' ) {
                upd ( i , j ) ;
            }
            if ( a[ i ][ j ] == 'G' ) { ++ sr ; }
        }
    }    
}

void solve ( ) {
    bfs ( n - 1 , m - 1 ) ;
    if ( cnt2 > 0 || cnt1 < sr ) { cout << "No\n" ; }
    else { cout << "Yes\n" ; }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}