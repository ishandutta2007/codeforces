#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 1024 ;

int n , k ;
bool bad[ MAXN ] ;

bool ask ( int x ) {
    cout << "? " << x + 1 << "\n" ;
    fflush ( stdout ) ;
    char ret ;
    cin >> ret ;
    if ( ret == 'Y' ) { return true ; }
    return false ;
}

void solve ( ) {
    cin >> n >> k ;
    int sz = ( k / 2 ) ;
    if ( sz == 0 ) { sz = 1 ; }
    
    int cnt = ( n / sz ) ;
    for ( int i = 0 ; i < ( cnt + 1 ) / 2 ; ++ i ) {
        int mv = 1 ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int wh = i * sz + j ;
            if ( bad[ wh ] == true ) { continue ; }
            if ( ask ( wh ) == true ) { bad[ wh ] = true ; }
        }
        for ( int st = 0 ; st < cnt - 1 ; ++ st ) {
            int id = ( i + mv + cnt ) % cnt ;
            for ( int j = 0 ; j < sz ; ++ j ) {
                int wh = id * sz + j ;
                if ( bad[ wh ] == true ) { continue ; }
                if ( ask ( wh ) == true ) { bad[ wh ] = true ; }
            }
            mv = -mv ;
            if ( mv > 0 ) { ++ mv ; }
        }
        cout << "R\n" ;
        fflush ( stdout ) ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( bad[ i ] == false ) { ++ ans ; }
    }
    cout << "! " << ans << "\n" ;
    fflush ( stdout ) ;
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}