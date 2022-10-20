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

#define MAXN 2507
#define PI 3.14159265358979323846264


int n ;
long long orix , oriy ;

struct pt {
    long long x , y ;
    long double ang ;
    bool operator < ( pt other ) const {
        return ( ang < other.ang ) ;
    }
};

pt a[ MAXN ] ;

pt b[ MAXN ] ;

long long ans = 0 ;
long long dp[ MAXN ][ 7 ] ;

long long pref[ 7 ] ;

long long det ( pt p1 , pt p2 , pt p3 ) {
    long long k = p1.x * p2.y ;
    k += p1.y * p3.x ;

    k -= p3.x * p2.y ;
    k -= p3.y * p1.x ;
    k -= p2.x * p1.y ;
    
    k += p2.x * p3.y ;
    if ( k > 0 ) { return 1 ; }
    if ( k == 0 ) { return 0 ; }
    return -1 ;
}

void calc ( ) {
    for ( int i = 2 ; i <= n ; ++ i ) {
        dp[ i ][ 1 ] = 1 ;
        dp[ i ][ 2 ] = dp[ i ][ 3 ] = dp[ i ][ 4 ] = 0 ;
    }
    pref[ 1 ] = pref[ 2 ] = pref[ 3 ] = pref[ 4 ] = 0 ;
    int l ;
    l = 2 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        while ( det ( b[ 1 ] , b[ l ] , b[ i ] ) < 0 ) {
            for ( int j = 1 ; j <= 4 ; ++ j ) {
                pref[ j ] -= dp[ l ][ j ] ;
            }
            ++ l ;
        }
        for ( int j = 2 ; j <= 4 ; ++ j ) {
            dp[ i ][ j ] = pref[ j - 1 ] ;
        }
        ans += dp[ i ][ 4 ] ;
        for ( int j = 1 ; j <= 4 ; ++ j ) {
            pref[ j ] += dp[ i ][ j ] ;
        }
    }
    
    long long cnt = 0 ;
    int pos = 2 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        //if ( pos <= i ) { pos = i + 1 ; cnt = 1 ; }
        while ( pos <= n && det ( b[ 1 ] , b[ i ] , b[ pos ] ) >= 0 ) {       
            ++ pos , ++ cnt ;
        }
        -- cnt ;
        ans -= ( cnt * ( cnt - 1 ) * ( cnt - 2 ) ) / 6 ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].x >> a[ i ].y ; 
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        orix = a[ i ].x ;
        oriy = a[ i ].y ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            b[ j ] = a[ j ] ;
        }
        swap ( b[ 1 ] , b[ i ] ) ;
        for ( int j = 2 ; j <= n ; ++ j ) {
            b[ j ].ang = atan2 ( b[ j ].y - a[ i ].y , b[ j ].x - a[ i ].x ) ;
        }
        sort ( b + 2 , b + n + 1 ) ;
        calc ( ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}