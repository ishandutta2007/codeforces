#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;

int n ;
string a ;

map < int , int > wh ;
stack < int > s ;

void solve ( ) {
    cin >> n ;
    cin >> a ;
    wh.clear ( ) ;
    while ( s.empty ( ) == false ) { s.pop ( ) ; }
    s.push ( -1 ) ;
    int x = 0 , ans = 0 ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        if ( a[ i - 1 ] == '(' ) {
            if ( s.top ( ) > wh[ x ] ) {
                ++ ans ;
            }

            wh[ x ] = i - 1 ;
            ++ x ;
            s.push ( i ) ;
        }
        else {
            wh[ x ] = i - 1 ;
            -- x ;
            s.pop ( ) ;
            
            if ( s.top ( ) > wh[ x ] ) {
                ++ ans ;
            }
        }
    }
    cout << ans + 1 << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}