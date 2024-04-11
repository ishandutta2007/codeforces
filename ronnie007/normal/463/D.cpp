#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<cassert>
using namespace std;

int n , k ;
int a[ 7 ][ 1007 ] ;
int pos[ 7 ][ 1007 ] ;
int dp[ 1007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i , j ;
    for ( i = 1 ; i <= k ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            pos[ i ][ a[ i ][ j ] ] = j ;
        }
    }
}

void solve ( ) {
    int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) {
        dp[ i ] = 1 ;
        for ( j = 1 ; j < i ; j ++ ) {
            for ( t = 1 ; t <= k ; t ++ ) {
                if ( pos[ t ][ a[ 1 ][ i ] ] < pos[ t ][ a[ 1 ][ j ] ] ) break ;
            }
            if ( t == k + 1 ) {
                dp[ i ] = max ( dp[ i ] , dp[ j ] + 1 ) ;
            }
        }
    }
    int ans = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( ans == -1 || ans < dp[ i ] ) ans = dp[ i ] ;
    }
    printf ( "%d\n" , ans ) ;
}