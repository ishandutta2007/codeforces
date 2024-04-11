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

int n ;
long long sr ;
long long a[ MAXN ] ;
long long pref[ MAXN ] ;
int id[ MAXN ] ;


pair < long long , int > srt[ MAXN ] ;

class Tree {
    public :
    int tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IL > IR ) { return ; }
        if ( pos < IL || IR < pos ) { return ; }
        if ( IL == IR ) { tr[ where ] ++ ; return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR ) { return 0 ; }
        if ( CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

int get ( long long val ) {
    int l , r , mid ;
    l = 0 ;
    r = ( n - 1 ) ;
    if ( srt[ n - 1 ].first <= val ) { return ( n + 1 ) ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( srt[ mid ].first <= val ) { l = mid ; }
        else { r = mid ; }
    }
    while ( srt[ l ].first <= val ) { l ++ ; }
    return ( l + 1 ) ;
}


void input ( ) {
    scanf ( "%d%I64d" , &n , &sr ) ;
    int i ;
    srt[ 0 ] = make_pair ( 0 , 0 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d" , &a[ i ] ) ;
        pref[ i ] = ( pref[ i - 1 ] + a[ i ] ) ;
        srt[ i ] = make_pair ( pref[ i ] , i ) ;
    }
    sort ( srt , srt + n ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        id[ srt[ i ].second ] = i + 1 ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    w.update ( 1 , 1 , n , id[ 0 ] ) ;
    int i ;
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        long long aux = ( pref[ i ] - sr ) ;
        int pos = get ( aux ) ;
        ans += w.query ( 1 , 1 , n , pos , n ) ;
        w.update ( 1 , 1 , n , id[ i ] ) ;
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