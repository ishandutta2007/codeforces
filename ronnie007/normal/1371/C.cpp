#include<bits/stdc++.h>
using namespace std ;

long long v , c , n , m ;

void input ( ) {
    cin >> v >> c >> n >> m ;
}

void solve ( ) {
    if ( v + c < n + m ) {
        cout << "No\n" ;
        return ;
    }
    if ( min ( v , c ) < m ) {
        cout << "No\n" ;
        return ;
    }
    cout << "Yes\n" ;
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