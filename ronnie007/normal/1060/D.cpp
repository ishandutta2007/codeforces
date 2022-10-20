#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
pair < int , int > a[ MAXN ] ;
priority_queue < int > x ;
priority_queue < int > y ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        x.push ( a[ i ].first ) ;
        y.push ( a[ i ].second ) ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int hh1 = x.top ( ) ;
        x.pop ( ) ;
        int hh2 = y.top ( ) ;
        y.pop ( ) ;
        ans += max ( hh1 , hh2 ) ;
    }
    ans += n ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}