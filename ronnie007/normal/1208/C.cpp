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

#define MAXN 1007

int n ;
int ans[ MAXN ][ MAXN ] ;

void upd ( int x , int y , int val ) {
    for ( int j = 0 ; j < 4 ; ++ j ) {
        for ( int i = 0 ; i < 4 ; ++ i ) {
            ans[ x + i ][ y + j ] = val ++ ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int id = 0 ;
    for ( int i = 0 ; i < n ; i += 4 ) {
        for ( int j = 0 ; j < n ; j += 4 ) {
            upd ( i , j , id ) ;
            id += 16 ;
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            printf ( "%d " , ans[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}