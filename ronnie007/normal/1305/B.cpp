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

#define MAXN 1007

int n ;
string a ;


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    vector < int > v ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int x , y ;
        x = y = 0 ;
        for ( int j = 0 ; j <= i ; ++ j ) {
            x += ( a[ j ] == '(' ) ;
        }
        for ( int j = i + 1 ; j < n ; ++ j ) {
            y += ( a[ j ] == ')' ) ;
        }
        if ( x == y && x > 0 ) {
            printf ( "1\n%d\n" , 2 * x ) ;
            for ( int j = 0 ; j < n ; ++ j ) {
                if ( j <= i && a[ j ] == '(' ) { printf ( "%d " , j + 1 ) ; }
                if ( j > i && a[ j ] == ')' ) { printf ( "%d " , j + 1 ) ; }
            }
            printf ( "\n" ) ;
            return ;
        }
    }
    printf ( "0\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}