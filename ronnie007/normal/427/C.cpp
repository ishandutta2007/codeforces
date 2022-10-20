#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;

#define MOD 1000000007

long long inf = 0 ;

int n , m ;
int a[ 100007 ] ;
int cost[ 100007 ] ;
vector < int > v[ 100007 ] ;
vector < int > rev[ 100007 ] ;
int comp[ 100007 ] ;
int used[ 100007 ] ;
long long mncost , brw ;
int CompInd ;

stack < int > s ;

int ind ;
long long ans = 0 ;
long long ways = 0 ;


void input ( ) ;
void solve ( ) ;


void dfs1 ( int vertex ) {
    used[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ vertex ][ i ] ] == 0 ) {
            dfs1 ( v[ vertex ][ i ]  ) ;
        }
    }
    s.push ( vertex ) ;
}

void dfs2 ( int vertex ) {
    used[ vertex ] = 1 ;
    comp[ vertex ] = CompInd ;
    if ( cost[ vertex ] == mncost ) brw ++ ;
    if ( cost[ vertex ] < mncost ) {
        mncost = cost[ vertex ] ;
        brw = 1 ;
    }
    int i ;
    int sz = rev[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ rev[ vertex ][ i ] ] == 0 ) dfs2 ( rev[ vertex ][ i ] ) ;
    }
}

int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &cost[ i ] ) ;
    }
    scanf ( "%d" , &m ) ;
    int x , y ;
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        rev[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    inf = 1 ;
    int i ;
    for ( i = 0 ; i < 16 ; i ++ ) inf = inf * 10 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == 0 ) {
            dfs1 ( i ) ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) used[ i ] = 0 ;
    int x ;
    ways = 1 ;
    CompInd = 1 ;
    while ( s.empty ( ) == false ) {
        x = s.top ( ) ;
        s.pop ( ) ;
        ///printf ( "%d\n" , x ) ;
        mncost = inf ;
        brw = 1 ;
        if ( used[ x ] == 1 ) continue ;
        dfs2 ( x ) ;
        ///printf ( "%I64d\n" , mncost ) ;
        ans = ans + mncost ;
        ways = ( ways * brw ) % MOD ;
        CompInd ++ ;
    }
    printf ( "%I64d %I64d\n" , ans , ways % MOD ) ;
}