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
string a ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    cin >> a ;
    n = a.size ( ) ; 
}

void solve ( )  {
    int ans = 0 ; 
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = i ; j < n - 3 ; j ++ ) {
            if ( a[ j ] == 'b' && a[ j + 1 ] == 'e' && a[ j + 2 ] == 'a' && a[ j + 3 ] == 'r' ) {
                break ;
            }
        }
        j += 3 ;
        if ( n - j > 0 ) ans += ( n - j ) ;
    }
    printf ( "%d\n" , ans ) ;
}