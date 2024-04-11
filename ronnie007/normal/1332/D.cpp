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
#include<random>
using namespace std ;

int k ;

void input ( ) {
    scanf ( "%d" , &k ) ;
}

void solve ( ) {
    int aux = 1 ;
    while ( aux <= k ) { aux *= 2 ; }
    int mx = 2 * aux - 1 ;
    printf ( "3 3\n" ) ;
    printf ( "%d %d 0\n" , mx , k ) ;
    printf ( "%d %d %d\n" , aux , mx , mx ) ;
    printf ( "0 %d %d\n" , mx , k ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}