#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std ;


#define MAXN 200007

int n ;
int a[ MAXN ] ;

vector < int > v[ 37 ] ;

pair < int , int > srt[ MAXN ] ;

int l_id[ MAXN ][ 37 ] ;
int r_id[ MAXN ][ 37 ] ;

int aux[ 37 ] ;

class Tree {
    public :
    int tr[ 3 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( pos < IL || IR < pos ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = 1 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
    }
    int getl ( int where , int IL , int IR , int pos ) {
        if ( pos < IL ) { return 0 ; }
        if ( tr[ where ] == 0 ) { return 0 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = getl ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        if ( ret != 0 ) { return ret ; }
        return getl ( 2 * where , IL , mid , pos ) ;
    }
    int getr ( int where , int IL , int IR , int pos ) {
        if ( IR < pos ) { return ( n + 1 ) ; }
        if ( tr[ where ] == 0 ) { return ( n + 1 ) ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = getr ( 2 * where , IL , mid , pos ) ;
        if ( ret != ( n + 1 ) ) { return ret ; }
        return getr ( 2 * where + 1 , mid + 1 , IR , pos ) ;
    }
};

Tree w ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        srt[ i ] = make_pair ( -a[ i ] , i ) ;
        for ( j = 0 ; j <= 30 ; j ++ ) {
            if ( ( a[ i ] & (1<<j) ) != 0 ) {
                v[ j ].push_back ( i ) ;
            }
        }
    }
    sort ( srt + 1 , srt + n + 1 ) ;
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int i , j ;
    for ( i = 0 ; i <= 30 ; i ++ ) {
        aux[ i ] = 0 ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 0 ; j <= 30 ; j ++ ) {
            if ( ( a[ i ] & (1<<j) ) != 0 ) {
                aux[ j ] = i ;
            }
            l_id[ i ][ j ] = aux[ j ] ;
        }
    }
    for ( i = 0 ; i <= 30 ; i ++ ) {
        aux[ i ] = n + 1 ;
    }
    for ( i = n ; i >= 1 ; i -- ) {
        for ( j = 0 ; j <= 30 ; j ++ ) {
            if ( ( a[ i ] & (1<<j) ) != 0 ) {
                aux[ j ] = i ;
            }
            r_id[ i ][ j ] = aux[ j ] ;
        }
    }
    long long ans = n ;
    ans *= ( n + 1 ) ;
    ans /= 2 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        srt[ i ].first = -srt[ i ].first ;
        int st = 0 ;
        int en = n + 1 ;
        for ( j = 0 ; j <= 30 ; j ++ ) {
            if ( (srt[ i ].first & (1<<j) ) != 0 ) { continue ; }
            if ( st < l_id[ srt[ i ].second ][ j ] ) {
                st = l_id[ srt[ i ].second ][ j ] ;
            }
            if ( en > r_id[ srt[ i ].second ][ j ] ) {
                en = r_id[ srt[ i ].second ][ j ] ;
            }
        }
        int h1 = w.getl ( 1 , 1 , n , srt[ i ].second ) ;
        int h2 = w.getr ( 1 , 1 , n , srt[ i ].second ) ;
        if ( st < h1 ) { st = h1 ; }
        if ( en > h2 ) { en = h2 ; }
        ans -= 1LL * ( srt[ i ].second - st ) * ( en - srt[ i ].second ) ;
        w.update ( 1 , 1 , n , srt[ i ].second ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}