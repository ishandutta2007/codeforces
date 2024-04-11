#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


int n , c1 , c2 , c3 ;
string a ;

long long ans ;


void input ( ) {
    cin >> n >> c1 >> c2 >> c3 ;
    cin >> a ;
}

void solve ( ) {
    bool fl = false ;
    int cnt = 0 ;
    vector < int > v ;
    vector < int > init ;
    int hh = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == '0' ) { ++ cnt ; }
        else {
            if ( fl == true && cnt > 0 ) {
                v.push_back ( cnt ) ;
                init.push_back ( cnt ) ;
            }
            cnt = 0 , fl = true ;
        }
        if ( i > 0 && a[ i ] == '1' && a[ i - 1 ] == '1' ) { ++ hh ; }
    }
    int useful = 0 ;
    int useless = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == '1' ) { break ; }
        if ( i == 0 ) { ++ useless ; }
        else { ++ useful ; }
    }
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        if ( a[ i ] == '1' ) { break ; }
        if ( i == n - 1 ) { ++ useless ; }
        else { ++ useful ; }
    }
    
    int sz = v.size ( ) ;
    sort ( v.begin ( ) , v.end ( ) ) ;
    sort ( init.begin ( ) , init.end ( ) ) ;
    ans = 0 ;
    for ( int type = 0 ; type < 2 ; ++ type ) {
        long long aux = 0 ;
        int l , r ;
        l = r = 0 ;
        while ( r < sz && v[ r ] == 1 ) { ++ r ; } 
        int lft = hh ;
        int lft_useful = useful ;
        int lft_useless = useless ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ( i % 2 ) == type ) {
                if ( lft > 0 ) {
                    if ( r < sz && v[ r ] > 1 ) {
                        -- v[ r ] ;
                        aux += c1 ;
                        ans = max ( ans , aux ) ;

                        if ( v[ r ] == 1 ) { ++ r ; }
                    }
                    else if ( lft_useful > 0 ) {
                        aux += c1 ;
                        -- lft_useful ;
                        ans = max ( ans , aux ) ;
                    }
                    else if ( l < r ) {
                        ++ l ;
                        aux -= c3 ;
                        ans = max ( ans , aux ) ;
                        ++ lft ;
                    }
                    else if ( lft_useless > 0 ) {
                        aux -= c3 ;
                        ans = max ( ans , aux ) ;
                        -- lft_useless ;
                    }
                    else { break ; }
                }
                else {
                    if ( r < sz && v[ r ] > 1 ) {
                        ans = max ( ans , aux + c1 ) ;
                    }
                    if ( lft_useful > 0 ) {
                        ans = max ( ans , aux + c1 ) ;
                    }
                    if ( l < r ) {
                        ++ l ;
                        aux -= c3 ;
                        ans = max ( ans , aux ) ;

                        ++ lft ;
                    }
                    else { break ; }
                }
            }
            else {
                if ( lft > 0 ) {
                    -- lft ;
                    aux += c2 ;
                    ans = max ( ans , aux ) ;
                }
                else { break ; }
            }
        }

        v.clear ( ) ;
        for ( auto x : init ) { v.push_back ( x ) ; }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}