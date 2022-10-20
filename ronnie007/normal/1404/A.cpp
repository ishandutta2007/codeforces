#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , k ;
string a ;


void input ( ) {
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    int cnt0 , cnt1 ;
    cnt0 = cnt1 = 0 ;
    for ( int i = 0 ; i < k ; ++ i ) {
        bool fl0 , fl1 ;
        fl0 = fl1 = false ;
        for ( int j = i ; j < n ; j += k ) {
            if ( a[ j ] == '0' ) { fl0 = true ; }
            if ( a[ j ] == '1' ) { fl1 = true ; }
        }
        if ( fl0 == true && fl1 == true ) {
            cout << "NO\n" ;
            return ;
        }
        if ( fl0 == true ) { ++ cnt0 ; }
        if ( fl1 == true ) { ++ cnt1 ; }
    }
    if ( cnt0 > ( k / 2 ) || cnt1 > ( k / 2 ) ) {
        cout << "NO\n" ;
        return ;
    }
    cout << "YES\n" ;
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