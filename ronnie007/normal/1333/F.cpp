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
#include<random>
using namespace std ;

#define MAXN 500007
int n ;
int cnt[ MAXN ] ;
bool used[ MAXN ] ;

int ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    for ( int i = n / 2 ; i >= 1 ; -- i ) {
        cnt[ i ] = 1 ;
        for ( int j = 2 * i ; j <= n ; j += i ) {
            if ( used[ j ] == false ) { ++ cnt[ i ] ; }
            used[ j ] = true ;
        }
    }
    int pos = ( n / 2 ) ;
    for ( int i = n ; i >= 2 ; -- i ) {
        -- cnt[ pos ] ;
        ans[ i ] = pos ;        
        while ( pos > 1 && cnt[ pos ] < 2 ) { -- pos ; }

    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}