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
int n , m ;
bool f[ 3 * MAXN ] ;

vector < int > v ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    v.clear ( ) ;
    for ( int i = 1 ; i <= 3 * n ; ++ i ) {
        f[ i ] = false ;
    }
    v.clear ( ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( f[ x ] == false && f[ y ] == false ) {
            f[ x ] = f[ y ] = true ;
            v.push_back ( i ) ;
        }
    }
}

void solve ( ) {
    if ( v.size ( ) >= n ) {
        printf ( "Matching\n" ) ;
        for ( int i = 0 ; i < n ; ++ i ) {
            printf ( "%d " , v[ i ] ) ;
        }
        printf ( "\n" ) ;
    }
    else {
        printf ( "IndSet\n" ) ;
        int lft = n ;
        for ( int i = 1 ; i <= 3 * n && lft > 0 ; ++ i ) {
            if ( f[ i ] == false ) {
                -- lft ;
                printf ( "%d " , i ) ;
            }
        }
        printf ( "\n" ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ; scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}