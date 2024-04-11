#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;
long long a[ 300007 ] ;
long long ans ; 

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    cin >> n ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ; 
    }
}

void solve ( )  {
    int i ;
    long long cur = 0 ;
    ans = 0 ;
    sort ( a , a + n ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        cur += a[ i ] ; 
    }
    for ( i = 0 ; i < n ; i ++ ) {
        ans += cur ;
        cur -= a[ i ] ;
        if ( cur == 0 ) break ;
        ans += a[ i ] ;
    }
    cout << ans << "\n" ;
}