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
using namespace std ;

#define MAXN 200007

int n ;
int cost[ MAXN ] ;
int a[ MAXN ] ;

int used[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &cost[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] != 0 ) { continue ; }
        int x = i ;
        vector < int > v ;
        v.clear ( ) ;
        while ( used[ x ] == 0 ) {
            v.push_back ( x ) ;
            used[ x ] = 1 ;
            x = a[ x ] ;
        }
        int sz = v.size ( ) ;
        int j ;
        bool fl = false ;
        int mncost = MAXN ;
        for ( j = 0 ; j < sz ; j ++ ) {
            if ( v[ j ] == x ) { fl = true ; }
            if ( fl == true ) {
                if ( mncost > cost[ v[ j ] ] ) {
                    mncost = cost[ v[ j ] ] ;
                }
            }
        }
        if ( mncost < MAXN ) { ans += mncost ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}