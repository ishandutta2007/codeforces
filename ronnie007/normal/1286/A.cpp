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

#define MAXN 107

int n ;
int a[ MAXN ] ;
int used[ MAXN ] ;

int cnt1 , cnt2 ;

int dp[ MAXN ][ MAXN ][ MAXN ][ 2 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        used[ a[ i ] ] = 1 ;
    }
    cnt1 = cnt2 = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            if ( ( i % 2 ) == 0 ) { ++ cnt1 ; }
            else { ++ cnt2 ; }
        }
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= cnt1 ; ++ j ) {
            for ( int t = 0 ; t <= cnt2 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    dp[ i ][ j ][ t ][ z ] = MAXN ;
                }
            }
        }
    }
    dp[ 0 ][ 0 ][ 0 ][ 0 ] = dp[ 0 ][ 0 ][ 0 ][ 1 ] = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j <= cnt1 ; ++ j ) {
            for ( int t = 0 ; t <= cnt2 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    if ( a[ i + 1 ] == 0 ) {
                        if ( j < cnt1 ) {
                            int aux = 0 ;
                            if ( z == 1 ) { ++ aux ; }
                            dp[ i + 1 ][ j + 1 ][ t ][ 0 ] = min ( dp[ i + 1 ][ j + 1 ][ t ][ 0 ] , dp[ i ][ j ][ t ][ z ] + aux ) ;
                        }
                        if ( t < cnt2 ) {
                            int aux = 0 ;
                            if ( z == 0 ) { ++ aux ; }
                            dp[ i + 1 ][ j ][ t + 1 ][ 1 ] = min ( dp[ i + 1 ][ j ][ t + 1 ][ 1 ] , dp[ i ][ j ][ t ][ z ] + aux ) ;                            
                        }
                    }
                    else {
                        int aux = 0 ;
                        int sr = ( a[ i + 1 ] % 2 ) ;
                        if ( z != sr ) { ++ aux ; }
                        dp[ i + 1 ][ j ][ t ][ sr ] = min ( dp[ i + 1 ][ j ][ t ][ sr ] , dp[ i ][ j ][ t ][ z ] + aux ) ;
                    }
                }
            }
        }
    }
    printf ( "%d\n" , min ( dp[ n ][ cnt1 ][ cnt2 ][ 0 ] , dp[ n ][ cnt1 ][ cnt2 ][ 1 ] ) ) ;
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}