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
#include<random>
using namespace std ;

int n ;
long long l , r ;
long long st ;

void f ( int root , int lo , int hi ) {
    if ( st >= r ) { return ; }
    int cnt = ( hi - lo + 1 ) ;
    if ( st + 2 * cnt - 1 < l ) {
        st += 2 * cnt - 1 ;
        return ;
    }
    for ( int i = lo ; i <= hi ; ++ i ) {
        int aux = i ;
        ++ st ;
        if ( l <= st && st <= r ) { printf ( "%d " , aux ) ; }
        if ( i == hi ) { break ; }
        ++ st ;
        aux = root ;
        if ( l <= st && st <= r ) { printf ( "%d " , aux ) ; }
    }
}

void input ( ) {
    cin >> n >> l >> r ;
}

void solve ( ) {
    st = 1 ;
    if ( l == 1 ) { printf ( "1 " ) ; }
    f ( 1 , 2 , n ) ;
    for ( int i = 2 ; i < n ; ++ i ) {
        ++ st ;
        if ( l <= st && st <= r ) { printf ( "%d " , i ) ; }
        f ( i , i + 1 , n ) ;
    }
    if ( st < r ) {
        printf ( "1" ) ;
    }
    printf ( "\n" ) ;
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