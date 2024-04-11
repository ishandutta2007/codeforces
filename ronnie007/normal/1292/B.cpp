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


long long mx_coord ;
int n ;

pair < long long , long long > st ;
long long t ;

pair < long long , long long > a[ 107 ] ;

long long dist ( pair < long long , long long > p1 , pair < long long , long long > p2 ) {
    long long ret = 0 ;
    if ( p1.first < p2.first ) { ret += p2.first - p1.first ; }
    else { ret += p1.first - p2.first ; }

    if ( p1.second < p2.second ) { ret += p2.second - p1.second ; }
    else { ret += p1.second - p2.second ; }
    
    return ret ;
}

void input ( ) {
    cin >> a[ 0 ].first >> a[ 0 ].second ;
    long long coef1 , coef2 ;
    long long add1 , add2 ;
    cin >> coef1 >> coef2 ;
    cin >> add1 >> add2 ;
    for ( int i = 1 ; i <= 70 ; ++ i ) {
        n = i - 1 ;
        a[ i ].first = ( coef1 * a[ i - 1 ].first ) + add1 ;
        a[ i ].second = ( coef2 * a[ i - 1 ].second ) + add2 ;
        if ( a[ i ].first > mx_coord || a[ i ].second > mx_coord ) { break ; }
    }
    ++ n ;
    cin >> st.first >> st.second >> t ;
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int step = -1 ; step <= 1 ; step += 2 ) {
            long long aux = dist ( st , a[ i ] ) ;
            if ( aux > t ) { continue ; }
            int h = 1 ;
            for ( int j = i + step ; j < n && j >= 0 ; j += step ) {
                aux += dist ( a[ j - step ] , a[ j ] ) ;
                if ( aux <= t ) { ++ h ; }
                else { break ; }
            }
            if ( ans < h ) { ans = h ; }
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    mx_coord = 2 ;
    for ( int i = 1 ; i <= 16 ; ++ i ) { mx_coord *= 10 ; }
    ++ mx_coord ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}