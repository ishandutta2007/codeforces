#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

struct tuhla {
    int x , y ;
    int id ;
    bool operator < ( tuhla other ) const {
        if ( x != other.x ) {
            return ( x > other.x ) ;
        }
        return ( y > other.y ) ;
    }
};

int n ;
tuhla a[ MAXN ] ;

long long sm1 , sm2 ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    sm1 = 0 ;
    sm2 = 0 ;
    for ( int i = 1 ; i < 2 * n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
        a[ i ].id = i ;
        sm1 += a[ i ].x ;
        sm2 += a[ i ].y ; 
    }
    sort ( a + 1 , a + 2 * n ) ;
}

void solve ( ) {
    long long cnt = 0 ;
    for ( int i = 1 ; i < 2 * n ; i += 2 ) {
        cnt += a[ i ].y ;
    }
    if ( 2 * cnt >= sm2 ) {
        printf ( "YES\n" ) ;
        for ( int i = 1 ; i < 2 * n ; i += 2 ) {
            printf ( "%d " , a[ i ].id ) ;
        }
        printf ( "\n" ) ;
    }
    else {
        printf ( "YES\n" ) ;
        printf ( "%d" , a[ 1 ].id ) ;
        for ( int i = 2 ; i < 2 * n ; i += 2 ) {
            printf ( " %d" , a[ i ].id ) ;
        }
        printf ( "\n" ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}