#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 300007

int n ;
string a ;

int f[ MAXN ] ;
int aux[ MAXN ] ;

int shift ;

void input ( ) {
    cin >> n >> a ;
    int mn = n + 2 ;
    shift = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux[ i ] = ( aux[ i - 1 ] + ( a[ i - 1 ] == '(' ? 1 : -1 ) ) ;
        if ( mn > aux[ i ] ) { mn = aux[ i ] , shift = i ; }
    }
    ++ shift ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        f[ i ] = f[ i - 1 ] + ( a[ shift - 1 ] == '(' ? 1 : -1 ) ;
        ++ shift ;
        if ( shift > n ) { shift -= n ; }
    }
}

void solve ( ) {
    if ( f[ n ] != 0 ) { printf ( "0\n1 1\n" ) ; return ; }
    int mx = 0 ;
    int cnt = 0 ;
    int init = 0 ;
    int lst = 0 ;
    pair < int , int > ans ;
    ans = { 1 , 1 } ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( f[ i ] == 0 ) {
            if ( mx < cnt ) {
                mx = cnt ;
                ans = { lst + 1 , i } ;
            }
            cnt = 0 ; ++ init ;
            lst = i ;
        }
        else { cnt += ( f[ i ] == 1 ) ; }
    }
    lst = cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( f[ i ] == 1 ) {
            if ( mx < init + cnt ) {
                mx = init + cnt ;
                ans = { lst + 1 , i } ;
            }
            cnt = 0 ;
            lst = i ;
        }
        else { cnt += ( f[ i ] == 2 ) ; }
    }
    printf ( "%d\n" , mx ) ;
    -- shift ;
    ans.first += shift , ans.second += shift ;
    if ( ans.first > n ) { ans.first -= n ; }
    if ( ans.second > n ) { ans.second -= n ; }
    printf ( "%d %d\n" , ans.first , ans.second ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}