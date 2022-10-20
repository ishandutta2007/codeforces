#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

long long n , k ;

vector < long long > v ;
map < long long , vector < long long > > ZX ;
map < long long , bool > vis ;

void f ( long long num , long long lvl ) {
    if ( lvl == 0 ) { v.push_back ( num ) ; return ; }
    if ( num == 1 ) { v.push_back ( 1 ) ; return ; }
    long long i ;
    vector < long long > aux ;
    if ( v.size ( ) > 100000 ) { return ; }
    if ( vis.find ( num ) == vis.end ( ) ) {
        vis[ num ] = true ;
        for ( i = 1 ; i * i <= num ; i ++ ) {
            if ( ( num % i ) == 0 ) {
                ZX[ num ].push_back ( i ) ;
                if ( ( num / i ) != i ) {
                    ZX[ num ].push_back ( ( num / i ) ) ;
                }
            }
        }
        sort ( ZX[ num ].begin ( ) , ZX[ num ].end ( ) ) ;
    }
    int sz = ZX[ num ].size ( ) ;
    if ( sz == 2 ) {
        for ( i = 0 ; i < lvl ; i ++ ) {
            v.push_back ( 1 ) ;
            if ( v.size ( ) > 100000 ) { return ; }
        }
        v.push_back ( num ) ;
        return ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        f ( ZX[ num ][ i ] , lvl - 1 ) ;
        if ( v.size ( ) > 100000 ) { return ; }
    }
}

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    f ( n , k ) ;
    int sz = v.size ( ) ;
    if ( sz > 100000 ) { sz = 100000 ; }
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%I64d" , v[ i ] ) ;
        if ( i == ( sz - 1 ) ) { printf ( "\n" ) ; }
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