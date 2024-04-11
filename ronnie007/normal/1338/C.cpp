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

long long n ;
unsigned long long pw[ 67 ] ;


void input ( ) {
    cin >> n ;
}

void solve ( ) {
    long long tr_id = ( ( n + 2 ) / 3 ) - 1 ;
    long long lft = ( n % 3 ) ;
    long long len = 1 ;
    long long tot = 0 ;
    int cnt = 0 ;
    while ( len <= tr_id ) {
        tr_id -= len ;
        ++ cnt ;
        len *= 4 ;
    }
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= 63 ; ++ i ) {
        pw[ i ] = pw[ i - 1 ] * 2 ;
    }
    unsigned long long ans = 0 ;
    int pos = 0 ;
    while ( cnt > 0 ) {
        int rem = ( tr_id % 4 ) ;
        tr_id /= 4 ;
        -- cnt ;
        if ( rem == 1 ) {
            if ( lft == 1 ) {
                ans += pw[ pos ] ;
            }
            else if ( lft == 2 ) {
                ans += pw[ pos + 1 ] ;
            }
            else { ans += pw[ pos ] + pw[ pos + 1 ] ; }
        }
        else if ( rem == 2 ) {
            if ( lft == 1 ) {
                ans += pw[ pos + 1 ] ;
            }
            else if ( lft == 2 ) {
                ans += pw[ pos ] + pw[ pos + 1 ] ;
            }
            else {
                ans += pw[ pos ] ;
            }
        }
        else if ( rem == 3 ) {
            if ( lft == 1 ) {
                ans += pw[ pos ] + pw[ pos + 1 ] ;
            }
            else if ( lft == 2 ) {
                ans += pw[ pos ] ;
            }
            else { ans += pw[ pos + 1 ] ; }            
        }
        pos += 2 ;
    }
    if ( lft == 1 ) {
        ans += pw[ pos ] ;
    }
    else if ( lft == 2 ) {
        ans += pw[ pos + 1 ] ;
    }
    else { ans += pw[ pos ] + pw[ pos + 1 ] ; }
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