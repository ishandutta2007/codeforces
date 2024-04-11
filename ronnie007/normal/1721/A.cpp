#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair < int , int > pii ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int cnt[ 30 ] ;

void solve ( ) {
    for ( int i = 0 ; i < 26 ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    string a , b ;
    cin >> a >> b ;
    a += b ;
    for ( int i = 0 ; i < 4 ; ++ i ) {
        ++ cnt[ ( a[ i ] - 'a' ) ] ;
    }
    sort ( cnt , cnt + 26 , greater < int > ( ) ) ;
    cout << ( cnt[ 1 ] > 0 ) + ( cnt[ 2 ] > 0 ) + ( cnt[ 3 ] > 0 ) << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}