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
pair < int , int > a[ 57 ] ;

long long dp[ 57 ][ 57 ][ 5007 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ].first ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ].second ) ;
    }
    sort ( a + 1 , a + n + 1 , greater < pair < int , int > > () ) ;
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= n ; ++ j ) {
            for ( int t = 0 ; t <= 5000 ; ++ t ) {
                dp[ i ][ j ][ t ] = -1 ;
            }
        }
    }
    dp[ 0 ][ 0 ][ 0 ] = 0 ;
    double ans = -1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ].first == a[ i + 1 ].first ) { continue ; }
        int aux = i + 1 ;
        vector < int > srt ;
        srt.clear ( ) ;
        while ( a[ aux ].first == a[ i + 1 ].first ) {
            srt.push_back ( a[ aux ].second ) ;
            ++ aux ;
        }
        -- aux ;
        int sz = srt.size ( ) ;
        for ( int j = 0 ; j <= i ; ++ j ) {
            for ( int t = 0 ; t <= 5000 ; ++ t ) {
                if ( dp[ i ][ j ][ t ] == -1 ) { continue ; }
                int sm = 0 ;
                for ( int z = 0 ; z <= sz ; ++ z ) {
                    if ( j < ( sz - z ) ) {
                        if ( z < sz ) { sm += srt[ z ] ; }
                        continue ;
                    }
                    if ( dp[ aux ][ j - ( sz - z ) + z ][ t + sm ] == -1 ) {
                        dp[ aux ][ j - ( sz - z ) + z ][ t + sm ] = dp[ i ][ j ][ t ] + z * a[ i + 1 ].first ;
                    }
                    dp[ aux ][ j - ( sz - z ) + z ][ t + sm ] = min ( dp[ aux ][ j - ( sz - z ) + z ][ t + sm ] , dp[ i ][ j ][ t ] + z * a[ i + 1 ].first ) ;
                    if ( z == sz ) { break ; }
                    sm += srt[ z ] ;
                }
            }
        }
    }
    for ( int j = 0 ; j <= n ; ++ j ) {
        for ( int t = 0 ; t <= 5000 ; ++ t ) {
            if ( dp[ n ][ j ][ t ] == -1 ) { continue ; }
            double aux = dp[ n ][ j ][ t ] ;
            aux /= t ;
            if ( ans < 0 ) { ans = aux ; }
            ans = min ( ans , aux ) ;
        }
    }
    ans *= 1000 ;
    long long aux = ceil ( ans ) ;
    cout << aux << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}