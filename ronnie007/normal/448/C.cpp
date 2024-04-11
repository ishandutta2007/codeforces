#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std;

int n ;
int a[ 5007 ] ;


void input ( ) ;
void solve ( ) ;

int f ( int l , int r ) {
    if ( l == r ) {
        if ( a[ l ] == 0 ) return 0 ;
        return 1 ;
    }
    int i ;
    int mn = -1 ;
    int br = 0 ;
    int ind = -1 ;
    for ( i = l ; i <= r ; i ++ ) {
        if ( a[ i ] != 0 ) br ++ ;
        if ( mn < 0 || mn > a[ i ] ) {
            mn = a[ i ] ;
            ind = i ;
        }
    }
    for ( i = l ; i <= r ; i ++ ) {
        a[ i ] -= mn ;
    }
    int u ;
    u = mn ;
    if ( ind != l ) {
        u += f ( l , ind - 1 ) ;
    }
    if ( ind != r ) {
        u += f ( ind + 1 , r ) ;
    }
    return ( min ( br , u ) ) ;
}


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int ans = f ( 0 , n - 1 ) ;
    printf ( "%d\n" , ans ) ;
}