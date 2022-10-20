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


int b , d ;
string a , c ;
int n , m ;

pair < int , int > p[ 177 ] ;

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
    cin >> b >> d ;
    cin >> a >> c ;
    n = a.size ( ) ;
    m = c.size ( ) ;
}


void solve ( )  {
    int i , j , t ;
    int ind = 0 ;
    for ( i = 0 ; i < m ; i ++ ) {
        ind = i ;
        for ( j = 0 ; j < n ; j ++ ) {

            if ( c[ ind ] == a[ j ] ) {
                ind ++ ;
                if ( ind == m ) {
                    ind = 0 ;
                    p[ i ].first ++ ;
                }
            }
        }
        p[ i ].second = ind ;
        ///cout << ind << "\n" ;
    }

    int ans = 0 ;
    int x = 0 ;
    for ( i = 0 ; i < b ; i ++ ) {
        ans += p[ x ].first ;
        x = p[ x ].second ;
    }
    printf ( "%d\n" , ans / d ) ;
}