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

#define MAXN 500007
#define MAXBIT 31
#define MOD 998244353

int n , m , k ;

vector < int > open[ MAXN ] ;
vector < pair < int , int > > close[ MAXN ] ;

long long dp[ MAXN ] ;

long long f ( int id ) {
    long long ret = 1 ;
    int cnt = 0 ;
    int st = 0 ;
    dp[ 0 ] = 1 ;
    for ( int i = 1 , sz ; i <= n ; ++ i ) {
        sz = open[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( ( open[ i ][ j ] & (1<<id) ) > 0 ) {
                ++ cnt ;
            }
        }
        if ( cnt > 0 ) { dp[ i ] = 0 ; }
        else {
            dp[ i ] = ret ;
            ret = ( ret * 2 ) % MOD ;
        }
        sz = close[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( ( close[ i ][ j ].first & ( 1<<id ) ) > 0 ) {
                -- cnt ;
            }
            else {
                while ( st < close[ i ][ j ].second ) {
                    ret = ( ret - dp[ st ++ ] + MOD ) % MOD ;
                }
            }
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &k , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , val ;
        scanf ( "%d%d%d" , &x , &y , &val ) ;
        open[ x ].push_back ( val ) ;
        close[ y ].push_back ( { val , x } ) ;
    }
}

void solve ( ) {
    long long ret = 1 ;
    for ( int i = 0 ; i < k ; ++ i ) {
        ret = ( ret * f ( i ) ) % MOD ;
    }
    printf ( "%I64d\n" , ret ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}