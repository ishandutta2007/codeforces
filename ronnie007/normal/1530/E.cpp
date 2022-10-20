#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
string a ;

int cnt[ 32 ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        ++ cnt[ ( a[ i ] - 'a' ) ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( cnt[ i ] == n ) {
            cout << a << "\n" ;
            return ;
        }
    }

    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( cnt[ i ] == 1 ) {
            cout << char ( 'a' + i ) ;
            for ( int j = 0 ; j < 26 ; ++ j ) {
                if ( i == j ) { continue ; }
                while ( cnt[ j ] > 0 ) {
                    -- cnt[ j ] ;
                    cout << char ( 'a' + j ) ;
                }
            }
            cout << "\n" ;
            return ;
        }
    }
    
    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( cnt[ i ] > 0 ) {
            if ( cnt[ i ] - 2 <= n - cnt[ i ] ) {
                -- cnt[ i ] ;
                cout << char ( 'a' + i ) ;
                int sz = 1 ;
                while ( sz < n ) {
                    if ( cnt[ i ] > 0 ) {
                        cout << char ( 'a' + i ) ;
                        -- cnt[ i ] ;
                        ++ sz ;
                    }
                    for ( int j = 0 ; j < 26 ; ++ j ) {
                        if ( i == j ) { continue ; }
                        if ( cnt[ j ] > 0 ) {
                            -- cnt[ j ] ;
                            ++ sz ;
                            cout << char ( 'a' + j ) ;
                            break ;
                        }
                    }
                }
                cout << "\n" ;
                return ;
            }
            else { break ; }
        }
    }
    int big , scd ;
    big = scd = -1 ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( cnt[ i ] > 0 ) {
            if ( big == -1 ) { big = i ; }
            else if ( scd == -1 ) { scd = i ; }
            else { break ; }
        }
    }
    cout << char ( 'a' + big ) ;
    -- cnt[ big ] ;
    int other = n - 1 - cnt[ big ] - cnt[ scd ] ;
    if ( other == 0 ) { 
        while ( cnt[ scd ] > 0 ) {
            -- cnt[ scd ] ;
            cout << char ( 'a' + scd ) ;
        }
        for ( int i = 0 ; i < 26 ; ++ i ) {
            while ( cnt[ i ] > 0 ) {
                -- cnt[ i ] ;
                cout << char ( 'a' + i ) ;
            }
        }
    }
    else {
        cout << char ( 'a' + scd ) ;
        -- cnt[ scd ] ;

        while ( cnt[ big ] > 0 ) {
            -- cnt[ big ] ;
            cout << char ( 'a' + big ) ;
        }

        for ( int i = scd + 1 ; i < 26 ; ++ i ) {
            if ( cnt[ i ] > 0 ) {
                -- cnt[ i ] ;
                cout << char ( 'a' + i ) ;
                break ; 
            }
        }
        for ( int i = 0 ; i < 26 ; ++ i ) {
            while ( cnt[ i ] > 0 ) {
                -- cnt[ i ] ;
                cout << char ( 'a' + i ) ;
            }
        }        
    }
    cout << "\n" ;
}

int main ( ) {
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