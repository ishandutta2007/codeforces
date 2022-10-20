#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std;


int a1 , a2 , a3 ;
int b1 , b2 , b3 ;
int n ;

void input ( ) ;
void solve ( ) ;




int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d%d" , &a1 , &a2 , &a3 ) ;
    scanf ( "%d%d%d" , &b1 , &b2 , &b3 ) ;
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int x = a1 + a2 + a3 ;
    int y = b1 + b2 + b3 ;
    if ( x % 5 != 0 ) n -- ;
    if ( y % 10 != 0 ) n -- ;
    n -= ( x / 5 ) ;
    n -= ( y / 10 ) ;
    if ( n >= 0 ) printf ( "YES\n" ) ;
    else printf ( "NO\n" ) ;
}