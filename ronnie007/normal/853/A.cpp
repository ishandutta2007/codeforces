#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 300007

int n , k ;
int a[ MAXN ] ;
int pos[ MAXN ] ;

struct tuhla {
    int val ;
    int id ;
    tuhla ( ) { val = id = 0 ; }
    tuhla ( int _val , int _id ) {
        val = _val ;
        id = _id ;
    }
};

bool operator < ( tuhla p1 , tuhla p2 ) {
    if ( p1.val != p2.val ) { return  ( p1.val < p2.val ) ; }
    return ( p1.id < p2.id ) ;
}

priority_queue < tuhla > q ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    long long ans = 0 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        q.push ( tuhla ( a[ i ] , i ) ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        int h = ( k + i ) ;
        if ( h <= n ) {
            q.push ( tuhla ( a[ h ] , h ) ) ;
        }
        tuhla ret = q.top ( ) ;
        q.pop ( ) ;
        pos[ ret.id ] = h ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        long long cur = a[ i ] ;
        cur *= ( pos[ i ] - i ) ;
        ans += cur ;
    }
    printf ( "%I64d\n" , ans ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d" , pos[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}