#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , m , k ;
int a[ MAXN ][ MAXN ] ;
int f[ 41 ][ MAXN ][ MAXN ] ;

int dist[ 41 ][ 41 ] ;

queue < pair < int , int > > q ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

bool check ( int x , int y ) {
    if ( x < 1 || x > n ) { return false ; }
    if ( y < 1 || y > m ) { return false ; }
    return true ;
}

void bfs ( int id ) {
    while ( q.empty ( ) == false ) {
        pair < int , int > aux = q.front ( ) ;
        q.pop ( ) ;
        for ( int i = 0 ; i < 4 ; ++ i ) {
            int nx = aux.first + dx[ i ] ;
            int ny = aux.second + dy[ i ] ;
            if ( check ( nx , ny ) == false ) { continue ; }
            if ( f[ id ][ nx ][ ny ] >= 0 ) { continue ; }
            f[ id ][ nx ][ ny ] = f[ id ][ aux.first ][ aux.second ] + 1 ;
            q.push ( { nx , ny } ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= k ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            for ( int t = 1 ; t <= m ; ++ t ) {
                f[ i ][ j ][ t ] = -1 ;
                if ( a[ j ][ t ] == i ) {
                    f[ i ][ j ][ t ] = 0 ;
                    q.push ( { j , t } ) ;
                }
            }
        }
        bfs ( i ) ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        for ( int j = 1 ; j <= k ; ++ j ) {
            dist[ i ][ j ] = -1 ;
        }
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            for ( int t = 1 ; t <= m ; ++ t ) {
                int c = a[ j ][ t ] ;
                if ( f[ i ][ j ][ t ] > -1 ) {
                    if ( dist[ i ][ c ] < 0 ) {
                        dist[ i ][ c ] = f[ i ][ j ][ t ] ;
                    }
                    dist[ i ][ c ] = min ( dist[ i ][ c ] , f[ i ][ j ][ t ] ) ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        for ( int j = 1 ; j <= k ; ++ j ) {
            if ( dist[ i ][ j ] < 0 ) { continue ; }
            ++ dist[ i ][ j ] ;
        }
    }
    for ( int t = 1 ; t <= k ; ++ t ) {
        for ( int i = 1 ; i <= k ; ++ i ) {
            for ( int j = 1 ; j <= k ; ++ j ) {
                if ( dist[ i ][ t ] < 0 || dist[ t ][ j ] < 0 ) { continue ; }
                dist[ i ][ j ] = min ( dist[ i ][ j ] , dist[ i ][ t ] + dist[ t ][ j ] ) ;
            }
        }
    }
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int r1 , c1 , r2 , c2 ;
        scanf ( "%d%d%d%d" , &r1 , &c1 , &r2 , &c2 ) ;
        int ans = abs ( r1 - r2 ) + abs ( c1 - c2 ) ;
        for ( int i = 1 ; i <= k ; ++ i ) {
            for ( int j = 1 ; j <= k ; ++ j ) {
                int aux = dist[ i ][ j ] + f[ i ][ r1 ][ c1 ] + f[ j ][ r2 ][ c2 ] ;
                if ( i != j ) { ++ aux ; }
                ans = min ( ans , aux ) ;
            }
        }
        printf ( "%d\n" , ans ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}