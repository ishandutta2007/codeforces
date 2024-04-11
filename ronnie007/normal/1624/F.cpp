#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int l , r , mid ;
    l = 1 , r = n - 1 ;
    if ( n == 2 ) {
        cout << "! 1\n" ;
        fflush ( stdout ) ;
        return ;
    }
    int lst = 0 ;
    int add = 0 ;
    while ( l < r ) {
        mid = ( l + r ) / 2 ;
        int nw = ( lst + 1 ) * n - ( mid + 1 ) - add ;
        cout << "+ " << nw << "\n" ;
        fflush ( stdout ) ;
        add += nw ;
        int ret ; cin >> ret ;
        if ( ret == lst ) { r = mid ; }
        else { l = mid + 1 ; }
        lst = ret ;
    }
    cout << "! " << l + add << "\n" ;
    fflush ( stdout ) ;
}


int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}