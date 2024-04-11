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

#define MAXN 10007

int n , q ;
int lst[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 , x , y , z ; i <= q ; ++ i ) {
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( { z , y } ) ;
    }
}

void solve ( ) {
    lst[ 0 ] = n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = v[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            for ( int aux = n - v[ i ][ j ].first ; aux >= 0 ; -- aux ) {
                if ( lst[ aux ] >= i ) {
                    lst[ aux + v[ i ][ j ].first ] = max ( min ( v[ i ][ j ].second , lst[ aux ] ) , lst[ aux + v[ i ][ j ].first ] ) ;
                }
            }
        }
    }
    vector < int > ans ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( lst[ i ] > 0 ) { ans.push_back ( i ) ; }
    }
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