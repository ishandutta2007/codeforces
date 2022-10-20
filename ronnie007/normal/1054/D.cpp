#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , k ;
int a[ MAXN ] ;

int pref[ MAXN ] ;
map < int , int > w ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        pref[ i ] = ( pref[ i - 1 ] ^ a[ i ] ) ;
    }
}

void solve ( ) {
    int offset = (1<<k) - 1 ;
    long long ans = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        ++ w[ min ( pref[ i ] , pref[ i ] ^ offset ) ] ;
    }
    for ( auto it = w.begin ( ) ; it != w.end ( ) ; ++ it ) {
        long long aux = ( it->second + 1 ) / 2 ;
        ans += aux * ( aux - 1 ) / 2 ;
        aux = it->second - aux ;
        ans += aux * ( aux - 1 ) / 2 ;
    }
    cout << 1LL * n * ( n + 1 ) / 2 - ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}