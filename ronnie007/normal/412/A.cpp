#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n , k ;
string a ;


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
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    int d1 , d2 ;
    int i ;
    int dir = 0 ;
    int x ;
    d1 = k - 1 ;
    d2 = n - k ;
    if ( d1 > d2 ) {
        for ( i = 0 ; i < d2 ; i ++ ) {
            printf ( "RIGHT\n" ) ;
        }
        printf ( "PRINT " ) ;
        cout << a[ n - 1 ] << "\n" ;

        for ( i = n - 2 ; i >= 0 ; i -- ) {
            printf ( "LEFT\n" ) ;
            printf ( "PRINT " ) ;
            cout << a[ i ] << "\n" ;
        }
    }
    else {
        for ( i = 0 ; i < d1 ; i ++ ) {
            printf ( "LEFT\n" ) ;
        }
        printf ( "PRINT " ) ;
        cout << a[ 0 ] << "\n" ;

        for ( i = 1 ; i < n  ; i ++ ) {
            printf ( "RIGHT\n" ) ;
            printf ( "PRINT " ) ;
            cout << a[ i ] << "\n" ;
        }
    }
}