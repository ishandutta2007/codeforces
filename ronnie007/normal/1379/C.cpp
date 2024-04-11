#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , cnt ;
pair < long long , long long > a[ MAXN ] ;

int pos[ MAXN ] ;

pair < long long , int > srt[ MAXN ] ;
long long pref[ MAXN ] ;

int f ( long long sr ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    if ( sr > srt[ 1 ].first ) { return 0 ; }
    if ( srt[ n ].first >= sr ) { return n ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( srt[ mid ].first >= sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( srt[ r ].first < sr ) { -- r ; }
    return r ;
}

void input ( ) {
    cin >> cnt >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        srt[ i ] = { a[ i ].first , i } ;
    }
    sort ( srt + 1 , srt + n + 1 , greater < pair < long long , int > > ( ) ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] + srt[ i ].first ) ;
        pos[ srt[ i ].second ] = i ;
    }
}

void solve ( ) {
    long long ans = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long aux = a[ i ].first ;
        int hh = f ( a[ i ].second ) ;
        if ( hh > cnt - 1 ) { hh = cnt - 1 ; }
        aux += pref[ hh ] ;
        long long lft = cnt - 1 - hh ;
        if ( pos[ i ] <= hh ) {
            aux -= a[ i ].first ;
            ++ lft ;
        }
        aux += lft * a[ i ].second ;
        if ( ans < aux ) { ans = aux ; }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}