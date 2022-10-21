#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std ;

#define MAXN 300007

int n , q ;
int a[ MAXN ] ;

struct tuhla {
    int br ;
    int to[ 2 ] ;
};
vector < tuhla > v ;
int flip[ 27 ] ;

void dfs ( int pos , int i ) {
    if ( i < 0 ) { return ; }
    v[ pos ].br = 0 ;
    tuhla emp ;
    emp.br = emp.to[ 0 ] = emp.to[ 1 ] = 0 ;
    v.push_back ( emp ) ;
    v[ pos ].to[ 0 ] = v.size ( ) - 1 ;
    dfs ( v[ pos ].to[ 0 ] , i - 1 ) ;
    v.push_back ( emp ) ;
    v[ pos ].to[ 1 ] = v.size ( ) - 1 ;
    dfs ( v[ pos ].to[ 1 ] , i - 1 ) ;
}

void add ( int val ) {
    int pos = 1 ;
    int i ;
    for ( i = 20 ; i >= 0 ; i -- ) {
        v[ pos ].br ++ ;
        if ( (val&(1<<i)) == 0 ) {
            pos = v[ pos ].to[ 0 ] ;
        }
        else {
            pos = v[ pos ].to[ 1 ] ;
        }
    }
    v[ pos ].br ++ ;
}

int mex ( ) {
    int i ;
    int pos = 1 ;
    int ret = 0 ;
    for ( i = 20 ; i >= 0 ; i -- ) {
        int id = 0 ;
        id ^= flip[ i ] ;
        int u = v[ pos ].to[ id ] ;
        if ( v[ u ].br != (1<<i) ) {
            pos = u ;
        }
        else {
            ret += (1<<i) ;
            pos = v[ pos ].to[ ( 1 - id ) ] ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int i ;
    v.resize ( 2 ) ;
    dfs ( 1 , 20 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( i != 1 && a[ i ] == a[ i - 1 ] ) { continue ; }
        add ( a[ i ] ) ;
    }
    int x ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%d" , &x ) ;
        for ( i = 20 ; i >= 0 ; i -- ) {
            if ( (x&(1<<i)) != 0 ) {
                flip[ i ] ^= 1 ;
            }
        }
        printf ( "%d\n" , mex ( ) ) ;
    }
}

int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}