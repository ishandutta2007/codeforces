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

int n , m ;
long long br1[ 1007 ] ;
long long br2[ 1007 ] ;

long long a[ 1007 ] ;
long long b[ 1007 ] ;


void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    int i , j ;
    scanf ( "%d%d" , &n , &m ) ;
    int x ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            scanf ( "%d" , &x ) ;
            a[ i ] += x ;
            b[ j ] += x ;
        }
    }
}


void solve ( )  {
    int i , j ;
    for ( i = 0 ; i <= n ; i ++ ) {
        br1[ i ] = 0 ;
        for ( j = 1 ; j <= n ; j ++ )
        br1[ i ] += ( j * 4 - 2 - i * 4 ) * ( j * 4 - 2 - i * 4 ) * a[ j ] ;
    }
    for ( i = 0 ; i <= m ; i ++ ) {
        br2[ i ] = 0 ;
        for ( j = 1 ; j <= m ; j ++ )
        br2[ i ] += ( j * 4 - 2 - i * 4 ) * ( j * 4 - 2 - i * 4 ) * b[ j ] ;
    }
    long long ans = br1[ 0 ]+ br2[ 0 ] ;
    int ans1 = 0 ;
    int ans2 = 0 ;
    for ( i = 0 ; i <= n ; i ++ ) {

        for ( j = 0 ; j <= m ; j ++ ) {
            if ( br1[ i ] + br2[ j ] < ans ) {
                ans = br1[ i ] + br2[ j ] ;
                ans1 = i ;
                ans2 = j ;
            }
        }
    }
    printf ( "%I64d\n%d %d\n" , ans , ans1 , ans2 ) ;
}