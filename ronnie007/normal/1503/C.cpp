#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;

struct tuhla {
    int lvl , c ;
    int id ;
};

tuhla a[ MAXN ] ;

long long ans = 0 ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].lvl >> a[ i ].c ;
        a[ i ].id = i ;
        ans += a[ i ].c ;
    }
    auto cmp = [ & ] ( tuhla p1 , tuhla p2 ) {
        return ( p1.lvl < p2.lvl ) ;
    };
    sort ( a + 1 , a + n + 1 , cmp ) ;
}

void solve ( ) {
    int mx = a[ 1 ].lvl + a[ 1 ].c ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( mx < a[ i ].lvl ) {
            ans += a[ i ].lvl - mx ;
        }
        if ( mx < a[ i ].lvl + a[ i ].c ) {
            mx = a[ i ].lvl + a[ i ].c ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}