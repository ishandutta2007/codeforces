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
using ll = long long ;

int n , m ;
ll st[ MAXN ] ;
ll en[ MAXN ] ;

long long prior[ MAXN ] ;
pair < ll , int > r[ MAXN ] ;

long long a[ MAXN ] ;

int ans[ MAXN ] ;

priority_queue < pair < ll , int > > q ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d%I64d" , &st[ i ] , &en[ i ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        r[ i ] = { en[ i + 1 ] - st[ i ] , i } ;
        prior[ i ] = st[ i + 1 ] - en[ i ] ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    vector < pair < ll , int > > srt ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        srt.push_back ( { a[ i ] , i } ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        r[ i ].second += m ;
        srt.push_back ( r[ i ] ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    int cnt = 0 ;
    for ( int i = srt.size ( ) - 1 ; i >= 0 ; -- i ) {
        if ( srt[ i ].second > m ) {
            srt[ i ].second -= m ;
            q.push ( { prior[ srt[ i ].second ] , srt[ i ].second } ) ;
        }
        else {
            if ( q.empty ( ) == true ) { continue ; }
            pair < ll , int > ret = q.top ( ) ;
            q.pop ( ) ;
            if ( ret.first > srt[ i ].first ) {
                printf ( "No\n" ) ;
                return ;
            }
            else {
                ans[ ret.second ] = srt[ i ].second ;
                ++ cnt ;
            }
        }
    }
    if ( cnt < ( n - 1 ) ) {
        printf ( "No\n" ) ;
        return ;
    }
    printf ( "Yes\n" ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}