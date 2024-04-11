#include<bits/stdc++.h>
using namespace std ;

long long n ;
vector < long long > v ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    v.clear ( ) ;
    long long g = 1 ;
    long long sm = 1 ;
    while ( 1 ) {
        if ( sm + g * 4 <= n ) {
            v.push_back ( g ) ;
            g *= 2 ;
            sm += g ;
        }
        else {
            if ( sm + 2 * g >= n ) {
                v.push_back ( n - sm - g ) ;
                sm = n ;
                break ;
            }
            long long diff = n - sm - g * 2 ;
            
            v.push_back ( ( diff / 2 ) ) ;
            g += ( diff / 2 ) ;
            sm += g ;
            if ( sm < n ) {
                v.push_back ( n - sm - g ) ;
                sm += n - sm ;
            }
            break ;
        }
    }
    int sz = v.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << v[ i ] << " " ;
    }
    cout << "\n" ;
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