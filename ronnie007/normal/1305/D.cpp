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
#include<random>
using namespace std ;

#define MAXN 1007

int n ;
vector < int > v[ MAXN ] ;
int sz[ MAXN ] ;
bool h[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        sz[ i ] = v[ i ].size ( ) ;
    }
    while ( 1 ) {
        int x , y ;
        x = y = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( sz[ i ] == 1 ) {
                if ( x == 0 ) { x = i ; }
                else { y = i ; break ; }
            }
        }
        if ( y == 0 ) {
            for ( int i = 1 ; i <= n ; ++ i ) {
                if ( h[ i ] == false ) { x = i ; break ; }
            }
            printf ( "! %d\n" , x ) ;
            fflush ( stdout ) ;
            return ;
        }
        else {
            h[ x ] = h[ y ] = true ;
            printf ( "? %d %d\n" , x , y ) ;
            fflush ( stdout ) ;
            int ret ;
            scanf ( "%d" , &ret ) ;
            if ( ret == x || ret == y ) {
                printf ( "! %d\n" , ret ) ;
                fflush ( stdout ) ;
                return ;
            }
            else {
                sz[ x ] = sz[ y ] = 0 ;
                int aux = v[ x ].size ( ) ;
                for ( int i = 0 ; i < aux ; ++ i ) {
                    -- sz[ v[ x ][ i ] ] ;
                }
                aux = v[ y ].size ( ) ;
                for ( int i = 0 ; i < aux ; ++ i ) {
                    -- sz[ v[ y ][ i ] ] ;
                }
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