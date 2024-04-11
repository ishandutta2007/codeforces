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

#define MAXN 1000007

int n ;
int a[ MAXN ] ;
int used[ MAXN ] ;

bool h[ MAXN ] ;
vector < int > divs[ MAXN ] ;

int ans = MAXN ;

vector < int > v[ MAXN ] ;

vector < int > vis ;

void bfs ( int st ) {
    vis.clear ( ) ;
    queue < pair < int , int > > q ;
    q.push ( { st , -1 } ) ;
    while ( q.empty ( ) == false ) {
        pair < int , int > aux ;
        aux = q.front ( ) ;
        q.pop ( ) ;
        vis.push_back ( aux.first ) ;
        int sz = v[ aux.first ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( aux.second == v[ aux.first ][ i ] ) { continue ; }
            if ( used[ v[ aux.first ][ i ] ] > 0 ) {
                ans = min ( ans , used[ v[ aux.first ][ i ] ] + used[ aux.first ] + 1 ) ;
            }
            else {
                used[ v[ aux.first ][ i ] ] = used[ aux.first ] + 1 ;
                q.push ( { v[ aux.first ][ i ] , aux.first } ) ;
            }
        }
    }
    int sz = vis.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        used[ vis[ i ] ] = 0 ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        if ( h[ i ] == true ) { continue ; }
        for ( int j = i ; j < MAXN ; j += i ) {
            divs[ j ].push_back ( i ) ;
            h[ j ] = true ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = a[ i ] ;
        int sz = divs[ a[ i ] ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            long long h = 1LL * divs[ a[ i ] ][ j ] * divs[ a[ i ] ][ j ] ;
            while ( ( aux % h ) == 0 ) {
                aux /= h ;
            }
        }
        if ( aux == 1 ) { printf ( "1\n" ) ; return ; }
        if ( sz == 1 ) {
            v[ aux ].push_back ( 1 ) ;
            v[ 1 ].push_back ( aux ) ;
        }
        else {
            if ( aux == divs[ a[ i ] ][ 0 ] || aux == divs[ a[ i ] ][ 1 ] ) {
                v[ aux ].push_back ( 1 ) ;
                v[ 1 ].push_back ( aux ) ;
            }
            else {
                v[ divs[ a[ i ] ][ 0 ] ].push_back ( divs[ a[ i ] ][ 1 ] ) ;
                v[ divs[ a[ i ] ][ 1 ] ].push_back ( divs[ a[ i ] ][ 0 ] ) ;
            }
        }
    }
    for ( int i = 1 ; i <= 1000 ; ++ i ) {
        if ( i == 1 || h[ i ] == true ) { bfs ( i ) ; }
    }
    if ( ans == MAXN ) { ans = -1 ; }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}