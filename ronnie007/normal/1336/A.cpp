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

#define MAXN 200007

int n , k ;
vector < int > v[ MAXN ] ;
long long ans = 0 ;
int depth[ MAXN ] ;
int comp[ MAXN ] ;
int lst[ MAXN ] ;

pair < int , int > srt[ MAXN ] ;


void dfs ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    comp[ vertex ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == lst[ vertex ] ) { continue ; }
        lst[ v[ vertex ][ i ] ] = vertex ;
        depth[ v[ vertex ][ i ] ] = depth[ vertex ] + 1 ;
        dfs ( v[ vertex ][ i ] ) ;
        comp[ vertex ] += comp[ v[ vertex ][ i ] ] ;
    }
}



void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        srt[ i ] = { - ( comp[ i ] - depth[ i ] - 1 ) , i } ;
    }
    sort ( srt + 1 , srt + n + 1 ) ;
    for ( int i = 1 ; i <= n - k ; ++ i ) {
        int id = srt[ i ].second ;
        ans -= srt[ i ].first ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}