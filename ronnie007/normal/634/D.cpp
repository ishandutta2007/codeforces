#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int lim , cap ;
int n ;

pair < int , int > a[ MAXN ] ;
int nxt[ MAXN ] ;

struct tuhla {
    int pos , lft , cost ;
    tuhla ( ) { pos = lft = cost = 0 ; }
    tuhla ( int _pos , int _lft , int _cost ) {
        pos = _pos ; lft = _lft ; cost = _cost ;
    }
    bool operator > ( tuhla other ) const {
        return cost < other.cost ;
    }
};

void input ( ) {
    scanf ( "%d%d%d" , &lim , &cap , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    a[ n + 1 ] = { lim , 0 } ;
}

void solve ( ) {
    stack < pair < int , int > > s ;
    s.push ( { 0 , n + 1 } ) ;
    for ( int i = n ; i >= 1 ; -- i ) {
        while ( s.empty ( ) == false && s.top ( ).first > a[ i ].second ) {
            s.pop ( ) ;
        }
        nxt[ i ] = s.top ( ).second ;
        s.push ( { a[ i ].second , i } ) ;
    }
    long long ans = 0 ;
    long long lft = cap ;
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        lft -= ( a[ i ].first - a[ i - 1 ].first ) ;
        if ( lft < 0 ) {
            printf ( "-1\n" ) ;
            return ;
        }
        if ( i == n + 1 ) { break ; }
        int dist = a[ nxt[ i ] ].first - a[ i ].first ;
        int coef = min ( cap , dist ) - lft ;
        coef = max ( coef , 0 ) ;
        ans += 1LL * coef * a[ i ].second ;
        lft += coef ;
    }
    printf ( "%lld\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}