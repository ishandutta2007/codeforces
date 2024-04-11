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

#define MAXN 500007
#define MOD 1000000007

int n , m , k ;
long long a[ MAXN ] ;

pair < int , int > gr[ MAXN ] ;

long long st[ MAXN ] ;

set < int > s ;
set < int > comps ;
long long aux = 1 ;

int unites = 0 ;
int edges = 0 ;

int prv[ MAXN ] ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        prv[ k1 ] = k2 ;
        unites ++ ;
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    st[ 0 ] = 1 ;
    int i ;
    for ( i = 1 ; i <= max ( n , k ) ; i ++ ) {
        st[ i ] = ( 2 * st[ i - 1 ] ) % MOD ;
    }
    for ( i = 1 ; i <= k ; i ++ ) { aux *= 2 ; }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d" , &a[ i ] ) ;
        prv[ i ] = -1 ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d%d" , &gr[ i ].first , &gr[ i ].second ) ;
    }
}

void solve ( ) {
    long long ans ;
    ans = ( st[ n ] * st[ k ] ) % MOD ;
    if ( m == 0 ) { printf ( "%I64d\n" , ans ) ; return ; }
    int i ;
    vector < pair < long long , int > > vals ;
    for ( i = 1 ; i <= m ; i ++ ) {
        long long val = ( a[ gr[ i ].first ] ^ a[ gr[ i ].second ] ) ;
        ///if ( val >= aux ) { continue ; }
        vals.push_back ( make_pair ( val , i ) ) ;
    }
    if ( vals.size ( ) == 0 ) { printf ( "%I64d\n" , ans ) ; return ; }
    sort ( vals.begin ( ) , vals.end ( ) ) ;
    s.insert ( gr[ vals[ 0 ].second ].first ) ;
    s.insert ( gr[ vals[ 0 ].second ].second ) ;
    UNITE ( gr[ vals[ 0 ].second ].first , gr[ vals[ 0 ].second ].second ) ;
    edges = 1 ;
    int vec_size = vals.size ( ) ;
    for ( i = 1 ; i < vec_size ; i ++ ) {
        if ( vals[ i ].first == vals[ i - 1 ].first ) {
            s.insert ( gr[ vals[ i ].second ].first ) ;
            s.insert ( gr[ vals[ i ].second ].second ) ;
            edges ++ ;
            UNITE ( gr[ vals[ i ].second ].first , gr[ vals[ i ].second ].second ) ;
        }
        else {
            int sz = s.size ( ) ;
            ans = ( ans - st[ n ] + MOD ) % MOD ;
            long long cur = ( st[ sz - unites ] * st[ n - sz ] ) % MOD ;
            ans = ( ans + cur ) % MOD ;
            set < int > :: iterator it ;
            for ( it = s.begin ( ) ; it != s.end ( ) ; it ++ ) {
                prv[ (*it) ] = -1 ;
            }
            s.clear ( ) ;
            edges = 1 ;
            unites = 0 ;
            s.insert ( gr[ vals[ i ].second ].first ) ;
            s.insert ( gr[ vals[ i ].second ].second ) ;
            UNITE ( gr[ vals[ i ].second ].first , gr[ vals[ i ].second ].second ) ;
        }
    }
    int sz = s.size ( ) ;
    if ( sz > 0 ) {
        ans = ( ans - st[ n ] + MOD ) % MOD ;
        long long cur = ( st[ sz - unites ] * st[ n - sz ] ) % MOD ;
        ans = ( ans + cur ) % MOD ;
        s.clear ( ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
/**
5 4 1
0 1 0 1 0
1 2
2 3
3 4
4 5
**/