#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
using namespace std;

int n , m , x , y , z , p ;

pair < int , int > a[ 100007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    scanf ( "%d%d%d" , &x , &y , &z ) ;
    scanf ( "%d" , &p ) ;
    int i ;
    for ( i = 0 ; i < p ; i ++ ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        a[ i ].first -- ;
        a[ i ].second -- ;
    }
    x %= 4 ;
    y %= 2 ;
    z %= 4 ;
}

void solve ( ) {
    int i , j ;
    int u , w ;
    n -- ;
    m -- ;
    //printf ( "------\n" ) ;
    for ( i = 0 ; i < x ; i ++ ) {
        for ( j = 0 ; j < p ; j ++ ) {
            u = a[ j ].first ;
            w = a[ j ].second ;
            a[ j ].first = w ;
            a[ j ].second = n - u ;
        }
        swap ( n , m ) ;
    }
    //for ( i = 0 ; i < p ; i ++ ) {
    //  printf ( "%d %d\n" , a[ i ].first , a[ i ].second ) ;
    //}
    //printf ( "---------\n" ) ;
    for ( i = 0 ; i < y ; i ++ ) {
        for ( j = 0 ; j < p ; j ++ ) {
            u = a[ j ].first ;
            w = a[ j ].second ;
            a[ j ].first = u ;
            a[ j ].second = m - w ;
        }
    }


    for ( i = 0 ; i < z ; i ++ ) {
        for ( j = 0 ; j < p ; j ++ ) {
            u = a[ j ].first ;
            w = a[ j ].second ;
            a[ j ].first = m - w ;
            a[ j ].second = u ;
        }
        swap ( n , m ) ;
    }
    for ( i = 0 ; i < p ; i ++ ) {
        printf ( "%d %d\n" , a[ i ].first + 1 , a[ i ].second + 1 ) ;
    }
}