#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

#define MAXN 600007

int n , k ;
string a , b ;



void input ( ) {
    cin >> n >> k ;
    cin >> a >> b ;
}

void solve ( ) {
    int i ;
    long long x , y ;
    x = y = 1 ;
    long long ans = 0 ;
    long long lst = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        x = ( a[ i ] == 'b' ) ? ( 2 * x + 1 ) : ( 2 * x ) ;
        y = ( b[ i ] == 'b' ) ? ( 2 * y + 1 ) : ( 2 * y ) ;
        long long aux = min ( ( y - x + 1 ) - lst , 1LL * k ) ;
        ans += aux * ( n - i ) ;
        lst = ( y - x + 1 ) ;
        k -= aux ;
        if ( k <= 0 ) { break ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}