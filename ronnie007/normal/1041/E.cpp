#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;


#define MAXN 1007

int n ;
int a[ MAXN ] ;
int br[ MAXN ] ;
int used[ MAXN ] ;

bool wa = false ;

int ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        int x ;
        scanf ( "%d%d" , &a[ i ] , &x ) ;
        br[ a[ i ] ] ++ ;
        if ( x != n ) { wa = true ; }
    }
}

void solve ( ) {
    if ( wa == true ) { printf ( "NO\n" ) ; return ; }
    sort ( a + 1 , a + n ) ;
    ans[ n ] = n ;
    int i ;
    int pos = n ;
    for ( i = n - 1 ; i >= 1 ; i -- ) {
        if ( br[ i ] == 0 ) { continue ; }
        while ( br[ i ] > 0 ) { pos -- ; br[ i ] -- ; }
        ans[ pos ] = i ;
        used[ i ] = 1 ;
    }
    int nw = n - 1 ;
    for ( i = n - 1 ; i >= 1 ; i -- ) {
        if ( ans[ i ] == 0 ) {
            while ( used[ nw ] == 1 ) { nw -- ; }
            ans[ i ] = nw ;
            used[ nw ] = 1 ;
        }
    }
    int mx = 0 ;
    for ( i = 1 ; i < n ; i ++ ) {
        mx = max ( mx , ans[ i ] ) ;
        if ( mx != a[ i ] ) { printf ( "NO\n" ) ; return ; }
    }
    printf ( "YES\n" ) ;
    for ( i = 1 ; i < n ; i ++ ) {
        printf ( "%d %d\n" , ans[ i ] , ans[ i + 1 ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}