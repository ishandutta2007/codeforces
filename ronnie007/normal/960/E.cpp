#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 200007
#define MOD 1000000007

int n ;
long long a[ MAXN ] ;
vector < int > v[ MAXN ] ;

int used[ MAXN ] ;
int subtree[ MAXN ] ;

int lvl[ MAXN ] ;

long long cnt[ 2 ] ;
long long aux[ MAXN ][ 2 ] ;

long long ans ;

int tot ;

void recalc_subtree ( int vertex , int prv ) {
    tot ++ ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        recalc_subtree ( v[ vertex ][ i ] , vertex ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
    }
}

int get_centroid ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        if ( subtree[ v[ vertex ][ i ] ] > ( tot / 2 ) ) {
            return get_centroid ( v[ vertex ][ i ] , vertex ) ;
        }
    }
    return vertex ;
}

void relabel ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        relabel ( v[ vertex ][ i ] , vertex ) ;
    }
}

void add ( int vertex , int prv , int coef ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    cnt[ ( lvl[ vertex ] % 2 ) ] += coef ;
    aux[ vertex ][ 0 ] = aux[ vertex ][ 1 ] = 0 ;
    aux[ vertex ][ ( lvl[ vertex ] % 2 ) ] -= coef ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        add ( v[ vertex ][ i ] , vertex , coef ) ;
        aux[ vertex ][ 0 ] += aux[ v[ vertex ][ i ] ][ 0 ] ;
        aux[ vertex ][ 1 ] += aux[ v[ vertex ][ i ] ][ 1 ] ;
    }
}

void calc ( int vertex , int prv , int cen ) {
    int id = ( lvl[ vertex ] % 2 ) ;
    long long tm = ( 2 * cnt[ id ] * aux[ vertex ][ id ] ) % MOD ;
    tm = ( tm * a[ vertex ] ) % MOD ;
    if ( tm < 0 ) { tm += MOD ; }
    ans = ( ans + tm ) ;
    if ( ans > MOD ) { ans -= MOD ; }
    ///if ( cen == 1 ) { printf ( "%d --> %I64d ---> %I64d\n" , vertex , tm , ans ) ; }
    tm = ( 2 * cnt[ (id^1) ] * aux[ vertex ][ (id^1) ] ) % MOD ;
    tm = ( tm * a[ vertex ] ) % MOD ;
    if ( tm < 0 ) { tm += MOD ; }
    ans -= tm ;
    if ( ans < 0 ) { ans += MOD ;}
    ///if ( cen == 1 ) { printf ( "%d --> %I64d --> %I64d\n" , vertex , tm , ans ) ; }
    if ( id == 0 ) {
        tm = ( 2 * aux[ vertex ][ id ] ) % MOD ;
        tm = ( tm * ( a[ vertex ] ) ) % MOD ;
        if ( tm < 0 ) { tm += MOD ; }
        ans = ( ans + tm ) % MOD ;
        ans = ( ans + 2 * a[ cen ] ) % MOD ;
        if ( ans < 0 ) { ans += MOD ; }
    }
    else {
        tm = ( 2 * aux[ vertex ][ (id^1) ] ) % MOD ;
        tm = ( tm * ( -a[ vertex ] ) ) % MOD ;
        if ( tm < 0 ) { tm += MOD ; }
        ans = ( ans + tm ) ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        calc ( v[ vertex ][ i ] , vertex , cen ) ;
    }
}

void decompose ( int vertex , int prv ) {
    tot = 0 ;
    recalc_subtree ( vertex , prv ) ;
    int c = get_centroid ( vertex , prv ) ;
    used[ c ] = 1 ;
    lvl[ c ] = 0 ;
    relabel ( c , prv ) ;
    int sz = v[ c ].size ( ) ;
    int i ;
    ///printf ( "%d\n" , c ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ c ][ i ] ] != 0 ) { continue ; }
        add ( v[ c ][ i ] , c , 1 ) ;
    }
    ///printf ( "--- %I64d %I64d\n" , cnt[ 0 ] , cnt[ 1 ] ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ c ][ i ] ] != 0 ) { continue ; }
        add ( v[ c ][ i ] , c , -1 ) ;
        ///printf ( "--- %I64d %I64d -- %I64d %I64d\n" , cnt[ 0 ] , cnt[ 1 ] , aux[ v[ c ][ i ] ][ 0 ] , aux[ v[ c ][ i ] ][ 1 ] ) ;
        long long tm = ( cnt[ 0 ] * aux[ v[ c ][ i ] ][ 0 ] ) % MOD ;
        tm = ( tm * a[ c ] ) % MOD ;
        if ( tm < 0 ) { tm += MOD ; }
        ans = ( ans + tm ) ;
        if ( ans >= MOD ) { ans -= MOD ; }

        tm = ( cnt[ 1 ] * aux[ v[ c ][ i ] ][ 1 ] ) % MOD ;
        tm = ( tm * a[ c ] ) % MOD ;
        if ( tm < 0 ) { tm += MOD ; }
        ans = ( ans - tm ) ;
        if ( ans < 0 ) { ans += MOD ; }

        ///printf ( "CALCULATED %I64d\n" , ans ) ;

        calc ( v[ c ][ i ] , c , c ) ;
        add ( v[ c ][ i ] , c , 1 ) ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ c ][ i ] ] != 0 ) { continue ; }
        add ( v[ c ][ i ] , c , -1 ) ;
    }
    ///printf ( "--- %I64d\n" , ans ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ c ][ i ] ] != 0 ) { continue ; }
        decompose ( v[ c ][ i ] , c ) ;
    }

}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d" , &a[ i ] ) ;
        ans = ( ans + a[ i ] ) ;
        if ( ans < 0 ) { ans += MOD ; }
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    decompose ( 1 , -1 ) ;
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}