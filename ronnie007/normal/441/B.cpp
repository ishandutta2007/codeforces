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

int n , v ;
pair < int , int > a[ 5007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &v ) ;
    int i ;
    int x , y ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
    sort ( a , a + n ) ;
}


void solve ( )  {
    int ans = 0 ;
    int i , j ;
    int ind = 0 ;
    int lft ;
    for ( i = 1 ; i <= 3001 ; i ++ ) {
        lft = v ;
        for ( j = 0 ; j < n ; j ++ ) {
            if ( lft == 0 ) break ;
            if ( a[ j ].first == i - 1 || a[ j ].first == i ) {
                if ( a[ j ].second < lft ) {
                    lft -= a[ j ].second ;
                    ans += a[ j ].second ;
                    a[ j ].second = 0 ;
                }
                else {
                    ans += lft ;
                    a[ j ].second -= lft ;
                    lft = 0 ;
                }
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}