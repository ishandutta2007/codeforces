#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 200007
#define LOG 63


int n ;
pair < long long , long long > a[ MAXN ] ;
pair < long long , long long > b[ MAXN ] ;

int ans = 0 ;
vector < long long > v ;
vector < long long > dead ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ].first ) ;
        a[ i ].second = a[ i ].first ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= 63 ; ++ i ) {
        int cur = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( a[ j ].first % 2 ) == 0 ) { ++ cur ; }
        }
        if ( ans < n - cur ) {
            ans = n - cur ;
            v = dead ;
            for ( int j = 1 ; j <= n ; ++ j ) {
                if ( ( a[ j ].first % 2 ) == 0 ) {
                    v.push_back ( a[ j ].second ) ;
                }
            }
        }

        int sz = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( a[ j ].first % 2 ) == 0 ) {
                b[ ++ sz ] = a[ j ] ;
                b[ sz ].first /= 2 ;
            }
            else { dead.push_back ( a[ j ].second ) ; }
        }
        n = sz ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            a[ j ] = b[ j ] ;
        }
    }
    ans = v.size ( ) ;
    printf ( "%d\n" , ans ) ;
    for ( int i = 0 ; i < ans ; ++ i ) {
        printf ( "%I64d " , v[ i ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}