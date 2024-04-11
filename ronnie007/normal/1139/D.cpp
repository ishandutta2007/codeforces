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

#define MAXN 100007
#define MOD 1000000007
typedef pair < long long , long long > TYPE ;


vector < int > divs[ MAXN ] ;

int m ;
TYPE dp[ MAXN ] ;
long long ff[ 256 ] ;


TYPE add ( TYPE p1 , TYPE p2 ) {
    TYPE ret ;
    ret.second = ( p1.second * p2.second ) % MOD ;
    ret.first = ( p1.first * p2.second + p1.second * p2.first ) % MOD ;
    return ret ;
}

void init ( ) {
    int i , j ;
    for ( i = 1 ; i <= m ; i ++ ) {
        for ( j = i ; j <= m ; j += i ) {
            divs[ j ].push_back ( i ) ;
        }
    }
}

long long fastpow ( long long x , long long st ) {
    long long ret = 1 ;
    while ( st > 0 ) {
        if ( ( st % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            st /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            st -- ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &m ) ;
}

void solve ( ) {
    init ( ) ;
    int i , j , t ;
    dp[ 1 ] = make_pair ( 0 , 1 ) ;
    for ( i = 2 ; i <= m ; i ++ ) {
        int sz = divs[ i ].size ( ) ;
        dp[ i ] = make_pair ( 0 , 1 ) ;
        for ( j = sz - 1 ; j >= 0 ; j -- ) {
            long long cnt = ( m / divs[ i ][ j ] ) ;
            for ( t = ( j + 1 ) ; t < sz ; t ++ ) {
                if ( ( divs[ i ][ t ] % divs[ i ][ j ] ) != 0 ) { continue ; }
                cnt -= ff[ t ] ;
            }
            ff[ j ] = cnt ;
            if ( j != sz - 1 ) {
                TYPE aux = dp[ divs[ i ][ j ] ] ;
                aux.first = ( aux.first + aux.second ) % MOD ;
                aux.first = ( aux.first * cnt ) % MOD ;
                aux.second = ( aux.second * m ) % MOD ;
                dp[ i ] = add ( dp[ i ] , aux ) ;
            }
            else {
                TYPE aux = make_pair ( cnt , m ) ;
                dp[ i ] = add ( dp[ i ] , aux ) ;
            }
        }
        dp[ i ].first = ( dp[ i ].first * m ) % MOD ;
        dp[ i ].second = ( dp[ i ].second * ( m - ff[ sz - 1 ] ) ) % MOD ;
    }
    TYPE ret = make_pair ( 0 , 1 ) ;
    for ( i = 1 ; i <= m ; i ++ ) {
        dp[ i ].first = ( dp[ i ].first + dp[ i ].second ) % MOD ;
        dp[ i ].second = ( dp[ i ].second * m ) % MOD ;
        ret = add ( ret , dp[ i ] ) ;
    }
    printf ( "%I64d\n" , ( ret.first * fastpow ( ret.second , MOD - 2 ) ) % MOD ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}