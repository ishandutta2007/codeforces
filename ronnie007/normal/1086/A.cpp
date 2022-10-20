#include<bits/stdc++.h>
using namespace std ;

int n = 3 ;
pair < int , int > a[ 5 ] ;
vector < pair < int , int > > v ;

void input ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    for ( int i = a[ 1 ].first ; i < a[ 2 ].first ; ++ i ) {
        v.push_back ( { i , a[ 1 ].second } ) ;
    }
    int st = min ( a[ 1 ].second , a[ 2 ].second ) ;
    st = min ( st , a[ 3 ].second ) ;

    int en = max ( a[ 1 ].second , a[ 2 ].second ) ;
    en = max ( en , a[ 3 ].second ) ;
    for ( int i = st ; i <= en ; ++ i ) {
        v.push_back ( { a[ 2 ].first , i } ) ;
    }
    for ( int i = a[ 2 ].first + 1 ; i <= a[ 3 ].first ; ++ i ) {
        v.push_back ( { i , a[ 3 ].second } ) ;
    }
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}