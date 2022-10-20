#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;
int ans[ 1007 ][ 1007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) 
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( ) 
    {
    scanf ( "%d" , &n ) ;
    }

void solve ( ) 
    {
    int i , j ;
    int res = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            if ( ( i + j ) % 2  == 0 ){
                ans[ i ][ j ] = 1 ;
                res ++ ;
                }
            }
        }
    printf ( "%d\n" , res ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            if ( ( i + j ) % 2  == 0 ){
                cout << "C" ;
                }
            else cout << "." ;
            }
        cout << "\n" ;
        }
    }