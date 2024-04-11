#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

vector < int > a ;

long long sys[ 200001 ] ;
int ref[ 200001 ] ;

int find_set ( int r ) {
    if ( ref[ r ] == r ) return r ;
    return ref[ r ] = find_set ( ref[ r ] ) ;
}

int main() {
    int i ;
    for ( i = 0 ; i < 200001 ; i ++ ) ref[ i ] = i ;

    int n , m ;
    cin>>n;
    a.resize ( n ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    cin >> m ;
    for ( i = 0 ; i < m ; i ++ ) {
        int t ;
        cin >> t ;
        if ( t == 1 ) {
            long long p , x ;
            scanf ( "%I64d %I64d" , &p , &x ) ;
            int ind = find_set ( p - 1 ) ;
            while ( ind < n && x ) {
                int old = sys[ ind ] ;
                sys[ ind ] += min ( x , a[ ind ] - sys[ ind ] ) ;
                x -= sys[ ind ] - old ;
                if ( sys[ ind ] == a[ ind ]) ref[ ind ] = ind + 1 ;

                ind = find_set( ind ) ;
            }
        }
        else {
            int k ;
            cin >> k ;
            printf ( "%d\n" , sys [ k - 1 ] ) ;
        }
    }

    return 0 ;
}