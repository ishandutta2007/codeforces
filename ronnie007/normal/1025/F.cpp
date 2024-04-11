#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std ;

#define MAXN 2007

struct tuhla {
    int x , y ;
    tuhla ( ) { x = y = 0 ; }
    tuhla ( int _x , int _y ) {
        x = _x ;
        y = _y ;
    }
    tuhla operator - ( const tuhla &other ) const {
        return tuhla ( x - other.x , y - other.y ) ;
    }
};


long long det ( tuhla p1 , tuhla p2 , tuhla p3 ) {
    long long ret = 1LL * p1.x * p2.y + 1LL * p1.y * p3.x + 1LL * p2.x * p3.y ;
    ret -= 1LL * p3.x * p2.y + 1LL * p3.y * p1.x + 1LL * p2.x * p1.y ;
    return ret ;
}

bool cmp ( tuhla p1 , tuhla p2 ) {
    return ( det ( p1 , tuhla ( 0 , 0 ) , p2 ) <= 0 ) ;
}

int n ;
tuhla a[ MAXN ] ;

vector < tuhla > v ;
long long ans = 0 ;

void autistic_sort ( ) {
    vector < tuhla > w1 , w2 ;
    int i ;
    for ( i = 0 ; i < ( n - 1 ) ; i ++ ) {
        if ( v[ i ].y < 0 || ( v[ i ].y == 0 && v[ i ].x < 0 ) ) {
            w1.push_back ( v[ i ] ) ;
        }
        else { w2.push_back ( v[ i ] ) ; }
    }
    sort ( w1.begin ( ) , w1.end ( ) , cmp ) ;
    sort ( w2.begin ( ) , w2.end ( ) , cmp ) ;
    v.clear ( ) ;
    int sz1 = w1.size ( ) ;
    int sz2 = w2.size ( ) ;
    for ( i = 0 ; i < sz1 ; i ++ ) {
        v.push_back ( w1[ i ] ) ;
    }
    for ( i = 0 ; i < sz2 ; i ++ ) {
        v.push_back ( w2[ i ] ) ;
    }
}

void calc ( ) {
    int i ;
    for ( i = 0 ; i < ( n - 1 ) ; i ++ ) {
        v.push_back ( v[ i ] ) ;
    }
    int pos = -1 ;
    int val = 0 ;
    int sz = v.size ( ) ;
    for ( i = 0 ; i < n - 1 ; i ++ ) {
        while ( pos + 1 < i + n - 1 && det ( v[ i ] , tuhla ( 0 , 0 ) , v[ pos + 1 ] ) <= 0 ) {
            pos ++ ;
            val ++ ;
        }
        val -- ;
        long long aux1 = ( 1LL * val * ( val - 1 ) ) / 2 ;
        long long aux2 = ( 1LL * ( n - val - 2 ) * ( n - val - 3 ) ) / 2 ;
        aux1 *= aux2 ;
        ans += aux1 ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        v.clear ( ) ;
        for ( j = 1 ; j <= n ; j ++ ) {
            if ( i == j ) { continue ; }
            v.push_back ( a[ j ] - a[ i ] ) ;
        }
        autistic_sort ( ) ;
        calc ( ) ;
    }
    printf ( "%I64d\n" , ( ans / 2 ) ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}