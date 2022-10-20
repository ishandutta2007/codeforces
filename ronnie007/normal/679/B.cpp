#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

typedef long long type ;
typedef pair < type , type > tuhla ;
type n ;

type get_cube ( type x ) {
    type ret = 0 ;
    while ( ret * ret * ret <= x ) { ret ++ ; }
    ret -- ;
    return ret ;
}

tuhla f ( type n ) {
    if ( n == 0 ) { return make_pair ( 0 , 0 ) ; }
    type x = get_cube ( n ) ;
    tuhla p1 , p2 ;
    p1 = f ( n - x * x * x ) ;
    if ( x <= 1 ) {
        p2 = make_pair ( -7 , -7 ) ;
    }
    else {
        p2 = f ( x * x * x - 1 - ( x - 1 ) * ( x - 1 ) * ( x - 1 ) ) ;
    }
    if ( p1.first >= p2.first ) {
        p1.first ++ ;
        p1.second += x * x * x ;
        return p1 ;
    }
    p2.first ++ ;
    p2.second += ( x - 1 ) * ( x - 1 ) * ( x - 1 ) ;
    return p2 ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    tuhla ret = f ( n ) ;
    cout << ret.first << " " << ret.second << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}