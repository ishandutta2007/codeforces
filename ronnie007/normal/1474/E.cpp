#include<bits/stdc++.h>
using namespace std ;

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    long long ans = 1LL * ( n - 1 ) * ( n - 1 ) ;
    for ( int i = 2 ; i < n ; ++ i ) {
        int aux = max ( i - 1 , n - i ) ;
        ans += 1LL * aux * aux ;
    }
    int mid = ( n / 2 ) ;
    cout << ans << "\n" ;
    cout << mid + 1 << " " ;
    for ( int i = 1 ; i < mid ; ++ i ) {
        cout << i << " " ;
    }
    for ( int i = mid + 2 ; i <= n ; ++ i ) {
        cout << i << " " ;
    }
    cout << mid << "\n" ;
    cout << n - 1 << "\n" ;
    for ( int i = mid + 1 ; i < n ; ++ i ) {
        cout << i << " 1" << "\n" ;
    }
    for ( int i = mid ; i >= 2 ; -- i ) {
        cout << i << " " << n << "\n" ;
    }
    cout << "1 " << n << "\n" ;
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