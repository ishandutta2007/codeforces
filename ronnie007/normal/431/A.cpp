#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int a[ 7 ] ;
string b ;

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
    int i ;
    for ( i = 0 ; i < 4 ; i ++ ) cin >> a[ i ] ;
    cin >> b ;
}

void solve ( ) {
    int n = b.size ( ) ;
    int i ;
    int x ;
    int ans = 0 ;
    for ( i = 0 ; i  < n ; i ++ ) {
        x = ( b[ i ] - '1' ) ;
        ans += a[ x ] ;
    }
    cout << ans << "\n" ;
}