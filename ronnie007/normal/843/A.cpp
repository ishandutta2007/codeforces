#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int rev[ MAXN ] ;
int used[ MAXN ] ;

vector < pair < int , int > > srt ;
vector < int > ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        srt.push_back ( make_pair ( a[ i ] , i ) ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        b[ srt[ i ].second ] = ( i + 1 ) ;
        rev[ ( i + 1 ) ] = srt[ i ].second ;
    }
}

void solve ( ) {
    int i , j ;
    int x ;
    int tot = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ rev[ i ] ] == 1 ) { continue ; }
        tot ++ ;
        x = rev[ i ] ;
        while ( used[ x ] == 0 ) {
            ans[ tot ].push_back ( x ) ;
            used[ x ] = 1 ;
            x = b[ x ] ;
            if ( used[ x ] == 1 ) { break ; }
        }
    }
    printf ( "%d\n" , tot ) ;
    for ( i = 1 ; i <= tot ; i ++ ) {
        int sz = ans[ i ].size ( ) ;
        printf ( "%d" , sz ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            printf ( " %d" , ans[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}