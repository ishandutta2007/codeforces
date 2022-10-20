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

#define MAXN 200007

int n , p , k ;
int a[ MAXN ] ;
long long pref[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &p , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = pref[ i - 1 ] + a[ i ] ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i < k ; ++ i ) {
        long long st = pref[ i ] ;
        int cnt = i ;
        if ( st <= p ) {
            int pos = i + k ;
            while ( pos <= n && st + a[ pos ] <= p ) {
                cnt += k ;
                st += a[ pos ] ;
                pos += k ;
            }
            if ( ans < cnt ) { ans = cnt ; }
        }
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}