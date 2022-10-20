#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int ans = 0 ;
int a[ 7 ][ 7 ] ;
int x[ 7 ] ;

void input ( ) ;
void solve ( ) ;

int get ( ) {
    int i , j ;
    int ret = 0 ;
    for ( i = 0 ; i <= 5 ; i ++ ) {
        for ( j = i + 1 ; j <= 5 ; j ++ ) {
            if ( j % 2 == i % 2 ) {
                ret += ( a[ x[ j - 1 ] ][ x[ j ] ] + a[ x[ j ] ][ x[ j - 1 ] ] ) ;
            }
        }
    }
    return ret ;
}


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    int i , j ;
    for ( i = 1 ; i <= 5 ; i ++ ) {
        for ( j = 1 ; j <= 5 ; j ++ ) {
            cin >> a[ i ][ j ] ;
        }
    }
}


void solve ( )  {
    int i ;
    for ( i = 1 ; i <= 5 ; i ++ ) {
        x[ i ] = i ;
    }
    ans = get ( ) ;
    int cur ;
    while ( next_permutation ( x + 1 , x + 5 + 1 ) ) {
        cur = get ( ) ;
        if ( ans < cur ) ans = cur ;
    }
    cout << ans << "\n" ;
}