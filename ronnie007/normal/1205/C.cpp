#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

int n ;
int a[ MAXN ][ MAXN ] ;

bool vis[ MAXN ][ MAXN ] ;

int dx[ 6 ] = { 2 , -2 , 0 , 0 , 1 , -1 } ;
int dy[ 6 ] = { 0 , 0 , 2 , -2 , 1 , -1 } ;

bool check ( int x , int y ) {
    if ( x < 1 || x > n ) { return false ; }
    if ( y < 1 || y > n ) { return false ; }
    return true ;
}

void dfs ( int x , int y ) {
    vis[ x ][ y ] = true ;
    for ( int i = 0 ; i < 6 ; ++ i ) {
        int nx = x + dx[ i ] ;
        int ny = y + dy[ i ] ;
        if ( check ( nx , ny ) == false ) { continue ; }
        if ( vis[ nx ][ ny ] == true ) { continue ; }
        printf ( "? %d %d %d %d\n" , min ( x , nx ) , min ( y , ny ) , max ( x , nx ) , max ( y , ny ) ) ;
        fflush ( stdout ) ;
        int ret = 0 ;
        scanf ( "%d" , &ret ) ;
        if ( ret == 1 ) {
            a[ nx ][ ny ] = a[ x ][ y ] ;
        }
        else {
            a[ nx ][ ny ] = a[ x ][ y ] ^ 1 ;
        }
        dfs ( nx , ny ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    a[ 1 ][ 1 ] = 1 ;
    a[ n ][ n ] = 0 ;
    vis[ n ][ n ] = true ;
}

void solve ( ) {
    dfs ( 1 , 1 ) ;
    dfs ( 1 , 2 ) ;
    int aux = 0 ;
    bool done = false ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( done == true ) { break ; }
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( done == true ) { break ; }
            for ( int dir1 : { 0 , 2 } ) {
                if ( done == true ) { break ; }
                for ( int dir2 : { 0 , 2 } ) {
                    if ( done == true ) { break ; }
                    for ( int dir3 : { 0 , 2 } ) {
                        if ( done == true ) { break ; }
                        int nx1 = i + dx[ dir1 ] / 2 , ny1 = j + dy[ dir1 ] / 2 ;
                        int nx2 = nx1 + dx[ dir2 ] / 2 , ny2 = ny1 + dy[ dir2 ] / 2 ;
                        int nx3 = nx2 + dx[ dir3 ] / 2 , ny3 = ny2 + dy[ dir3 ] / 2 ;

                        if ( check ( nx3 , ny3 ) == false ) { continue ; }

                        if ( a[ i ][ j ] ^ a[ nx2 ][ ny2 ] == a[ nx1 ][ ny1 ] ^ a[ nx3 ][ ny3 ] ) {
                            printf ( "? %d %d %d %d\n" , i , j , nx3 , ny3 ) ;
                            fflush ( stdout ) ;
                            int hh ;
                            scanf ( "%d" , &hh ) ;
                            if ( hh == 1 && a[ i ][ j ] != a[ nx3 ][ ny3 ] ) {
                                aux = 1 ;
                            }
                            if ( hh == 0 && a[ i ][ j ] == a[ nx3 ][ ny3 ] ) {
                                aux = 1 ;
                            }
                            done = true ;
                        }
                    }
                }
            }
        }
    }
    printf ( "!\n" ) ;
    fflush ( stdout ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( i % 2 ) != ( j % 2 ) ) {
                a[ i ][ j ] ^= aux ;
            }
            printf ( "%d" , a[ i ][ j ] ) ;
            fflush ( stdout ) ;
        }
        printf ( "\n" ) ;
        fflush ( stdout ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}