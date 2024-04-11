#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
vector < long long > v ;



void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long x ;
        cin >> x ;
        v.push_back ( x ) ;
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
}

void solve ( ) {
    long long sm = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        sm += v[ i ] ;
    }
    int q ;
    cin >> q ;
    while ( q -- ) {
        long long x , y ;
        cin >> x >> y ;
        auto it = lower_bound ( v.begin ( ) , v.end ( ) , x ) ;
        long long ans = -1 ;
        if ( it != v.end ( ) ) {
            long long aux = y - ( sm - (*it) ) ;
            if ( aux < 0 ) { aux = 0 ; }
            if ( ans == -1 || ans > aux ) { ans = aux ; }
        }
        if ( it != v.begin ( ) ) {
            -- it ;
            long long aux = y - ( sm - (*it) ) ;
            if ( aux < 0 ) { aux = 0 ; }
            aux += ( x - (*it) ) ;
            if ( ans == -1 || ans > aux ) { ans = aux ; }
        }
        cout << ans << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}