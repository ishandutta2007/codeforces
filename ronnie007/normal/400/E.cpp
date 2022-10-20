#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN  100007
#define MAXL  18

int n, m, a;
set<int> s[ MAXL ];

int main ( ) {
    int p , v ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 0 ; i < MAXL ; i ++ ) {
        s[ i ].insert ( 0 ) ;
        s[ i ].insert ( n + 1 ) ;
    }
    for (int i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a ) ;
        for (int j = 0 ; j < MAXL ; j++ ) {
            if ( !(a & (1 << j ) ) ) {
                s[ j ].insert( i ) ;
            }
        }
    }
    set < int > ::iterator it ;
    long long total = 0 ;
    for (int i = 0 ; i < MAXL ; i ++ ) {
        int last = -1 ;
        for ( it = s[ i ].begin ( ) ; it != s[ i ].end ( ) ; it ++ ) {
            long long d = *it - last - 1 ;
            total += ((d * ( d + 1 ) ) >> 1) << i ;
            last = *it ;
        }
    }
    while ( m != 0  ) {
        scanf ( "%d%d" , &p , &v ) ;
        for (int i = 0 ; i < MAXL ; i ++ ) {
            it = s[ i ].find( p ) ;
            if ( v & (1 << i ) ) {
                if ( it != s[ i ].end ( ) ) {
                    it -- ;
                    long long a = *it ;
                    it ++ ;
                    it ++ ;
                    long long b = *it ;
                    it -- ;
                    total += ( ( p - a ) * ( b - p ) ) << i ;
                    s[ i ].erase ( it ) ;
                }
            }
            else {
                if ( it == s[ i ].end ( ) ) {
                    it = s[ i ].upper_bound( p ) ;
                    long long b = *it ;
                    it -- ;
                    long long a = *it ;
                    total -= ( ( p - a ) * ( b - p ) ) << i ;
                    s[ i ].insert( p ) ;
                }
            }
        }
        printf ( "%I64d\n" , total ) ;
        m -- ;
    }
    return 0 ;
}