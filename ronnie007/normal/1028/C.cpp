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
using namespace std ;

#define MAXN 200007

int n ;
struct tuhla {
    int mnx , mxx ;
    int mny , mxy ;
};

tuhla UNITE ( tuhla p1 , tuhla p2 ) {
    tuhla ret ;
    ret.mnx = max ( p1.mnx , p2.mnx ) ;
    ret.mxx = min ( p1.mxx , p2.mxx ) ;

    ret.mny = max ( p1.mny , p2.mny ) ;
    ret.mxy = min ( p1.mxy , p2.mxy ) ;
    return ret ;
}

bool check ( tuhla aux ) {
    if ( aux.mnx > aux.mxx ) { return false ; }
    if ( aux.mny > aux.mxy ) { return false ; }
    return true ;
}

tuhla a[ MAXN ] ;

tuhla pref[ MAXN ] ;
tuhla suff[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d%d%d" , &a[ i ].mnx , &a[ i ].mny , &a[ i ].mxx , &a[ i ].mxy ) ;
    }
    pref[ 1 ] = a[ 1 ] ;
    for ( i = 2 ; i <= n ; i ++ ) {
        pref[ i ] = UNITE ( pref[ i - 1 ] , a[ i ] ) ;
    }
    suff[ n ] = a[ n ] ;
    for ( i = n - 1 ; i >= 1 ; i -- ) {
        suff[ i ] = UNITE ( suff[ i + 1 ] , a[ i ] ) ;
    }
}

void solve ( ) {
    if ( check ( pref[ n - 1 ] ) == true ) {
        printf ( "%d %d\n" , pref[ n - 1 ].mnx , pref[ n - 1 ].mny ) ;
        return ;
    }
    if ( check ( suff[ 2 ] ) == true ) {
        printf ( "%d %d\n" , suff[ 2 ].mnx , suff[ 2 ].mny ) ;
        return ;
    }
    int i ;
    for ( i = 2 ; i < n ; i ++ ) {
        tuhla ret = UNITE ( pref[ i - 1 ] , suff[ i + 1 ] ) ;
        if ( check ( ret ) == true ) {
            printf ( "%d %d\n" , ret.mnx , ret.mny ) ;
            return ;
        }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}