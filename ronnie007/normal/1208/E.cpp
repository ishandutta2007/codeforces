#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 1000007
#define emp -1000000007

int n , w ;
int len[ MAXN ] ;
vector < int > v[ MAXN ] ;

long long ans[ MAXN ] ;
long long sm = 0 ;


struct tuhla {
    int x , y ;
    int type ;
    tuhla ( ) { x = y = type = 0 ; }
    tuhla ( int _x , int _y , int _type ) {
        x = _x , y = _y , type = _type ;
    }
};

int vec_sz[ MAXN ] ;
vector < tuhla > add[ MAXN ] ;
vector < bool > del[ MAXN ] ;

priority_queue < pair < int , int > > pq[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &w ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &len[ i ] ) ;
        v[ i ].resize ( len[ i ] ) ;
        del[ i ].resize ( len[ i ] + 4 ) ;
        for ( int j = 0 ; j < len[ i ] ; ++ j ) {
            scanf ( "%d" , &v[ i ][ j ] ) ;
        }
        v[ i ].push_back ( 0 ) ;
        v[ i ].push_back ( 0 ) ;
        for ( int j = 0 ; j < len[ i ] + 4 ; ++ j ) {
            del[ i ][ j ] = false ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( len[ i ] < w ) {
            int st = 1 ;
            int en = w - len[ i ] ;
            add[ st ].push_back ( tuhla ( i , len[ i ] , 1 ) ) ;
            ++ vec_sz[ st ] ;
            add[ en + 1 ].push_back ( tuhla ( i , len[ i ] , -1 ) ) ;
            ++ vec_sz[ en + 1 ] ;

            st = len[ i ] + 1 ;
            en = w + 1 ;
            add[ st ].push_back ( tuhla ( i , len[ i ] + 1 , 1 ) ) ;
            ++ vec_sz[ st ] ;
            add[ en + 1 ].push_back ( tuhla ( i , len[ i ] + 1 , -1 ) ) ;
            ++ vec_sz[ en + 1 ] ;
        }
        for ( int j = 0 ; j < len[ i ] ; ++ j ) {
            int st = j + 1 ;
            int en = w - ( len[ i ] - j - 1 ) ;
            add[ st ].push_back ( tuhla ( i , j , 1 ) ) ;
            ++ vec_sz[ st ] ;
            add[ en + 1 ].push_back ( tuhla ( i , j , -1 ) ) ;
            ++ vec_sz[ en + 1 ] ;
        }
    }
    sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pq[ i ].push ( { emp , 0 } ) ;
    }
    for ( int i = 1 ; i <= w ; ++ i ) {
        for ( int j = 0 ; j < vec_sz[ i ] ; ++ j ) {
            int id = add[ i ][ j ].x ;
            int pos = add[ i ][ j ].y ;
            int val = v[ id ][ pos ] ;
            ++ pos ;
            if ( add[ i ][ j ].type == 1 ) {
                int curmx = pq[ id ].top().first ;
                pq[ id ].push ( { val , pos } ) ;
                int nwmx = pq[ id ].top().first ;
                if ( curmx == emp && nwmx != emp ) { sm += nwmx ; }
                else if ( curmx != emp && nwmx != emp ) { sm += nwmx - curmx ; }
                else if ( curmx != emp && nwmx == emp ) { sm -= curmx ; }
            }
            else {
                int curmx = pq[ id ].top().first ;
                del[ id ][ pos ] = true ;
                while ( del[ id ][ pq[ id ].top().second ] == true ) {
                    pq[ id ].pop ( ) ;
                }
                int nwmx = pq[ id ].top().first ;
                if ( curmx == emp && nwmx != emp ) { sm += nwmx ; }
                else if ( curmx != emp && nwmx != emp ) { sm += nwmx - curmx ; }
                else if ( curmx != emp && nwmx == emp ) { sm -= curmx ; }
            }
        }
        ans[ i ] = sm ;
    }
    for ( int i = 1 ; i <= w ; ++ i ) {
        printf ( "%I64d " , ans[ i ] ) ;
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