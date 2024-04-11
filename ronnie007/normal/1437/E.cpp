#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007
#define inf 1000000007

int n , k ;
int a[ MAXN ] ;
int b[ MAXN ] ;

vector < int > v ;

int add ( int x ) {
    if ( v.size ( ) == 0 ) {
        v.push_back ( x ) ;
        return 0 ;
    }
    int l , r , mid ;
    l = 0 ;
    r = v.size ( ) - 1 ;
    if ( v[ r ] <= x ) {
        v.push_back ( x ) ;
        return v.size ( ) - 1 ;
    }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( v[ mid ] <= x ) { l = mid ; }
        else { r = mid ; }
    }
    while ( v[ l ] <= x ) { ++ l ; }
    v[ l ] = x ;
    return l ;
}

int calc ( int st , int en ) {
    int ret = 0 ;
    v.clear ( ) ;
    int tot = 0 ;
    for ( int i = st + 1 ; i < en ; ++ i ) {
        if ( a[ i ] < a[ st ] ) { ++ ret ; continue ; }
        ++ tot ;
        add ( a[ i ] ) ;
    }
    ret += tot - add ( a[ en ] ) ;
    return ret ;
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] -= i ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    b[ 0 ] = 0 ;
    a[ 0 ] = -inf ;
    b[ k + 1 ] = n + 1 ;
    a[ n + 1 ] = inf ;
    for ( int i = 0 ; i < k ; ++ i ) {
        if ( a[ b[ i ] ] > a[ b[ i + 1 ] ] ) {
            cout << "-1\n" ;
            return ;
        }
    }
    int ans = 0 ;
    for ( int i = 0 ; i <= k ; ++ i ) {
        ans += calc ( b[ i ] , b[ i + 1 ] ) ;
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