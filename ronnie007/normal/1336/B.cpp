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

#define MAXN 100007

int n[ 4 ] ;
int a[ 4 ][ MAXN ] ;
int perm[ 3 ] ;

long long ans ;

long long f_l ( int id , int sr ) {
    int l , r , mid ;
    l = 1 ;
    r = n[ id ] ;
    if ( a[ id ][ r ] < sr ) { return -1 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ id ][ mid ] < sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( a[ id ][ l ] < sr ) { ++ l ; }
    return a[ id ][ l ] ;
}

long long f_sm ( int id , int sr ) {
    int l , r , mid ;
    l = 1 ;
    r = n[ id ] ;
    if ( a[ id ][ l ] > sr ) { return -1 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ id ][ mid ] > sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( a[ id ][ r ] > sr ) { -- r ; }
    return a[ id ][ r ] ;
}

void upd_ans ( long long aux1 , long long aux2 , long long aux3 ) {
    if ( aux1 == -1 ) { return ; }
    if ( aux2 == -1 ) { return ; }
    if ( aux3 == -1 ) { return ; }
    long long sr = ( aux3 - aux2 ) * ( aux3 - aux2 ) ;
    sr += ( aux3 - aux1 ) * ( aux3 - aux1 ) ;
    sr += ( aux2 - aux1 ) * ( aux2 - aux1 ) ;
    if ( ans < 0 || ans > sr ) { ans = sr ; }    
}

void calc ( ) {
    for ( int i = 1 ; i <= n[ 1 ] ; ++ i ) {
        long long aux1 = a[ 1 ][ i ] ;
        long long aux2 = f_sm ( 2 , aux1 ) ;
        long long aux3 = f_l ( 3 , aux1 ) ;
        upd_ans ( aux1 , aux2 , aux3 ) ;

        aux2 = f_l ( 2 , aux1 ) ;
        aux3 = f_sm ( 3 , aux1 ) ;
        upd_ans ( aux1 , aux2 , aux3 ) ;
    }

    for ( int i = 1 ; i <= n[ 2 ] ; ++ i ) {
        long long aux1 = a[ 2 ][ i ] ;
        long long aux2 = f_sm ( 1 , aux1 ) ;
        long long aux3 = f_l ( 3 , aux1 ) ;
        upd_ans ( aux1 , aux2 , aux3 ) ;

        aux2 = f_l ( 1 , aux1 ) ;
        aux3 = f_sm ( 3 , aux1 ) ;
        upd_ans ( aux1 , aux2 , aux3 ) ;
    }

    for ( int i = 1 ; i <= n[ 3 ] ; ++ i ) {
        long long aux1 = a[ 3 ][ i ] ;
        long long aux2 = f_sm ( 2 , aux1 ) ;
        long long aux3 = f_l ( 1 , aux1 ) ;
        upd_ans ( aux1 , aux2 , aux3 ) ;

        aux2 = f_l ( 2 , aux1 ) ;
        aux3 = f_sm ( 1 , aux1 ) ;
        upd_ans ( aux1 , aux2 , aux3 ) ;
    }    
}

void input ( ) {
    for ( int i = 1 ; i <= 3 ; ++ i ) {
        scanf ( "%d" , &n[ i ] ) ;
    }
    for ( int i = 1 ; i <= 3 ; ++ i ) {
        for ( int j = 1 ; j <= n[ i ] ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
        sort ( a[ i ] + 1 , a[ i ] + n[ i ] + 1 ) ;
    }
}

void solve ( ) {
    ans = -1 ;
    calc ( ) ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}