#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
string diff ;

string ans1 , ans2 ;

void input ( ) {
    cin >> n >> diff ;
}

void solve ( ) {
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( diff[ i ] == '0' ) { ++ cnt ; }
    }
    if ( ( cnt % 2 ) != 0 ) {
        cout << "NO\n" ;
        return ;
    }
    if ( diff[ 0 ] == '0' || diff[ n - 1 ] == '0' ) {
        cout << "NO\n" ;
        return ;
    }
    ans1.clear ( ) ; ans2.clear ( ) ;
    int lft = ( n - cnt ) / 2 ;
    int alt = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( diff[ i ] == '1' ) {
            if ( lft > 0 ) {
                ans1 += '(' ;
                ans2 += '(' ;
            }
            else {
                ans1 += ')' ;
                ans2 += ')' ;
            }
            -- lft ;
        }
        else {
            if ( alt == 0 ) {
                ans1 += '(' ;
                ans2 += ')' ;
            }
            else {
                ans1 += ')' ;
                ans2 += '(' ;
            }
            alt ^= 1 ;
        }
    }
    int sm1 = 0 ;
    int sm2 = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( ans1[ i ] == '(' ) { ++ sm1 ; }
        else { -- sm1 ; }

        if ( ans2[ i ] == '(' ) { ++ sm2 ; }
        else { -- sm2 ; }

        if ( sm1 < 0 || sm2 < 0 ) {
            cout << "NO\n" ;
            return ;
        }
    }
    if ( sm1 != 0 || sm2 != 0 ) {
        cout << "NO\n" ;
        return ;
    }
    cout << "YES\n" ;
    cout << ans1 << "\n" ;
    cout << ans2 << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}