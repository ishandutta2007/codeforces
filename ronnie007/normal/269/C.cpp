#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 200007

int n , m ;
int sm[ MAXN ] ;
int cur[ MAXN ] ;
int ans[ MAXN ] ;
bool fl[ MAXN ] ;

struct tuhla {
    int to ;
    int len ;
    int rot ;
    int id ;
    tuhla ( ) { to = len = rot = id = 0 ; }
    tuhla ( int _to , int _len , int _rot , int _id ) {
        to = _to ;
        len = _len ;
        rot = _rot ;
        id = _id ;
    }
};

vector < tuhla > v[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( tuhla ( y , z , 0 , i ) ) ;
        v[ y ].push_back ( tuhla ( x , z , 1 , i ) ) ;
        sm[ x ] += z ;
        sm[ y ] += z ;
    }
}

void solve ( ) {
    queue < int > q ;
    q.push ( 1 ) ;
    int i ;
    while ( q.empty ( ) == false ) {
        int vertex = q.front ( ) ;
        q.pop ( ) ;
        fl[ vertex ] = true ;
        int sz = v[ vertex ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
            if ( fl[ v[ vertex ][ i ].to ] == true ) { continue ; }
            ans[ v[ vertex ][ i ].id ] = v[ vertex ][ i ].rot ;
            cur[ v[ vertex ][ i ].to ] += v[ vertex ][ i ].len ;
            if ( v[ vertex ][ i ].to != n && 2 * cur[ v[ vertex ][ i ].to ] == sm[ v[ vertex ][ i ].to ] ) {
                q.push ( v[ vertex ][ i ].to ) ;
            }
        }
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        printf ( "%d\n" , ans[ i ] ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}