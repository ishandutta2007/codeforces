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
#include<random>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;

vector < pair < int , int > > ans ;

void dfs ( int vertex , int prv , int st ) {
    int sz = v[ vertex ].size ( ) ;
    int lft = sz ;
    if ( prv > 0 ) { -- lft ; }
    int h = st ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( st > lft ) {
            ans.push_back ( { vertex , st - lft - 1 } ) ;
            h = st - lft - 1 ;
            lft = 5 * MAXN ;
        }
        ans.push_back ( { v[ vertex ][ i ] , h + 1 } ) ;
        dfs ( v[ vertex ][ i ] , vertex , h + 1 ) ;
        ans.push_back ( { vertex , h + 1 } ) ;
        ++ h ;
        -- lft ;
    }
    if ( vertex != 1 && lft == 0 ) {
        ans.push_back ( { vertex , st - 1 } ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    ans.push_back ( { 1 , 0 } ) ;
    dfs ( 1 , -1 , 0 ) ;
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d\n" , ans[ i ].first , ans[ i ].second ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}