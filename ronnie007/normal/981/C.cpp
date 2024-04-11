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

#define MAXN 100007

int n ;
int deg[ MAXN ] ;

vector < int > v ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 , x , y ; i < n ; ++ i ) {
        scanf ( "%d%d" , &x , &y ) ;
        ++ deg[ x ] , ++ deg[ y ] ;
    }
}

void solve ( ) {
    int mx = 0 ;
    int id = 0 ;
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mx < deg[ i ] ) {
            mx = deg[ i ] ;
            id = i ;
        }
        if ( deg[ i ] > 2 ) { ++ cnt ; }
        if ( deg[ i ] == 1 ) { v.push_back ( i ) ; }
    }
    if ( mx < 3 ) {
        printf ( "Yes\n" ) ;
        printf ( "1\n" ) ;
        printf ( "%d %d\n" , v[ 0 ] , v[ 1 ] ) ;
    }
    else {
        if ( cnt > 1 ) { printf ( "No\n" ) ; }
        else {
            printf ( "Yes\n" ) ;
            int sz = v.size ( ) ;
            printf ( "%d\n" , sz ) ;
            for ( int i = 0 ; i < sz ; ++ i ) {
                printf ( "%d %d\n" , id , v[ i ] ) ;
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