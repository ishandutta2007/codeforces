#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



vector < int > ans ;

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
    int n , p ;
    int i , j ;
    int sz , x ;
    int fl  = 0 ;
    scanf ( "%d%d" , &n , &p ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &sz ) ;
        fl = 0 ;
        while ( sz != 0 ) {
            scanf ( "%d" , &x ) ;
            sz -- ;
            if ( x < p && fl == 0 ) {
                ans.push_back ( i + 1 ) ;
                fl = 1 ;
            }
        }
    }
}

void solve ( ) {
    int i ;
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d " , ans[ i ] ) ;
    }
}