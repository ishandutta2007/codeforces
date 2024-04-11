#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int n , m ;
int a[ 100007 ] ;

vector < int > v[ 100007 ] ;


void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    int i ;
    scanf ( "%d%d" , &m , &n ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {

    int i ;
    int j ;
    for ( i = 1 ; i < n ; i ++ ) {
        if ( a[ i ] != a[ i - 1 ] ) {
            v[ a[ i ] ].push_back ( a[ i - 1 ] ) ;
        }
    }
    for ( i = 0 ; i < n - 1 ; i ++ ) {
        if ( a[ i ] != a[ i + 1 ] ) {
            v[ a[ i ] ].push_back ( a[ i + 1 ] ) ;
        }
    }
    long long st = 0 ;
    for ( i = 1 ; i < n ; i ++ ) st += abs ( a[ i ] - a[ i - 1 ] ) ;

    int sz ;
    int x ;
    long long cur = -1 ; ;
    long long ans = -1 ;
    for ( i = 1 ; i <= m ; i ++ ) {
        if ( v[ i ].size ( ) == 0 ) continue ;
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
        sz = v[ i ].size ( ) ;
        x = v[ i ][ sz / 2 ] ;
        cur = st ;  ;
        ///printf ( "%d\n" , x ) ;
        for ( j = 0 ; j < v[ i ].size ( ) ; j ++ ) {
            cur += abs ( x - v[ i ][ j ] ) - abs ( i - v[ i ][ j ] ) ;;
        }
        if ( ans == -1 || ans > cur ) ans = cur ;
    }
    if ( ans == -1 ) ans = st ;
    printf ( "%I64d\n" , ans ) ;
}