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

int n ;
int a[ MAXN ] ;

pair < int , int > b[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        b[ i ] = { a[ i ] - i , a[ i ] } ;
    }
    sort ( b + 1 , b + n + 1 ) ;
}

void solve ( ) {
    long long ans = 0 ;
    long long aux = b[ 1 ].second ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( b[ i ].first == b[ i - 1 ].first ) {
            aux += b[ i ].second ;
        }
        else {
            ans = max ( ans , aux ) ;
            aux = b[ i ].second ;
        }
    }
    ans = max ( ans , aux ) ;
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}