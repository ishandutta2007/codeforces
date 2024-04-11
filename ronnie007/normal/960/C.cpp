#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

long long tot , diff ;

vector < long long > v ;

void input ( ) {
    cin >> tot >> diff ;
}

void solve ( ) {
    long long cur = 1 ;
    int i , j ;
    for ( i = 30 ; i >= 0 ; i -- ) {
        int aux = (1<<i) ;
        if ( tot >= aux ) {
            tot -= aux ;
            for ( j = 1 ; j <= i ; j ++ ) {
                v.push_back ( cur ) ;
            }
            cur += diff + 2 ;
            v.push_back ( cur ) ;
            cur += diff + 2 ;
        }
    }
    int n = v.size ( ) ;
    cout << n << "\n" ;
    for ( i = 0 ; i < n ; i ++ ) {
        cout << v[ i ] ;
        if ( i == ( n - 1 ) ) { cout << "\n" ; }
        else { cout << " " ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}