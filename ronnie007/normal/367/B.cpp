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

#define MAXN 200007

int n , m , p ;
int a[ MAXN ] ;
int b[ MAXN ] ;


map < int , int > w ;
map < int , int > sr ;
vector < int > ans ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &p ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
        ++ sr[ b[ i ] ] ;
    }
}

void solve ( ) {
    if ( 1LL * ( m - 1 ) * p > n ) { printf ( "0\n" ) ; return ; }
    for ( int i = 1 ; i <= p ; ++ i ) {
        if ( i + ( m - 1 ) * p > n ) { break ; }
        w.clear ( ) ;
        int sm = 0 ;
        for ( int j = 0 ; j < m ; ++ j ) {
            int aux = w[ a[ i + j * p ] ] ;
            if ( aux + 1 == sr[ a[ i + j * p ] ] ) {
                sm += aux + 1 ;
            }
            if ( aux == sr[ a[ i + j * p ] ] ) {
                sm -= aux ;
            }
            ++ w[ a[ i + j * p ] ] ;
        }
        if ( sm == m ) { ans.push_back ( i ) ; }
        for ( int j = i + m * p ; j <= n ; j += p ) {
            int aux = w[ a[ j - m * p ] ] ;
            if ( aux == sr[ a[ j - m * p ] ] + 1 ) {
                sm += aux - 1 ;
            }
            if ( aux == sr[ a[ j - m * p ] ] ) {
                sm -= aux ;
            }
            -- w[ a[ j - m * p ] ] ;

            aux = w[ a[ j ] ] ;
            if ( aux == sr[ a[ j ] ] - 1 ) {
                sm += aux + 1 ;
            }
            if ( aux == sr[ a[ j ] ] ) {
                sm -= aux ;
            }
            ++ w[ a[ j ] ] ;
            if ( sm == m ) { ans.push_back ( j - ( m - 1 ) * p ) ; }
        }
    }
    sort ( ans.begin ( ) , ans.end ( ) ) ;
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}