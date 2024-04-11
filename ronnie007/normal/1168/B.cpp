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


int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = i + 2 ; j < n ; ++ j ) {
            int t = 1 ;
            for ( t = 1 ; j - 2 * t >= i ; ++ t ) {
                if ( a[ j ] == a[ j - t ] && a[ j ] == a[ j - 2 * t ] ) {
                    break ;
                }
            }
            if ( j - 2 * t >= i ) {
                ans += ( n - j ) ;
                break ; 
            }
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}