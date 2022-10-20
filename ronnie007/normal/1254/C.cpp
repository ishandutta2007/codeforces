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

#define MAXN 1007

int n ;
pair < long long , int > a[ MAXN ] ;
vector < int > v1 , v2 , v3 , v4 ;
int pt1 , pt2 , pt3 , pt4 ;
int top_cand , bot_cand ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 3 ; i <= n ; ++ i ) {
        printf ( "1 %d %d %d\n" , 1 , 2 , i ) ;
        fflush ( stdout ) ;
        scanf ( "%I64d" , &a[ i ].first ) ;
        a[ i ].second = i ;
    }
    sort ( a + 3 , a + n + 1 ) ;
}

void solve ( ) {
    pt1 = pt4 = 1 ;
    pt2 = pt3 = 2 ;
    top_cand = bot_cand = -1 ;
    for ( int i = 3 ; i <= n ; ++ i ) {
        int sign ;
        printf ( "2 1 2 %d\n" , a[ i ].second ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &sign ) ;
        if ( sign < 0 ) {
            if ( bot_cand == -1 ) { bot_cand = a[ i ].second ; }
            else {
                printf ( "2 %d %d %d\n" , pt1 , bot_cand , a[ i ].second ) ;
                fflush ( stdout ) ;
                int ret ;
                scanf ( "%d" , &ret ) ;
                if ( ret > 0 ) { pt2 = bot_cand ; v1.push_back ( bot_cand ) ; }
                else { pt1 = bot_cand ; v2.push_back ( bot_cand ) ; }
                bot_cand = a[ i ].second ;
            }
        }
        else {
            if ( top_cand == -1 ) { top_cand = a[ i ].second ; }
            else {
                printf ( "2 %d %d %d\n" , pt3 , top_cand , a[ i ].second ) ;
                fflush ( stdout ) ;
                int ret ;
                scanf ( "%d" , &ret ) ;
                if ( ret < 0 ) { pt4 = top_cand , v4.push_back ( top_cand ) ; }
                else { pt3 = top_cand ; v3.push_back ( top_cand ) ; }
                top_cand = a[ i ].second ;
            }
        }
    }
    if ( bot_cand != -1 ) { v1.push_back ( bot_cand ) ; }
    if ( top_cand != -1 ) { v3.push_back ( top_cand ) ; }
    printf ( "0" ) ;
    int sz1 = v1.size ( ) , sz2 = v2.size ( ) , sz3 = v3.size ( ) , sz4 = v4.size ( ) ;
    printf ( " 1" ) ;
    for ( int i = 0 ; i < sz1 ; ++ i ) {
        printf ( " %d" , v1[ i ] ) ;
    }
    for ( int i = sz2 - 1 ; i >= 0 ; -- i ) {
        printf ( " %d" , v2[ i ] ) ;
    }
    printf ( " 2" ) ;
    for ( int i = 0 ; i < sz3 ; ++ i ) {
        printf ( " %d" , v3[ i ] ) ;
    }
    for ( int i = sz4 - 1 ; i >= 0 ; -- i ) {
        printf ( " %d" , v4[ i ] ) ;
    }
    printf ( "\n" ) ;
    fflush ( stdout ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}