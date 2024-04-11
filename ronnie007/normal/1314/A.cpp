#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
pair < int , long long > a[ MAXN ] ;

priority_queue < long long > q ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].second ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    long long ans = 0 ;
    long long sm = 0 ;
    int lst = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ].first != a[ i - 1 ].first ) {
            int diff = a[ i ].first - a[ i - 1 ].first ;
            while ( diff > 0 && q.empty ( ) == false ) {
                -- diff ;
                long long aux = q.top ( ) ;
                q.pop ( ) ;
                sm -= aux ; ans += sm ;
            }
        }
        sm += a[ i ].second ;
        q.push ( a[ i ].second ) ;
    }
    while ( q.empty ( ) == false ) {
        long long aux = q.top ( ) ;
        q.pop ( ) ;
        sm -= aux ; ans += sm ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}