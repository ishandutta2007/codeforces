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
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int i ;
    int cur = 0 ;
    int ans = 10 * n ;
    int id = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int cur = i + ( n / i ) ;
        if ( ( n % i ) != 0 ) { cur ++ ; }
        if ( ans > cur ) { ans = cur ; id = i ; }
    }
    int pos = n ;
    int val = n ;
    int tot = ( n / id ) ;
    while ( tot > 0 ) {
        tot -- ;
        for ( i = pos - id + 1 ; i <= pos ; i ++ ) {
            a[ i ] = val ;
            val -- ;
        }
        pos -= id ;
    }
    for ( i = 1 ; i <= val ; i ++ ) {
        a[ i ] = ( val - i + 1 ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d " , a[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}