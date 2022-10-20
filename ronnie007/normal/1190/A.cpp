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

long long lim ;
long long n , k ;

long long a[ MAXN ] ;

void input ( ) {
    cin >> lim >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        -- a[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long id = ( a[ i ] - cnt ) / k ;
        ++ ans ;
        int add = 1 ;
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            long long sr = ( a[ j ] - cnt ) / k ;
            if ( sr == id ) { ++ i ; ++ add ; }
            else { break ; }
        }
        cnt += add ;
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