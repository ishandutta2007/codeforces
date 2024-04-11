#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n ;
int br ;
string a ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int i ;
    int j ;
    int t ;
    int x ;
    vector < int > ans ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a ;
        ans.clear ( ) ;
        for ( t = 1 ; t <= 12 ; t ++ ) {
            br = 0 ;
            if ( 12 % t != 0 ) continue ;
            for ( j = 0 ; j < t ; j ++ ) {
                x = j ;
                while ( x < 12 && a[ x ] == 'X' ) {
                    x += t ;
                }
                if ( x >= 12 ) { ans.push_back ( t ) ; break ; }
            }

        }
        printf ( "%d " , ans.size ( ) ) ;
        for ( j = ans.size ( ) - 1  ; j >= 0   ; j -- ) {
            printf ( "%dx%d " , 12 / ans[ j ] , ans[ j ] ) ;
        }
        printf ( "\n" ) ;
    }
}