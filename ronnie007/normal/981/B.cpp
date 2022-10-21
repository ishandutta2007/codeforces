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
vector < pair < int , int > > v ;

void input ( ) {
    int m ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        scanf ( "%d" , &m ) ;
        for ( int i = 1 , x , y ; i <= m ; ++ i ) {
            scanf ( "%d%d" , &x , &y ) ;
            v.push_back ( { x , y } ) ;
        }
    }
}

void solve ( ) {
    sort ( v.begin ( ) , v.end ( ) ) ;
    n = v.size ( ) ;
    int64_t ans = v[ n - 1 ].second ;
    for ( int i = n - 2 ; i >= 0 ; -- i ) {
        if ( v[ i ].first == v[ i + 1 ].first ) { continue ; }
        ans += v[ i ].second ;
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