#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n , p ;
int a[ MAXN ] ;

bool used[ MAXN ] ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;

vector < pair < int , int > > srt ;

long long ans = 0 ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y , int add ) {
    int k1 = get ( x ) ;
    int k2 = get ( y ) ;
    if ( k1 != k2 ) {
        ans += add ;
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
}

void proc ( int mid ) {
    used[ mid ] = true ;
    int st = mid - 1 ;
    int hh = a[ mid ] ;
    while ( st >= 1 ) {
        hh = __gcd ( hh , a[ st ] ) ;
        if ( hh == a[ mid ] ) {
            unite ( st , mid , hh ) ;
        }
        else { break ; }
        if ( used[ st ] == true ) { break ; }
        used[ st ] = true ;
        -- st ;
    }
    st = mid + 1 ;
    hh = a[ mid ] ;
    while ( st <= n ) {
        hh = __gcd ( hh , a[ st ] ) ;
        if ( hh == a[ mid ] ) {
            unite ( st , mid , hh ) ;
        }
        else { break ; }
        if ( used[ st ] == true ) { break ; }
        used[ st ] = true ;
        ++ st ;
    }
}

void input ( ) {
    cin >> n >> p ;
    srt.clear ( ) ;
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        srt.push_back ( { a[ i ] , i } ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = false ;
        prv[ i ] = -1 ; rnk[ i ] = 0 ;
    }
}

void solve ( ) {
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( srt[ i ].first >= p ) { break ; }
        proc ( srt[ i ].second ) ;
    }
    long long coef = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        coef += ( prv[ i ] == -1 ) ;
    }
    -- coef ;
    ans += coef * p ;
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}