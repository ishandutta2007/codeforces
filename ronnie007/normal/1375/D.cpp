#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
int a[ MAXN ] ;
int cnt[ MAXN ] ;

vector < int > ans ;

int mex ( ) {
    for ( int i = 0 ; i <= n + 1 ; ++ i ) {
        if ( cnt[ i ] == 0 ) { return i ; }
    }
}

bool done ( ) {
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] < a[ i - 1 ] ) { return false ; }
    }
    return true ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i <= n + 2 ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt[ a[ i ] ] ;
    }
}

void solve ( ) {
    ans.clear ( ) ;
    while ( done ( ) == false ) {
        int ret = mex ( ) ;
        if ( ret < n ) {
            -- cnt[ a[ ret + 1 ] ] ;
            ++ cnt[ ret ] ;
            a[ ret + 1 ] = ret ;
            ans.push_back ( ret + 1 ) ;
        }
        else {
            for ( int i = 1 ; i <= n ; ++ i ) {
                if ( a[ i ] != i - 1 ) {
                    -- cnt[ a[ i ] ] ;
                    ++ cnt[ ret ] ;
                    a[ i ] = ret ;
                    ans.push_back ( i ) ;
                    break ;
                }
            }
        }
    }
    int sz = ans.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << ans[ i ] << " " ;
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