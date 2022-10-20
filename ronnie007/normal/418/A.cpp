#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std ;


int n , k ;
vector < pair < int , int > > v ;
int used[ 1007 ][ 1007 ] ; 




void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    int i , j ;
    int br = 0 ; 
    for ( i = 1 ; i <= n ; i ++ ) {
        br = 0 ;
        for ( j = 1 ; j <= n ; j ++ ) {
            if ( i == j ) continue ;
            if ( br == k ) break ;
            if ( used[ i ][ j ] == 1 ) continue ;
            br ++ ;
            v.push_back ( make_pair ( i , j ) ) ;
            used[ i ][ j ] = 1 ;
            used[ j ][ i ] = 1 ;
        }
        if ( br != k ) {
            printf ( "-1\n" ) ;
            return ;
        }
    }
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}