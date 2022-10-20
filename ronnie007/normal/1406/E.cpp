#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 1e5 + 7 ;
const int MAGIC = 100 ;


int n ;
bool fl[ MAXN ] ;
vector < int > v ;

vector < int > divs ;

void solve ( ) {
    cin >> n ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( fl[ i ] == true ) { continue ; }
        v.push_back ( i ) ;
        for ( int j = 2 * i ; j <= n ; j += i ) {
            fl[ j ] = true ;
        }
    }
    int cons = 0 ;
    int exp = n ;
    int ans = 1 ;
    int sz = v.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << "B " << v[ i ] << "\n" ;
        fflush ( stdout ) ;
        int ret ; cin >> ret ;
        exp -= ret ;
        ++ cons ;
        
        if ( cons == MAGIC || i == sz - 1 ) {
            cout << "A 1\n" ;
            fflush ( stdout ) ;
            int tot ; cin >> tot ;
            if ( exp != tot ) {
                for ( int j = 0 ; j < cons ; ++ j ) {
                    if ( i - j < 0 ) { break ; }
                    cout << "A " << v[ i - j ] << "\n" ;
                    fflush ( stdout ) ;
                    int val ; cin >> val ;
                    if ( val > 0 ) { divs.push_back ( v[ i - j ] ) ; }
                }
            }
            exp = tot ;
            cons = 0 ;
        }
    }
    for ( auto x : divs ) {
        ans *= x ;
        for ( ll i = 1LL * x * x ; i <= n ; i *= x ) {
            cout << "A " << i << "\n" ;
            fflush ( stdout ) ;
            int ret ; cin >> ret ;
            if ( ret == 1 ) { ans *= x ; }
        }
    }
    cout << "C " << ans << "\n" ;
    fflush ( stdout ) ;
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}