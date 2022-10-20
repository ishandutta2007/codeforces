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

int n ;
long long lim , t1 , t2 ;

int type[ MAXN ] ;
int val[ MAXN ] ;
vector < pair < int , int > > pts ;

long long cnt1 , cnt2 ;
long long sm1 , sm2 ;

int calc ( long long aux ) {
    long long h = ( sm1 - cnt1 ) * t1 + ( sm2 - cnt2 ) * t2 ;
    int ret = ( sm1 - cnt1 ) + ( sm2 - cnt2 ) ;
    if ( h > aux ) { return 0 ; }
    long long lft = ( aux - h ) ;
    long long coef = ( lft / t1 ) ;
    if ( coef > cnt1 ) { coef = cnt1 ; }
    ret += coef ;
    lft -= coef * t1 ;
    coef = ( lft / t2 ) ;
    if ( coef > cnt2 ) { coef = cnt2 ; }
    ret += coef ;
    return ret ;
}

void input ( ) {
    pts.clear ( ) ;
    cnt1 = cnt2 = sm1 = sm2 = 0 ;
    scanf ( "%d%I64d%I64d%I64d" , &n , &lim , &t1 , &t2 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &type[ i ] ) ;
        if ( type[ i ] == 0 ) { ++ sm1 ; }
        else { ++ sm2 ; }
    }
    bool fl = false ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &val[ i ] ) ;
        if ( val[ i ] == lim ) { fl = true ; }
        pts.push_back ( { val[ i ] , i } ) ;
        if ( val[ i ] > 0 ) {
            pts.push_back ( { val[ i ] - 1 , i } ) ;
        }
    }
    if ( fl == false ) { pts.push_back ( { lim , 0 } ) ; }
}

void solve ( ) {
    int ans = 0 ;
    sort ( pts.begin ( ) , pts.end ( ) ) ;
    for ( int i = pts.size ( ) - 1 ; i >= 0 ; -- i ) {
        if ( pts[ i ].second > 0 && val[ pts[ i ].second ] == pts[ i ].first + 1 ) {
            if ( type[ pts[ i ].second ] == 0 ) { ++ cnt1 ; }
            else { ++ cnt2 ; } 
        }
        int ret = calc ( pts[ i ].first ) ;
        ans = max ( ans , ret ) ;
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