#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m , mx ;
int a[ MAXN ] ;

int ans[ MAXN ] ;

void input ( ) {
    cin >> n >> m >> mx ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    priority_queue < pair < long long , int > > q ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        q.push ( { 0 , i } ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        pair < long long , int > ret = q.top ( ) ;
        q.pop ( ) ;
        ans[ i ] = ret.second ;
        ret.first -= a[ i ] ;
        q.push ( ret ) ;
    }
    cout << "YES\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}