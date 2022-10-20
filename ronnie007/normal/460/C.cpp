#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;


int n , m , w ;
int a[ 100007 ] ;
int p[ 100007 ] ;
int bal[ 100007 ] ;


void input ( ) ;
void solve ( ) ;

bool f ( int x ) {
    int i ;
    int ind ;
    long long br = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        bal[ i ] = 0 ;
        p[ i ] = a[ i ] ;
    }
    int h = 0 ;
    for ( i = 0 ; i + w - 1 < n ; i ++ ) {
        h += bal[ i ] ;
        p[ i ] += h ;
        if ( p[ i ] < x ) {
            bal[ i + 1 ] += ( x - p[ i ] ) ;
            bal[ i + w ] -= ( x - p[ i ] ) ;

            br += ( x - p[ i ] ) ;
            p[ i ] = x ;
        }
    }
    for ( i = n + 1 - w ; i < n ; i ++ ) {
        h += bal[ i ] ;
        p[ i ] += h ;
    }
    /**
    printf ( "x = %d\n" , x ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        printf ( "%d " , p[ i ] ) ;
    }
    printf ( "\n" ) ;
    **/
    int mx = 0 ;
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        if ( p[ i ] < x ) {
            if ( mx < ( x - p[ i ] ) ) mx = ( x - p[ i ] ) ;
        }
    }

    br += mx ;
    return ( br <= m ) ;
}

int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &w ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    int mn = -1 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( mn == -1 || mn > a[ i ] ) mn = a[ i ] ;
    }
    int l , r ;
    int mid ;
    l = 1 ;
    r = mn + m ;
    while ( r - l > 7 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) l = mid ;
        else r = mid ;
    }
    for ( i = l ; i <= r ; i ++ ) {
        if ( f ( i ) == false ) break ;
    }
    printf ( "%d\n" , i - 1 ) ;
}