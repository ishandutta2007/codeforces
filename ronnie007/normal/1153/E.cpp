#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 1007

int r[ MAXN ] ;
int c[ MAXN ] ;

int n ;


void calc ( vector < int > v , bool isrow ) {
    int i ;
    vector < pair < int , int > > ans ;
    ans.clear ( ) ;
    for ( i = 0 ; i < 2 ; i ++ ) {
        int aux = v[ i ] ;
        int l , r , mid ;
        l = 1 ;
        r = n ;
        while ( l != r ) {
            mid = ( l + r ) / 2 ;
            int ret ;
            if ( isrow == true ) {
                printf ( "? %d %d %d %d\n" , aux , l , aux , mid ) ;
                fflush ( stdout ) ;
            }
            else {
                printf ( "? %d %d %d %d\n" , l , aux , mid , aux ) ;
                fflush ( stdout ) ;
            }
            scanf ( "%d" , &ret ) ;
            if ( ( ret % 2 ) == 1 ) { r = mid ; }
            else { l = mid + 1 ; }
        }
        if ( isrow == true ) {
            ans.push_back ( make_pair ( aux , l ) ) ;
        }
        else {
            ans.push_back ( make_pair ( l , aux ) ) ;
        }
    }
    printf ( "! %d %d %d %d\n" , ans[ 0 ].first , ans[ 0 ].second , ans[ 1 ].first , ans[ 1 ].second ) ;
    fflush ( stdout ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int i ;
    vector < int > v1 , v2 ;
    v1.clear ( ) ;
    v2.clear ( ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "? %d 1 %d %d\n" , i , i , n ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &r[ i ] ) ;
        if ( ( r[ i ] % 2 ) == 1 ) {
            v1.push_back ( i ) ;
        }
        if ( v1.size ( ) == 2 || v2.size ( ) == 2 ) { break ; }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( i == n ) { v2.push_back ( i ) ; break ; }
        printf ( "? 1 %d %d %d\n" , i , n , i ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &c[ i ] ) ;
        if ( ( c[ i ] % 2 ) == 1 ) {
            v2.push_back ( i ) ;
        }
        if ( v1.size ( ) == 2 || v2.size ( ) == 2 ) { break ; }
    }
    if ( v1.size ( ) == 2 ) {
        calc ( v1 , true ) ;
    }
    else {
        calc ( v2 , false ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}