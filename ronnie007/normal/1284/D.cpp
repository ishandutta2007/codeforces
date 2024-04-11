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
#define inf 1000000007


int n ;
pair < int , int > a[ MAXN ] ;
pair < int , int > b[ MAXN ] ;

class Tree {
public :
    pair < int , int > tr[ 10 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = { inf , -1 } ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val1 , int val2 ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = { val1 , val2 } ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val1 , val2 ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val1 , val2 ) ;
        }
        tr[ where ].first = min ( tr[ 2 * where ].first , tr[ 2 * where + 1 ].first ) ;
        tr[ where ].second = max ( tr[ 2 * where ].second , tr[ 2 * where + 1 ].second ) ;
    }
};

Tree w ;

bool calc ( ) {
    w.init ( 1 , 1 , n ) ;
    
    vector < pair < pair < int , int > , int > > srt ;
    srt.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        srt.push_back ( { { a[ i ].first , -1 } , i } ) ;
        srt.push_back ( { { a[ i ].second , 1 } , i } ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    int len = srt.size ( ) ;
    for ( int i = 0 ; i < len ; ++ i ) {
        if ( srt[ i ].first.second == -1 ) {
            int id = srt[ i ].second ;
            w.update ( 1 , 1 , n , id , b[ id ].second , b[ id ].first ) ;
        }
        else {
            int id = srt[ i ].second ;
            w.update ( 1 , 1 , n , id , inf , -1 ) ;
            pair < int , int > ret = w.tr[ 1 ] ;
            if ( ret.first < b[ id ].first ) { return true ; }
            if ( b[ id ].second < ret.second ) { return true ; }
        }
    }
    return false ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d%d%d" , &a[ i ].first , &a[ i ].second , &b[ i ].first , &b[ i ].second ) ;
    }
}

void solve ( ) {
    if ( calc ( ) == true ) { printf ( "NO\n" ) ; return ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        swap ( a[ i ] , b[ i ] ) ;
    }
    if ( calc ( ) == true ) { printf ( "NO\n" ) ; return ; }
    printf ( "YES\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}