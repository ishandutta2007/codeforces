#include<bits/stdc++.h>
using namespace std ;

int n , k ;
string a ;

int cnt[ 37 ] ;

void get_kth ( ) {
    int tot = 0 ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        tot += cnt[ i ] ;
        if ( tot >= k ) {
            cout << char ( i + 'a' ) << "\n" ;
            return ;
        }
    }
}
void proc ( ) {
    string ans ;
    ans.clear ( ) ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( cnt[ i ] > 0 ) {
            cnt[ i ] -= k ;
            ans += ( char ( i + 'a' ) ) ;
            break ;
        }
    }
    int diff = 0 ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( cnt[ i ] > 0 ) { ++ diff ; }
    }
    if ( diff > 1 ) {
        for ( int i = 0 ; i < 26 ; ++ i ) {
            while ( cnt[ i ] > 0 ) {
                -- cnt[ i ] ;
                ans += ( char ( i + 'a' ) ) ;
            }
        }
        cout << ans << "\n" ;
    }
    else {
        for ( int i = 0 ; i < 26 ; ++ i ) {
            if ( cnt[ i ] > 0 ) {
                int h = ( cnt[ i ] / k ) ;
                if ( h * k != cnt[ i ] ) { ++ h ; }
                while ( h > 0 ) {
                    -- h ;
                    ans += ( char ( i + 'a' ) ) ;
                }
                cnt[ i ] = 0 ;
            }
        }
        cout << ans << "\n" ;        
    }

}

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        ++ cnt[ ( a[ i ] - 'a' ) ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( cnt[ i ] > 0 ) {
            if ( cnt[ i ] < k ) {
                get_kth ( ) ;
                return ;
            }
            proc ( ) ;
            return ;
        }
    }
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