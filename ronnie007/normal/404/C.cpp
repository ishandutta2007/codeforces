#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std ;

int n ;
int k ; 
struct tuhla {
    int dist ;
    int ind ;
}; 
struct tuhla d[ 100007 ] ;

int degree[ 100007 ] ;
int g[ 100007 ] ;

int m ;

vector < pair < int , int > > v ;

bool f ( struct tuhla p1 , struct tuhla p2 ) {
    return ( p1.dist < p2.dist ) ;
}

void input ( ) ;
void solve ( ) ;



int main ( )  {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &d[ i ].dist ) ;
        d[ i ].ind = i ;
        g[ i ] = d[ i ].dist ;
    }
}

void solve ( ) {
    sort ( d + 1 , d + n + 1 , f ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        degree[ i ] = 0 ;
        //printf ( "%d\n" , d[ i ].dist ) ;
    }
    
    if ( d[ 1 ].dist != 0 ) {
        printf ( "-1\n" ) ;
        return  ;
    }
    if ( d[ 2 ].dist == 0 ) {
        printf ( "-1\n" ) ;
        return ;
    }
    queue < int > q ;
    while ( q.empty ( ) == false ) q.pop ( ) ;
    q.push ( d[ 1 ].ind ) ;
    for ( i = 2 ; i <= n ; i ++ ) {
        if ( q.empty ( ) == true ) {
            printf ( "-1\n" ) ;
            return ;
        }
        //printf ( "here1\n" ) ;
        while ( q.empty ( ) == false && degree[ q.front ( ) ] == k ) q.pop ( ) ;         
        while ( q.empty ( ) == false && g[ q.front ( ) ] != d[ i ].dist - 1 ) q.pop ( ) ;
        if ( q.empty ( ) == true ) {
            printf ( "-1\n" ) ;
            return ;
        }
        if ( g[ q.front ( ) ] != d[ i ].dist - 1 ) {
            printf ( "-1\n" ) ;
            return ;
        }
        //printf ( "here\n" ) ;
       
        if ( q.empty ( ) == true ) {
            printf ( "-1\n" ) ;
            return ;
        }
        degree[ q.front ( ) ] ++ ;
        degree[ d[ i ].ind ] ++ ;
        v.push_back ( make_pair ( q.front ( ) , d[ i ].ind ) ) ;
        q.push ( d[ i ].ind ) ;
    }
    int m = v.size ( ) ;
    printf ( "%d\n" , m ) ;
    for ( i = 0 ; i < m ; i ++  ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}