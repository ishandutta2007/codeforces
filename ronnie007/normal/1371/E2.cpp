#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define inf 1000000007

int n , p ;
int a[ MAXN ] ;

vector < int > ans ;

void input ( ) {
    cin >> n >> p ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    a[ n + 1 ] = inf ;
    int st = 1 ;
    int id = 1 ;
    int mx = inf ;
    int mn = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i >= p ) {
            mx = min ( mx , a[ i ] - ( i - p ) ) ;
        }
        mn = max ( mn , a[ i ] - i + 1 ) ;
    }
    if ( mx < mn ) {
        cout << "0\n" ;
        return ;
    }
    cout << mx - mn << "\n" ;
    for ( int i = mn ; i < mx ; ++ i ) {
        cout << i << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}