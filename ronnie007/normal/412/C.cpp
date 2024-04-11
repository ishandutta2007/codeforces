#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
using namespace std;

int n , m ;
string a[ 100007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ;
    }
    m = a[ 0 ].size ( ) ;
}

void solve ( ) {
    int i , j , f ;
    f = -1 ;
    for ( i = 0 ; i < m ; i ++ ) {
        f = -1 ;
        for ( j = 0 ; j < n ; j ++ ) {
            if ( a[ j ][ i ] != '?' ) {
                if ( f == -1 ) f = ( a[ j ][ i ] - 'a' ) ;
                else {
                    if ( f != ( a[ j ][ i ] - 'a' ) ) { f = -2 ; break ; }
                }
            }
        }
        if ( f == -2 ) printf ( "?" ) ;
        else {
            if ( f == -1 ) f = 0 ;
            printf ( "%c" , char( f + 'a' ) ) ;
        }
    }
    printf ( "\n" ) ;
}