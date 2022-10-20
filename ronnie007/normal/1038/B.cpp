#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

long long n ;
long long sm ;

void input ( ) {
    cin >> n ;
    sm = ( n * ( n + 1 ) / 2 ) ;
}

void solve ( ) {
    long long i ;
    long long val = 1 ;
    for ( i = 2 ; i * i <= sm ; i ++ ) {
        if ( ( sm % i ) == 0 ) { val = i ; break ; }
    }
    if ( val == 1 ) { cout << "No\n" ; return ; }
    cout << "Yes\n" ;
    int br = ( n / val ) ;
    cout << br ;
    for ( i = val ; i <= n ; i += val ) {
        cout << " " << i ;
    }
    cout << "\n" ;
    cout << n - br ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( ( i % val ) != 0 ) {
            cout << " " << i ;
        }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}