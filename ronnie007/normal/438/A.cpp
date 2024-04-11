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

int n , m ;
int a[ 1007 ] ;
int ans = 0 ;


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
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    int x , y ;
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        ans += min ( a[ x ] , a[ y ] ) ;
    }
}

void solve ( ) {
    printf ( "%d\n" , ans ) ;
}