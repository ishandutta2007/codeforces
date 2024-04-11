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

#define MAXN 507

int n ;
pair < int , int > a[ MAXN ] ;

vector < pair < int , int > > v ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ].first ) ;
        a[ i ].second = i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int br = 0 ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ].first == 1 ) { br ++ ; }
    }
    int id = 1 ;
    while ( br > 2 ) {
        a[ n ].first -- ;
        if ( a[ n ].first < 0 ) { printf ( "NO\n" ) ; return ; }
        a[ id ].first -- ;
        if ( a[ id ].first < 0 ) { printf ( "NO\n" ) ; return ; }
        br -- ;
        v.push_back ( make_pair ( a[ id ].second , a[ n ].second ) ) ;
        id ++ ;
        sort ( a + 1 , a + n + 1 ) ;
    }
    int lst = id ;
    for ( i = n ; i > id ; i -- ) {
        a[ lst ].first -- ;
        if ( a[ lst ].first < 0 ) { printf ( "NO\n" ) ; return ; }
        a[ i ].first -- ;
        if ( a[ i ].first < 0 ) { printf ( "NO\n" ) ; return ; }
        v.push_back ( make_pair ( a[ lst ].second , a[ i ].second ) ) ;
        lst = i ;
    }
    printf ( "YES %d\n" , n - id ) ;
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}