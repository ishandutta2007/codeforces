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
int a[ 100007 ] ;
int b[ 100007 ] ;

void input ( ) ;
void solve ( ) ;


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
        b[ i ] = a[ i ] ;
    }
}

void solve ( ) {
    sort ( b , b + n ) ;
    int i , j ;
    int st , en ;
    for ( i = 0 ;  i < n ; i ++ ) {
        if ( a[ i ] != b[ i ] ) {
            break ;
        }
    }
    st = i ;
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        if ( a[ i ] != b[ i ] ) {
            break ;
        }
    }
    en = i ;
    if ( st == n && en == -1 ) { st = 0 ; en = 0 ; }
    int len = ( en - st + 1 ) ;
    for ( i = 0 ; i < len / 2 ; i ++ ) {
        swap ( a[ st + i ] , a[ en - i ] ) ;
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] != b[ i ] ) {
            printf ( "no\n" ) ;
            return ;
        }
    }
    printf ( "yes\n" ) ;
    printf ( "%d %d\n" , st + 1 , en + 1 ) ;
}