#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 100007

int n , m , k ;
long long mv[ MAXN ] ;
long long cost[ MAXN ] ;

struct ladder {
    int stx , sty , enx , eny ;
    int h ;
    int id ;
};

bool cmp_sty ( ladder p1 , ladder p2 ) {
    return ( p1.sty < p2.sty ) ;
}
bool cmp_eny ( ladder p1 , ladder p2 ) {
    return ( p1.eny < p2.eny ) ;
}

ladder a[ MAXN ] ;

vector < ladder > ending_at[ MAXN ] ;
vector < ladder > starting_at[ MAXN ] ;

long long inf = 1 ;

void input ( ) {
    cin >> n >> m >> k ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        ending_at[ i ].clear ( ) ;
        starting_at[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> mv[ i ] ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        cin >> a[ i ].stx >> a[ i ].sty >> a[ i ].enx >> a[ i ].eny >> a[ i ].h ;
        a[ i ].id = i ;
        starting_at[ a[ i ].stx ].push_back ( a[ i ] ) ;
        ending_at[ a[ i ].enx ].push_back ( a[ i ] ) ;
        cost[ i ] = -inf ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        sort ( starting_at[ i ].begin ( ) , starting_at[ i ].end ( ) , cmp_sty ) ;
        sort ( ending_at[ i ].begin ( ) , ending_at[ i ].end ( ) , cmp_eny ) ;
    }
}

void solve ( ) {
    for ( auto aux : starting_at[ 1 ] ) {
        cost[ aux.id ] = aux.h - 1LL * ( aux.sty - 1 ) * mv[ 1 ] ;
    }
    for ( int wh = 2 ; wh < n ; ++ wh ) {
        int sz = ending_at[ wh ].size ( ) ;
        int pos = 0 ;
        int len = starting_at[ wh ].size ( ) ;
        long long mx = -inf ;
        for ( int i = 0 ; i < len ; ++ i ) {
            while ( pos < sz && ending_at[ wh ][ pos ].eny <= starting_at[ wh ][ i ].sty ) {
                if ( cost[ ending_at[ wh ][ pos ].id ] > -inf ) { 
                    mx = max ( mx , cost[ ending_at[ wh ][ pos ].id ] + 1LL * mv[ wh ] * ending_at[ wh ][ pos ].eny ) ;
                }
                ++ pos ;
            }
            if ( mx > -inf ) {
                cost[ starting_at[ wh ][ i ].id ] = max ( cost[ starting_at[ wh ][ i ].id ] , mx - 1LL * mv[ wh ] * starting_at[ wh ][ i ].sty ) ;
            }
        }
        mx = -inf ;
        pos = sz - 1 ;
        for ( int i = len - 1 ; i >= 0 ; -- i ) {
            while ( pos >= 0 && ending_at[ wh ][ pos ].eny >= starting_at[ wh ][ i ].sty ) {
                if ( cost[ ending_at[ wh ][ pos ].id ] > -inf ) {
                    mx = max ( mx , cost[ ending_at[ wh ][ pos ].id ] - 1LL * mv[ wh ] * ending_at[ wh ][ pos ].eny ) ;
                }
                -- pos ;
            }
            if ( mx > -inf ) {
                cost[ starting_at[ wh ][ i ].id ] = max ( cost[ starting_at[ wh ][ i ].id ] , mx + 1LL * mv[ wh ] * starting_at[ wh ][ i ].sty ) ;
            }
            if ( cost[ starting_at[ wh ][ i ].id ] > -inf ) {
                cost[ starting_at[ wh ][ i ].id ] += starting_at[ wh ][ i ].h ;
            }
        }
    }
    long long ans = -inf ;
    for ( auto aux : ending_at[ n ] ) {
        if ( cost[ aux.id ] > -inf ) { 
            long long sr = cost[ aux.id ] - 1LL * ( m - aux.eny ) * mv[ n ] ;
            ans = max ( ans , sr ) ;
        }
    }
    if ( ans == -inf ) { cout << "NO ESCAPE\n" ; }
    else { cout << -ans << "\n" ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    for ( int i = 1 ; i <= 18 ; ++ i ) { inf *= 10 ; }
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}