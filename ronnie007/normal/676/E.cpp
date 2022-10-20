#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std ;

#define MAXN 100007

#define MOD1 1000000007
#define MOD2 98231323
#define MOD3 78654659

int n , k ;
int a[ MAXN ] ;

int br ;
int turn ;
bool fl = true ;

int parse ( string s ) {
    int coef = 1 ;
    int st = 0 ;
    if ( s[ 0 ] == '-' ) { st = 1 ; coef = -1 ; }
    int i ;
    int ret = 0 ;
    for ( i = st ; i < s.size ( ) ; i ++ ) {
        ret = ( ret * 10 + ( s[ i ] - '0' ) ) ;
    }
    ret *= coef ;
    return ret ;
}

void input ( ) {
    cin >> n >> k ;
    string str ;
    int i ;
    br = 0 ;
    for ( i = n + 1 ; i >= 1 ; i -- ) {
        cin >> str ;
        if ( str == "?" ) {
            br ++ ;
            if ( i == n + 1 ) { fl = false ; }
        }
        else {
            turn ++ ;
            a[ i ] = parse ( str ) ;
        }
    }
}

void solve ( ) {
    int i ;
    if ( br == 0 ) {
        long long u1 , u2 , u3 ;
        u1 = u2 = u3 = 0 ;
        for ( i = 1 ; i <= n + 1 ; i ++ ) {
            u1 = ( u1 * k + a[ i ] ) % MOD1 ;
            u2 = ( u2 * k + a[ i ] ) % MOD2 ;
            u3 = ( u3 * k + a[ i ] ) % MOD3 ;
        }
        if ( u1 != 0 || u2 != 0 || u3 != 0 ) {
            printf ( "No\n" ) ;
        }
        else {
            printf ( "Yes\n" ) ;
        }
        return ;
    }
    if ( k == 0 ) {
        if ( fl == true ) {
            if ( a[ n + 1 ] == 0 ) { printf ( "Yes\n" ) ; }
            else { printf ( "No\n" ) ; }
        }
        else {
            if ( ( turn % 2 ) == 1 ) { printf ( "Yes\n" ) ; }
            else { printf ( "No\n" ) ; }
        }
    }
    else {
        if ( ( n % 2 ) == 1 ) {
            printf ( "Yes\n" ) ;
        }
        else {
            printf ( "No\n" ) ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}