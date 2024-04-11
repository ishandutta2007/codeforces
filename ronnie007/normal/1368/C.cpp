#include<bits/stdc++.h>
using namespace std ;

#define MAXN 607

int n ;

int a[ MAXN ][ MAXN ] ; 
int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;


vector < pair < int , int > > v ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i + 1 ][ i + 1 ] = 1 ;
        v.push_back ( { i + 1 , i + 1 } ) ;
    }
    for ( int i = 1 ; i <= n + 3 ; ++ i ) {
        for ( int j = 1 ; j <= n + 3 ; ++ j ) {
            for ( int z = 0 ; z < 4 ; ++ z ) {
                int nx = i + dx[ z ] ;
                int ny = j + dy[ z ] ;
                if ( a[ nx ][ ny ] == 1 ) {
                    v.push_back ( { i , j } ) ;
                    break ;
                }
            }
        }
    }
    v.push_back ( { 1 , 1 } ) ;
    v.push_back ( { n + 2 , n + 2 } ) ;
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}