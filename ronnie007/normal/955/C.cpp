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

int q ;
long long inf ;
int pr[ 167 ] ;
vector < pair < int , int > > v ;

long long f ( long long x ) {
    if ( x <= 0 ) { return 1 ; }
    int i , j , t ;
    long long ret = 0 ;
    int sz = v.size ( ) ;
    long long lstans = inf ;
    for ( t = 0 ; t < sz ; t ++ ) {
    //for ( i = 2 ; i <= 62 ; i ++ ) {
        i = v[ t ].first ;
        long long l , r , mid ;
        l = 1 ;
        r = lstans ;
        while ( r - l > 3 ) {
            mid = ( l + r ) / 2 ;
            long long aux = 1 ;
            for ( j = 1 ; j <= i ; j ++ ) {
                if ( aux > ( x / mid ) ) {
                    break ;
                }
                aux *= mid ;
            }
            if ( j > i ) { l = mid ; }
            else { r = mid ; }
        }

        while ( r > 0 ) {
            long long aux = 1 ;
            for ( j = 1 ; j <= i ; j ++ ) {
                if ( aux > ( x / r ) ) {
                    break ;
                }
                aux *= r ;
            }
            if ( j > i ) { break ; }
            else { r -- ; }
        }
        if ( ( v[ t ].second % 2 ) == 1 ) { ret += r ; }
        else { ret -= r ; }
        lstans = r ;
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &q ) ;
}

void solve ( ) {
    inf = 1 ;
    int i , j ;
    for ( i = 2 ; i <= 62 ; i ++ ) {
        if ( pr[ i ] != 0 ) { continue ; }
        int prsz = v.size ( ) ;
        v.push_back ( make_pair ( i , 1 ) ) ;
        for ( j = 0 ; j < prsz ; j ++ ) {
            if ( v[ j ].first * i <= 62 ) {
                v.push_back ( make_pair ( v[ j ].first * i , v[ j ].second + 1 ) ) ;
            }
        }
        for ( j = 2 * i ; j <= 62 ; j += i ) {
            pr[ j ] ++ ;
        }
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
    for ( i = 1 ; i <= 18 ; i ++ ) { inf *= 10 ; }
    inf += 7 ;
    long long l , r ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%I64d%I64d" , &l , &r ) ;
        printf ( "%I64d\n" , f ( r ) - f ( l - 1 ) ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}