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
using namespace std ;

#define MAXN 100007

int n ;
long long a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ; 
    }
}

void solve ( ) {
    long long mxval = 0 ;
    long long lst = a[ 1 ] ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] >= lst ) {
            lst = a[ i ] ;
        }
        else {
            mxval = max ( mxval , lst - a[ i ] ) ;
        }
    }
    int ans = 0 ;
    while ( mxval > 0 ) {
        mxval /= 2 ;
        ++ ans ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}