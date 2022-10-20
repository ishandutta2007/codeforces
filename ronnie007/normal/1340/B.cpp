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

#define MAXN 2007

int n , k ;
string a[ MAXN ] ;

string dig[ 10 ] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" } ;

bool dp[ MAXN ][ MAXN ] ;

int dist ( int pos , int id ) {
    int ret = 0 ;
    for ( int i = 0 ; i < 7 ; ++ i ) {
        if ( a[ pos ][ i ] == '1' && dig[ id ][ i ] == '0' ) { return -1 ; }
        if ( a[ pos ][ i ] != dig[ id ][ i ] ) { ++ ret ; }
    }
    return ret ;
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    dp[ n + 1 ][ 0 ] = true ;
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = 0 ; j <= k ; ++ j ) {
            for ( int t = 0 ; t < 10 ; ++ t ) {
                int h = dist ( i , t ) ;
                if ( h == -1 ) { continue ; }
                if ( j < h ) { continue ; }
                if ( dp[ i + 1 ][ j - h ] == true ) {
                    dp[ i ][ j ] = true ;
                    break ;
                }
            }
        }
    }
    if ( dp[ 1 ][ k ] == false ) {
        cout << "-1\n" ;
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 9 ; j >= 0 ; -- j ) {
            int h = dist ( i , j ) ;
            if ( h == -1 ) { continue ; }
            if ( k < h ) { continue ; }
            if ( dp[ i + 1 ][ k - h ] == true ) {
                k -= h ;
                cout << j ;
                break ;
            }
        }
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}