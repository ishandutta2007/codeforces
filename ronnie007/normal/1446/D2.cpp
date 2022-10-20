#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 2e5 + 7 ;
const int MAGIC = 500 ;

int n ;
int a[ MAXN ] , freq[ MAXN ] ;
vector < pair < int , int > > srt ;

int cm ;
vector < int > v[ MAXN ] ;
int pref[ MAXN ] ;
int nxt[ MAXN ] ;

int fst[ 2 * MAXN ] ;

int heavy ( int minus , int plus ) {
    int sm = MAXN ;
    for ( int i = MAXN - n ; i <= MAXN + n ; ++ i ) {
        fst[ i ] = -1 ;
    }
    fst[ sm ] = 0 ;
    int ret = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == minus ) { -- sm ; }
        if ( a[ i ] == plus ) { ++ sm ; }
        if ( fst[ sm ] >= 0 ) {
            ret = max ( ret , i - fst[ sm ] ) ;
        }
        else {
            fst[ sm ] = i ;
        }
    }
    return ret ;
}

int cnt[ MAXN ] , aux[ MAXN ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ freq[ a[ i ] ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( freq[ i ] > 0 ) {
            srt.push_back ( { freq[ i ] , i } ) ;
        }
    }
    sort ( srt.begin ( ) , srt.end ( ) , greater < pair < int , int > > ( ) ) ; 
    if ( (int)srt.size ( ) == 1 ) {
        cout << "0\n" ;
        return ;
    }
    if ( srt[ 0 ].first == srt[ 1 ].first ) {
        cout << n << "\n" ;
        return ;
    }
    cm = srt[ 0 ].second ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ a[ i ] ].push_back ( i ) ;
    }
    int ans = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == cm ) { continue ; }
        if ( freq[ i ] >= MAGIC ) {
            ans = max ( ans , heavy ( i , cm ) ) ;
        }
    }
    for ( int lim = 1 ; lim <= MAGIC ; ++ lim ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            cnt[ i ] = aux[ i ] = 0 ;
        }
        int r = 0 ;
        for ( int l = 1 ; l <= n ; ++ l ) {
            while ( r < n && cnt[ a[ r + 1 ] ] + 1 <= lim ) {
                -- aux[ cnt[ a[ r + 1 ] ] ] ;
                ++ cnt[ a[ r + 1 ] ] ;
                ++ aux[ cnt[ a[ r + 1 ] ] ] ;
                ++ r ;
            }
            if ( aux[ lim ] >= 2 ) {
                ans = max ( ans , r - l + 1 ) ;
            }
            -- aux[ cnt[ a[ l ] ] ] ;
            -- cnt[ a[ l ] ] ;
            ++ aux[ cnt[ a[ l ] ] ] ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}