
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 5007
#define inf 100000007
int lim ;

int n , m ;
int a[ MAXN ][ MAXN ] ;
int b[ MAXN ][ MAXN ] ;

vector < int > v_list[ MAXN ] ;
int list_sz[ MAXN ] ;

int dp[ MAXN ] ;
int nw[ MAXN ] ;

vector < int > shifted[ MAXN ] ;
int shifted_sz[ MAXN ] ;
bool st[ MAXN ] ;


int get_shift ( int mask ) {
    int lst = ( mask & (lim/2) ) ;
    mask -= lst ;
    mask *= 2 ;
    mask += ( lst != 0 ) ;
    return mask ;
}

int get_val ( int c , int mask ) {
    int ret = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( ( mask & (1<<i) ) != 0 ) {
            ret += a[ i + 1 ][ c ] ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            b[ i ][ j ] = a[ i ][ j ] ;
        }
    }
    if ( m > n ) {
        vector < pair < int , int > > srt ;
        for ( int j = 1 ; j <= m ; ++ j ) {
            pair < int , int > aux = { -1 , j } ;
            for ( int i = 1 ; i <= n ; ++ i ) {
                aux.first = max ( aux.first , a[ i ][ j ] ) ;
            }
            aux.first *= -1 ;
            srt.push_back ( aux ) ;
        }
        sort ( srt.begin ( ) , srt.end ( ) ) ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            for ( int i = 1 ; i <= n ; ++ i ) {
                a[ i ][ j ] = b[ i ][ srt[ j - 1 ].second ] ;
            }
        }
        m = n ;
    }

    lim = (1<<n) ;
    for ( int i = 0 ; i < lim ; ++ i ) {
        v_list[ i ].clear ( ) ;
        list_sz[ i ] = 0 ;
        shifted[ i ].clear ( ) ;
        shifted_sz[ i ] = 0 ;
        st[ i ] = false ;
    }
    for ( int i = 0 ; i < lim ; ++ i ) {
        for ( int j = 0 ; j < lim ; ++ j ) {
            if ( ( i & j ) == 0 ) {
                v_list[ i ].push_back ( j ) ;
                ++ list_sz[ i ] ;
            }
        }
    }
    for ( int i = 0 ; i < lim ; ++ i ) {
        st[ i ] = true ;
        int aux = i ;
        shifted[ i ].push_back ( i ) ;
        ++ shifted_sz[ i ] ;
        while ( 1 ) {
            aux = get_shift ( aux ) ;
            if ( aux == i ) { break ; }
            shifted[ i ].push_back ( aux ) ;
            ++ shifted_sz[ i ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 0 ; i < lim ; ++ i ) {
        dp[ i ] = -inf ;
    }
    dp[ 0 ] = 0 ;
    for ( int j = 1 ; j <= m ; ++ j ) {
        for ( int cm = 0 ; cm < lim ; ++ cm ) {
            nw[ cm ] = dp[ cm ] ;
        }
        for ( int mask = 1 ; mask < lim ; ++ mask ) {
            if ( st[ mask ] == false ) { continue ; }
            int aux = mask ;
            int val = -inf ;
            for ( int kk = 0 ; kk < shifted_sz[ mask ] ; ++ kk ) {
                val = max ( get_val ( j , shifted[ mask ][ kk ] ) , val ) ;
            }
            for ( int www = 0 ; www < list_sz[ aux ] ; ++ www ) {
                int cm = v_list[ aux ][ www ] ;
                if ( dp[ cm ] < 0 ) { continue ; }
                nw[ cm | aux ] = max ( nw[ cm | aux ] , dp[ cm ] + val ) ;
            }
        }
        for ( int cm = 0 ; cm < lim ; ++ cm ) {
            int aux = cm ;
            for ( int j = 0 ; j < n ; ++ j ) {
                dp[ aux ] = max ( dp[ aux ] , nw[ cm ] ) ;
                aux = get_shift ( aux ) ;
            }
        }
    }
    printf ( "%d\n" , dp[ lim - 1 ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }

    return 0 ;
}