#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std;

int n ;
string a ;

int br[ 2 ][ 2 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}


void solve ( )  {
    long long ans1 , ans2 ;
    ans1 = 0 ;
    ans2 = 0 ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        br[ ( a[ i ] - 'a' ) ][ i % 2 ] ++ ;
        ans1 += br[ ( a[ i ] - 'a' ) ][ ( (i % 2) ^ 1 ) ] ;
        ans2 += br[ ( a[ i ] - 'a' ) ][ i % 2 ] ;
    }
    cout << ans1 << " " << ans2 << "\n" ;
}