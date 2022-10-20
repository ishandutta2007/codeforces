#include<bits/stdc++.h>
using namespace std ;

long long n , a , b ;

void input ( ) {
    cin >> n >> a >> b ;
}


void solve ( ) {
    long long sr = 1 ;
    while ( sr <= n ) {
        long long diff = n - sr ;
        if ( diff % b == 0 ) { cout << "Yes\n" ; return ; }
        if ( a == 1 ) { break ; }
        sr *= a ;
    }
    cout << "No\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
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