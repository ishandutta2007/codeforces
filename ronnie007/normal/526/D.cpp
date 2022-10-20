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

#define MAXN 1000007
#define BASE 26
#define NUM 1

long long MOD[ NUM ] ;

struct tuhla {
    long long h[ NUM ] ;
    void advance ( int ch ) {
        for ( int j = 0 ; j < NUM ; ++ j ) {
            h[ j ] = ( BASE * h[ j ] + ch ) % MOD[ j ] ;
        }
    }
    bool operator == ( tuhla other ) const {
        for ( int j = 0 ; j < NUM ; ++ j ) {
            if ( h[ j ] != other.h[ j ] ) { return false ; }
        }
        return true ;
    }
};
tuhla pw[ MAXN ] ;
tuhla pref[ MAXN ] ;

int add[ MAXN ] ;

int n , k ;
string a ;
int mxset ;

tuhla obtain ( int st , int en ) {
    int len = ( en - st + 1 ) ;
    tuhla ret = pref[ en ] ;
    for ( int j = 0 ; j < NUM ; ++ j ) {
        long long sub = ( pref[ st - 1 ].h[ j ] * pw[ len ].h[ j ] ) % MOD[ j ] ;
        ret.h[ j ] = ( ret.h[ j ] - sub + MOD[ j ] ) % MOD[ j ] ;
    }
    return ret ;
}

bool same ( int st1 , int en1 , int st2 , int en2 ) {
    tuhla h1 = obtain ( st1 , en1 ) ;
    tuhla h2 = obtain ( st2 , en2 ) ;
    return ( h1 == h2 ) ;
}

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    if ( k == 1 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            printf ( "1" ) ;
        }
        printf ( "\n" ) ;
        return ;
    }
    for ( int j = 0 ; j < NUM ; ++ j ) {
        pref[ 0 ].h[ j ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = pref[ i - 1 ] ;
        pref[ i ].advance ( a[ i - 1 ] - 'a' ) ;
    }
    for ( int len = 1 ; len * k <= n ; ++ len ) {
        if ( same ( 1 , len * ( k - 1 ) , len + 1 , len * k ) == true ) {
            int l , r , mid ;
            l = 0 ;
            r = min ( len , n - k * len ) ;
            if ( len * k < mxset ) { l = mxset - len * k ; }
            while ( r - l > 3 ) {
                int mid = ( l + r ) / 2 ;
                if ( same ( 1 , mid , len * k + 1 , len * k + mid ) == true ) { l = mid ; }
                else { r = mid ; }
            }
            while ( r > l && same ( 1 , r , len * k + 1 , len * k + r ) == false ) { -- r ; }
            ++ add[ len * k ] ;
            -- add[ len * k + r + 1 ] ;
            mxset = len * k + r ;
        }
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt += add[ i ] ;
        if ( cnt > 0 ) { printf ( "1" ) ; }
        else { printf ( "0" ) ; }
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    MOD[ 0 ] = 1000000007 ;
    MOD[ 1 ] = 998244353 ;
    MOD[ 2 ] = 83928329 ;
    for ( int j = 0 ; j < NUM ; ++ j ) {
        pw[ 0 ].h[ j ] = 1 ;
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        pw[ i ] = pw[ i - 1 ] ;
        pw[ i ].advance ( 0 ) ;
    }
    input ( ) ;
    solve ( ) ;
    return 0 ;
}