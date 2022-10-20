#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;
int br[ MAXN ] ;
int sm[ MAXN ] ;

vector < pair < int , int > > v ;

bool used[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d%d" , &br[ i ] , &sm[ i ] ) ;
    }
}

void solve ( ) {
    queue < int > q ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( br[ i ] == 1 ) {
            q.push ( i ) ;
        }
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        used[ x ] = true ;
        if ( br[ x ] != 0 ) {
            v.push_back ( make_pair ( x , sm[ x ] ) ) ;
            sm[ sm[ x ] ] ^= x ;
            br[ sm[ x ] ] -- ;
            if ( br[ sm[ x ] ] == 1 ) {
                q.push ( sm[ x ] ) ;
            }
        }
    }
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}