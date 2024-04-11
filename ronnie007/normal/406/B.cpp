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

#define k 1000000

int n ;
int a[ 500007 ] ;
bool used[ 1000007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        used[ a[ i ] ] = true ;
    }
}


void solve ( )  {
    vector < int > ans ;
    ans.clear ( ) ;
    int i ;
    int d = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( used[ k - a[ i ] + 1 ] == false ) {
            ans.push_back ( k - a[ i ] + 1 ) ;
            used[ k - a[ i ] + 1 ] = true ;
        }
        else d ++ ;
    }
    d /= 2 ;
    //printf ( "%d\n" , d ) ;
    for ( i = 1 ; i <= k ; i ++ ) {
        if ( d == 0 ) break ;
        if ( used[ i ] == false && used[ k - i + 1 ] == false ) {
            ans.push_back ( i ) ;
            ans.push_back ( k - i + 1 ) ;
            used[ i ] = true ;
            used[ k - i + 1 ] = true ;
            d -- ;
        }
    }
    printf ( "%d\n" , ans.size ( ) ) ;
    int sz = ans.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}