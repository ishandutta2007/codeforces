#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std ;

#define MAXN 300007

int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int c[ MAXN ] ;
map < int , int > cnt ;


struct tuhla {
    int x , y ;
    int id ;
};
bool cmp ( tuhla p1 , tuhla p2 ) {
    if ( p1.x != p2.x ) { return ( p1.x > p2.x ) ; }
    return ( p1.y > p2.y ) ;
}

tuhla f[ MAXN ] ;
void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        cnt[ a[ i ] ] ++ ;
    }
    scanf ( "%d" , &m ) ;
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        f[ i ].x = cnt[ b[ i ] ] ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d" , &c[ i ] ) ;
        f[ i ].y = cnt[ c[ i ] ] ;
        f[ i ].id = i ;
    }
}

void solve ( ) {
    sort ( f + 1 , f + m + 1 , cmp ) ;
    printf ( "%d\n" , f[ 1 ].id ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}