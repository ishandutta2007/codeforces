#include<bits/stdc++.h>
using namespace std ;

int n , m ;
vector < int > srt ;

void input ( ) {
    cin >> n >> m ;
}

void solve ( ) {
    srt.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            srt.push_back ( max ( i - 1 , n - i ) + max ( j - 1 , m - j ) ) ;
        }
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    for ( int i = 0 ; i < n * m ; ++ i ) {
        cout << srt[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}