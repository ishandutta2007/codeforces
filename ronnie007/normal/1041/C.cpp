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

int n , m , k ;
pair < int , int > a[ MAXN ] ;

int ans[ MAXN ] ;

priority_queue < pair < int , int > > q ;


void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ].first ) ;
        a[ i ].second = i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int mxval = 1 ;
    ans[ a[ 1 ].second ] = 1 ;
    q.push ( make_pair ( -a[ 1 ].first , 1 ) ) ;
    int i ;
    for ( i = 2 ; i <= n ; i ++ ) {
        pair < int , int > p = q.top ( ) ;
        q.pop ( ) ;
        if ( a[ i ].first + p.first > k ) {
            p.first = -a[ i ].first ;
            q.push ( p ) ;
            ans[ a[ i ].second ] = p.second ;
        }
        else {
            q.push ( p ) ;
            p.first = -a[ i ].first ;
            mxval ++ ;
            p.second = mxval ;
            q.push ( p ) ;
            ans[ a[ i ].second ] = p.second ;
        }
    }
    printf ( "%d\n" , mxval ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}