#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 50007

int n ;
int a[ MAXN ] ;
int x ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    cin >> x ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] -= x ;
    }
}

void solve ( ) {
    int cnt = 0 ;
    int st = 1 ;
    int sub = 0 ;
    while ( st + 1 <= n ) {
        long long sm = a[ st ++ ] ;
        long long mx = 0 ;
        for ( ; st <= n ; ++ st ) {
            long long lst = sm ;
            sm += a[ st ] ;
            if ( sm < mx ) {
                ++ sub , ++ st ;
                break ;
            }
            mx = max ( mx , lst ) ;
        }
    }
    cout << n - sub << "\n" ;
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