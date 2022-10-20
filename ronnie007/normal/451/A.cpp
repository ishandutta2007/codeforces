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

int n , m ;

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
    scanf ( "%d%d" , &n , &m ) ;
}

void solve ( ) {
    if ( ( min ( n , m ) ) % 2 == 0 ) printf ( "Malvika\n" ) ;
    else printf ( "Akshat\n" ) ;
}