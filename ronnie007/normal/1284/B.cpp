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
int sz[ MAXN ] ;
vector < int > v[ MAXN ] ;

int sm[ MAXN ] ;
int lg[ MAXN ] ;

bool fl[ MAXN ] ;

long long ans = 0 ;
long long cnt = 0 ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &sz[ i ] ) ;
        v[ i ].resize ( sz[ i ] ) ;
        int mn = -1 ;
        int mx = -1 ;
        for ( int j = 0 ; j < sz[ i ] ; ++ j ) {
            scanf ( "%d" , &v[ i ][ j ] ) ;
            if ( mn != -1 && v[ i ][ j ] > mn ) {
                fl[ i ] = true ;
            }
            if ( mn == -1 ) { mn = v[ i ][ j ] ; }
            if ( mn > v[ i ][ j ] ) { mn = v[ i ][ j ] ; }
            if ( mx < v[ i ][ j ] ) { mx = v[ i ][ j ] ; }
        }
        sm[ i ] = mn , lg[ i ] = mx ;
        if ( fl[ i ] == true ) { ++ cnt ; }
    }
}

void solve ( ) {
    ans = cnt * 2 * n - cnt * cnt ;
    vector < pair < int , int > > srt ;
    srt.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fl[ i ] == true ) { continue ; }
        srt.push_back ( { sm[ i ] , -1 } ) ;
        srt.push_back ( { lg[ i ] , 1 } ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    int len = srt.size ( ) ;
    int pos = 0 ;
    int aux = 0 ;
    for ( int i = 0 ; i < len ; ++ i ) {
        while ( srt[ pos ].first < srt[ i ].first ) {
            if ( srt[ pos ].second == -1 ) { ++ aux ; }
            ++ pos ;
        }
        if ( srt[ i ].second == 1 ) { ans += aux ; }
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}