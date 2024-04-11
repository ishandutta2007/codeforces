#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;


#define MAXN 100007

int n ;
long long sl ;

long long u ;
long long tot ;

struct tuhla {
    long long br ;
    long long x , y ;
};

tuhla a[ MAXN ] ;

bool cmp ( tuhla p1 , tuhla p2 ) {
    return ( ( p1.x - p1.y ) > ( p2.x - p2.y ) ) ;
}



long long f ( long long h ) {
    long long lft = ( u - h ) * sl ;
    h *= sl ;
    int i ;
    long long ret = 0 ;
    long long ost = tot ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ].x <= a[ i ].y ) {
            h = max ( 0LL , ost - lft ) ;
        }
        long long coef = min ( a[ i ].br , h ) ;
        ret += coef * a[ i ].x ;
        ret += ( a[ i ].br - coef ) * a[ i ].y ;
        ost -= a[ i ].br ;
        h -= coef ;
    }
    return ret ;
}

void input ( ) {
    cin >> n >> sl ;
    int i ;
    tot = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ].br >> a[ i ].x >> a[ i ].y ;
        tot += a[ i ].br ;
    }
    sort ( a + 1 , a + n + 1 , cmp ) ;
    u = ( tot / sl ) ;
    if ( ( tot % sl ) != 0 ) { u ++ ; }
}

void solve ( ) {
    long long l , r ;
    l = 0 ;
    r = u ;
    long long mid1 , mid2 ;
    long long ans = 0 ;
    while ( r - l > 3 ) {
        mid1 = ( 2 * l + r ) / 3 ;
        mid2 = ( l + 2 * r ) / 3 ;
        long long h1 , h2 ;
        h1 = f ( mid1 ) ;
        h2 = f ( mid2 ) ;
        if ( h1 < h2 ) {
            l = mid1 ;
        }
        else {
            r = mid2 ;
        }
        if ( ans < h1 ) { ans = h1 ; }
        if ( ans < h2 ) { ans = h2 ; }
    }
    long long i ;
    for ( i = l ; i <= r ; i ++ ) {
        long long ret = f ( i ) ;
        if ( ans < ret ) { ans = ret ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}