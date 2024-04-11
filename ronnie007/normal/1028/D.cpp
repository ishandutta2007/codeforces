#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 400007

#define MOD 1000000007

int n ;
set < int > buy , sell , unknown ;

char cm[ 15 ] ;

long long ans = 1 ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    int val ;
    buy.insert ( -MOD ) ;
    sell.insert ( MOD ) ;
    set < int > :: iterator it ;
    long long aux = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "\n%s %d" , &cm , &val ) ;
        if ( cm[ 0 ] == 'A' && cm[ 1 ] == 'D' ) {
            it = buy.end ( ) ;
            it -- ;
            if ( (*it) > val ) {
                buy.insert ( val ) ;
                continue ;
            }
            it = sell.begin ( ) ;
            if ( (*it) < val ) {
                sell.insert ( val ) ;
                continue ;
            }
            aux ++ ;
            unknown.insert ( val ) ;
        }
        else {
            it = buy.end ( ) ;
            it -- ;
            if ( (*it) > val ) { ans = 0 ; continue ; }
            else if ( (*it) == val ) {
                buy.erase ( it ) ;
                aux = 1 ;
                for ( it = unknown.begin ( ) ; it != unknown.end ( ) ; it ++ ) {
                    if ( (*it) < val ) { buy.insert ( (*it) ) ; }
                    else if ( (*it) > val ) { sell.insert ( (*it) ) ; }
                }
                unknown.clear ( ) ;
                continue ;
            }
            it = sell.begin ( ) ;
            if ( (*it) < val ) { ans = 0 ; continue ; }
            else if ( (*it) == val ) {
                sell.erase ( it ) ;
                aux = 1 ;
                for ( it = unknown.begin ( ) ; it != unknown.end ( ) ; it ++ ) {
                    if ( (*it) < val ) { buy.insert ( (*it) ) ; }
                    else if ( (*it) > val ) { sell.insert ( (*it) ) ; }
                }
                unknown.clear ( ) ;
                continue ;
            }
            if ( aux > 2 ) { aux = 2 ; }
            ans = ( ans * aux ) % MOD ;
            aux = 1 ;
            for ( it = unknown.begin ( ) ; it != unknown.end ( ) ; it ++ ) {
                if ( (*it) < val ) { buy.insert ( (*it) ) ; }
                else if ( (*it) > val ) { sell.insert ( (*it) ) ; }
            }
            unknown.clear ( ) ;
        }
    }
    ans = ( ans * aux ) % MOD ;
}

void solve ( ) {
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}