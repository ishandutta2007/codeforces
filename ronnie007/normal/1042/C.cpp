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

#define MAXN 200007
#define inf 1000000007

int n ;
pair < int , int > a[ MAXN ] ;

int used[ MAXN ] ;

int zero = 0 ;
int neg = 0 ;

int mnval ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    mnval = -inf ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ].first ) ;
        a[ i ].second = i ;
        zero += ( a[ i ].first == 0 ) ;
        neg += ( a[ i ].first < 0 ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int rem = ( ( neg % 2 ) + zero ) ;
    int i ;
    int hh = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ].first < 0 ) { hh = i ; }
    }
    if ( rem < n ) {
        vector < int > v ;
        v.clear ( ) ;
        int lst = -1 ;
        if ( ( neg % 2 ) == 1 ) { v.push_back ( hh ) ; used[ hh ] = 1 ; lst = hh ; }
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( a[ i ].first == 0 ) {
                if ( lst == -1 ) { lst = i ; used[ i ] = 1 ; }
                else {
                    printf ( "1 %d %d\n" , a[ lst ].second , a[ i ].second ) ;
                    used[ i ] = 1 ;
                    lst = i ;
                }
            }
        }
        if ( rem > 0 ) {
            printf ( "2 %d\n" , a[ lst ].second ) ;
        }
        lst = -1 ;
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( used[ i ] == 1 ) { continue ; }
            if ( lst == -1 ) { lst = i ; }
            else { printf ( "1 %d %d\n" , a[ lst ].second , a[ i ].second ) ; lst = i ; }
        }
    }
    else {
        int i ;
        for ( i = 1 ; i < n - 1 ; i ++ ) {
            printf ( "1 %d %d\n" , a[ i ].second , a[ i + 1 ].second ) ;
        }
        printf ( "2 %d\n" , a[ n - 1 ].second ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}