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

int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    sort ( a + 1 , a + n + 1 ) ;
    bool fl = false ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] == a[ i - 1 ] ) { fl = true ; }
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( a[ i ] == a[ i + 1 ] && a[ i ] > 0 ) {
            -- a[ i ] ;
            break ;
        }
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( a[ i ] == a[ i + 1 ] ) {
            printf ( "cslnb\n" ) ;
            return ;
        }
    }
    long long sm = 0 ;
    if ( fl == true ) { ++ sm ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] -= ( i - 1 ) ;
        sm += a[ i ] ;
    }
    if ( sm % 2 != 0 ) { printf ( "sjfnb\n" ) ; }
    else { printf ( "cslnb\n" ) ; }    
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}