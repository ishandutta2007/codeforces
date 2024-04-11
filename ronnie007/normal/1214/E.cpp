#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

pair < int , int > srt[ MAXN ] ;

vector < pair < int , int > > ans ;


int lvl[ 5 * MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        srt[ i ] = { a[ i ] , 2 * i } ;
    }
    sort ( srt + 1 , srt + n + 1 ) ;
}

void solve ( ) {
    for ( int i = 2 ; i <= n ; ++ i ) {
        ans.push_back ( { srt[ i - 1 ].second , srt[ i ].second } ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        lvl[ n - i + 1 ] = srt[ i ].second ;
    }
    int mx = n ;
    for ( int i = n ; i >= 1 ; -- i ) {
        int cur = ( n - i + 1 ) ;
        cur += srt[ i ].first - 1 ;
        ans.push_back ( { lvl[ cur ] , srt[ i ].second - 1 } ) ;
        if ( cur == mx ) {
            lvl[ cur + 1 ] = srt[ i ].second - 1 ;
            ++ mx ;
        }
    }
    int sz = ans.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d\n" , ans[ i ].first , ans[ i ].second ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}