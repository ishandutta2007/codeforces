#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main() {
    long long n , k , l , m , r , o ; 
    cin >> n >> k ;
    if ( k * ( k + 1 ) / 2 - k + 1 < n ) {
        cout << -1 << endl ;
        return 0 ;
    }
    l = 2 ;
    r = k ;
    o = k - 1 ;
    while ( l <= r ) {
        m = ( r + l ) / 2 ;
        if ( ( k * ( k + 1 ) / 2 - k + 1 ) - ( m * ( m + 1 ) / 2 - m ) >= n ) {
            o = k - m ; 
            l = m + 1 ;
        }
        else r = m - 1 ; 
    }
    cout << o << endl ;
}