#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 300007
#define LOG 20

int n , q ;
vector < pair < int , int > > v[ MAXN ] ;

int a[ MAXN ] ;
int nxt[ MAXN ][ LOG ] ;

int lst[ LOG ] ;

bool ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( { y , i } ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < LOG ; ++ i ) {
        lst[ i ] = n + 1 ; 
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = 0 ; j < LOG ; ++ j ) {
            nxt[ i ][ j ] = n + 1 ;
        }
        for ( int j = 0 ; j < LOG ; ++ j ) {
            if ( ( a[ i ] & (1<<j) ) != 0 ) {
                nxt[ i ][ j ] = i ;
                if ( lst[ j ] == n + 1 ) { lst[ j ] = i ; continue ; }
                for ( int t = 0 ; t < LOG ; ++ t ) {
                    nxt[ i ][ t ] = min ( nxt[ i ][ t ] , nxt[ lst[ j ] ][ t ] ) ;
                }
                lst[ j ] = i ;
            }
        }
        int sz = v[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int val = v[ i ][ j ].first ;
            int id = v[ i ][ j ].second ;
            for ( int t = 0 ; t < LOG ; ++ t ) {
                if ( ( a[ val ] & (1<<t) ) > 0 ) {
                    if ( nxt[ i ][ t ] <= val ) {
                        ans[ id ] = true ;
                    }
                }
            }
        }
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( ans[ i ] == true ) { printf ( "Shi\n" ) ; }
        else { printf ( "Fou\n" ) ; }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}