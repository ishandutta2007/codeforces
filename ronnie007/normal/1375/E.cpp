#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
int a[ MAXN ] ;
int pos[ MAXN ] ;
pair < int , int > b[ MAXN ] ;

vector < pair < int , int > > v ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        b[ i ] = { a[ i ] , i } ;
    }
    sort ( b + 1 , b + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ b[ i ].second ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        pos[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = a[ i ] + 1 ; j <= i ; ++ j ) {
            v.push_back ( { pos[ j ] , i } ) ;
            -- a[ pos[ j ] ] ;
        }
        for ( int j = 1 ; j < i ; ++ j ) {
            pos[ a[ j ] ] = j ;
        }
    }
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}