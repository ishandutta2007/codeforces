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

long long  n , m , k , q ;
long long  fst[ MAXN ] , lst[ MAXN ] ;
long long  a[ MAXN ] ;

long long  LEFT[ MAXN ] ;
long long  RIGHT[ MAXN ] ;
long long  target ;

void input ( ) {
    scanf ( "%I64d%I64d%I64d%I64d" , &n , &m , &k , &q ) ;
    for ( long long  i = 0 ; i <= n ; ++ i ) {
        fst[ i ] = m + 1 ;
        lst[ i ] = 0 ;
    }
    for ( long long  i = 0 ; i < k ; ++ i ) {
        long long  x , y ; scanf ( "%I64d%I64d" , &x , &y ) ;
        fst[ x ] = ( fst[ x ] < y ) ? fst[ x ] : y ;
        lst[ x ] = ( lst[ x ] < y ) ? y : lst[ x ] ;
    }
    target = 1 ;
    for ( long long  i = 1 ; i <= n ; ++ i ) {
        if ( fst[ i ] <= m ) { target = i ; }
    }
    for ( long long  i = 1 ; i <= q ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + q + 1 ) ;
    long long  id = 0 ;
    for ( long long  i = 1 ; i <= m ; ++ i ) {
        while ( id < q && a[ id + 1 ] <= i ) { ++ id ; }
        LEFT[ i ] = id ;
    }
    id = q + 1 ;
    for ( long long  i = m ; i >= 1 ; -- i ) {
        while ( id > 0 && a[ id - 1 ] >= i ) { -- id ; }
        RIGHT[ i ] = id ;
    }
}

void solve ( ) {
    vector < pair < long long , long long  > > dp ;
    dp.push_back ( { 0 , 1 } ) ;
    long long lazy = 0 ;
    for ( long long  i = 1 ; i <= n ; ++ i ) {
        if ( fst[ i ] > m ) {
            if ( i != 1 ) {
                ++ lazy ;
            }
            else {
                dp.clear ( ) ;
                for ( long long j = 1 ; j <= q ; ++ j ) {
                    dp.push_back ( { a[ j ] , a[ j ] } ) ;
                }
            }
            continue ;
        }

        vector < pair < long long , long long  > > cand ;
        cand.clear ( ) ;
        if ( LEFT[ fst[ i ] ] != 0 ) { cand.push_back ( { -1 , a[ LEFT[ fst[ i ] ] ] } ) ; }
        if ( RIGHT[ fst[ i ] ] != q + 1 ) { cand.push_back ( { -1 , a[ RIGHT[ fst[ i ] ] ] } ) ; }

        if ( LEFT[ lst[ i ] ] != 0 ) { cand.push_back ( { -1 , a[ LEFT[ lst[ i ] ] ] } ) ; }
        if ( RIGHT[ lst[ i ] ] != q + 1 ) { cand.push_back ( { -1 , a[ RIGHT[ lst[ i ] ] ] } ) ; }

        long long  sz = dp.size ( ) ;
        for ( long long  j = 0 ; j < dp.size ( ) ; ++ j ) {
            dp[ j ].first += lazy ;
        }
        lazy = 0 ;
        /// prv --> fst --> lst --> nxt
        long long w1 = -1 ;
        for ( long long  j = 0 ; j < sz ; ++ j ) {
            long long curr = dp[ j ].first + ( ( dp[ j ].second > fst[ i ] ) ? dp[ j ].second - fst[ i ] : fst[ i ] - dp[ j ].second ) + lst[ i ] - fst[ i ] ;
            if ( w1 == -1 ) { w1 = curr ; }
            if ( w1 > curr ) { w1 = curr ; }
        }
        /// prv --> lst --> fst --> nxt
        long long w2 = -1 ;
        for ( long long  j = 0 ; j < sz ; ++ j ) {
            long long curr = dp[ j ].first + ( ( dp[ j ].second > lst[ i ] ) ? dp[ j ].second - lst[ i ] : lst[ i ] - dp[ j ].second ) + lst[ i ] - fst[ i ] ;
            if ( w2 == -1 ) { w2 = curr ; }
            if ( w2 > curr ) { w2 = curr ; }
        }
        if ( i == target ) {
            printf ( "%I64d\n" , ( w1 < w2 ) ? w1 : w2 ) ;
            return ;
        }
        sz = cand.size ( ) ;
        for ( long long  j = 0 ; j < sz ; ++ j ) {
            long long curr1 = w1 + ( ( cand[ j ].second > lst[ i ] ) ? cand[ j ].second - lst[ i ] : lst[ i ] - cand[ j ].second ) ;
            long long curr2 = w2 + ( ( cand[ j ].second > fst[ i ] ) ? cand[ j ].second - fst[ i ] : fst[ i ] - cand[ j ].second ) ;
            cand[ j ].first = 1 + ( ( curr1 < curr2 ) ? curr1 : curr2 ) ;
        }
        dp = cand , cand.clear ( ) ;
    }
}

int  main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}