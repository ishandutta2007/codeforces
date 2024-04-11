#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int n ;
int a[ 500007 ] ;
int l[ 500007 ] ;
int r[ 500007 ] ;
long long ans = 0 ;


pair < int , int > p[ 500007 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;

        p[ i ].first = a[ i ] ;
        p[ i ].second = i ;
    }
    sort ( p , p + n ) ;
}

void solve ( ) {
    if ( n < 3 ) {
        printf ( "0\n" ) ;
        return ;
    }
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        l[ i ] = i - 1 ;
        r[ i ] = i + 1 ;
    }
    int ind ;
    int x , y ;
    int lo = 0 ;
    int hi = n - 1 ;
    for ( i = 0 ; i < n - 2 ; i ++ ) {
        ind = p[ i ].second ;
        ///printf ( "%d\n" , ind ) ;
        if ( ind == lo ) {
            ans += p[ i ].first ;
            lo = r[ ind ] ;
            continue ;
        }
        if ( ind == hi ) {
            ans += p[ i ].first ;
            hi = l[ ind ] ;
            continue ;
        }
        x = l[ ind ] ;
        y = r[ ind ] ;
        ans += min ( a[ x ] , a[ y ] ) ;
        r[ x ] = y ;
        l[ y ] = x ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}