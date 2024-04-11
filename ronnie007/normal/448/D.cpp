#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std;

long long n , m , k ;

void input ( ) ;
void solve ( ) ;

long long f ( long long x ) {
    int i ;
    long long br = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( x / i <= m ) br += ( x / i ) ;
        else br += m ;

    }
    ///cout << "---" << x << " " << br << "\n" ;
    return br ;
}


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> n >> m >> k ;
    ///k -- ;
}


void solve ( )  {
    long long l = 1 ;
    long long r = n * m ;
    long long mid ;
    while ( r - l > 1 ) {
        mid = ( r + l ) / 2 ;
        if ( f ( mid ) >= k ) r = mid ;
        else l = mid ;
    }
    while ( f ( l ) < k ) l ++ ;
    cout << l << "\n" ;
}