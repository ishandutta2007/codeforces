#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;

#define inf 1000000000

int n ;

int a[ 100007 ] ;

long long pr[ 100007 ] ;

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
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    long long cur = 0 ;
    long long best ;
    long long ans = a[ 2 ] * a[ 2 ] + 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        pr[ i ] = pr[ i - 1 ] + a[ i ] ;
    }
    long long w = 10000000 / n ;
    for ( j = 1 ; j <= w ; j ++ ) {
        for ( i = 1 ; i + j <= n ; i ++ ) {
            cur = pr[ i + j ] - pr[ i ] ;
            cur = cur * cur ;
            cur += j * j ;
            if ( ans > cur ) ans = cur ;
        }
    }
    cout << ans << "\n" ;
}