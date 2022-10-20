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
string a[ 1007 ] ;
int br[ 1007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> n >> m ;
    int i , j ;
    int x = -1 ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ;
        x = -1 ;
        for ( j = 0 ; j < m ; j ++ ) {
            if ( a[ i ][ j ] == 'G' || x != -1 ) x ++ ;
            if ( a[ i ][ j ] == 'S' && x == -1 ) {
                break ;
            }
            if ( a[ i ][ j ] == 'S' ) break ;
        }
        //if ( x != -1 ) { x ++ ; }
        br[ i ] = x ;
    }
}


void solve ( )  {
    int i , j ;
    int ans = 0 ;
    int lst = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        //cout << br[ i ] << "\n" ;
        if ( br[ i ] == -1 ) {
            break ;
        }
    }
    if ( i != n ) {
        printf ( "-1\n" ) ;
        return  ;
    }
    int x = 0 ;
    int x1 = 0 ;
    for ( i = 1 ; i <= m ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            if ( br[ j ] == i ) {
                break ;
            }
        }
        if ( j != n ) ans ++ ;
    }
    printf ( "%d\n" , ans ) ;
}