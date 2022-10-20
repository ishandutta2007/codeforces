#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 5e5 + 7 ;

int n , k ;
pair < int , int > a[ MAXN ] ;
int b[ MAXN ] ;

int pos[ MAXN ] ;
vector < int > at_pos[ MAXN ] ;
vector < int > at_val[ MAXN ] ;

int vals[ MAXN ] ;
ll neg[ MAXN ] ;

class Tree {
public :
    ll tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            if ( a[ IL ].second > 0 ) {
                tr[ where ] = a[ IL ].second ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    void update ( int where , int IL , int IR , int pos , int add ) {
        if ( IL == IR ) {
            tr[ where ] += add ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { update ( 2 * where , IL , mid , pos , add ) ; }
        else { update ( 2 * where + 1 , mid + 1 , IR , pos , add ) ; }
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    ll query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
Tree w ;


ll query ( int st , int en ) {
    ll ret = neg[ en ] - neg[ st - 1 ] ;
    ret += w.query ( 1 , 1 , n , st , en ) ;
    return ret ;
}

vector < int > best[ MAXN ] ;
ll dp[ MAXN ] ;

int f ( int lvl , int sr ) {
    int sz = best[ lvl ].size ( ) ;
    if ( sz == 0 ) { return -1 ; }
    if ( best[ lvl ][ 0 ] > sr ) { return -1 ; }
    int l , r , mid ;
    l = 0 , r = sz - 1 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( best[ lvl ][ mid ] <= sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( best[ lvl ][ r ] > sr ) { -- r ; }
    return best[ lvl ][ r ] ;
}

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].second ;
        if ( a[ i ].second >= 0 ) {
            at_val[ a[ i ].first ].push_back ( i ) ;
        }
    }
    cin >> k ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        cin >> b[ i ] ;
        vals[ b[ i ] ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        pos[ i ] = vals[ a[ i ].first ] ;
        if ( pos[ i ] > 0 ) {
            at_pos[ pos[ i ] ].push_back ( i ) ;
        }
    }
    neg[ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ].second < 0 ) {
            neg[ i ] = a[ i ].second + neg[ i - 1 ] ;
        }
        else {
            neg[ i ] = neg[ i - 1 ] ;
        }
    }

    w.init ( 1 , 1 , n ) ;
    best[ 0 ].push_back ( 0 ) ;
    ll ans = 1e17 ;
    for ( int wh = 1 ; wh <= k ; ++ wh ) {
        for ( auto i : at_pos[ wh ] ) {
            dp[ i ] = 1e17 ;
            int prv = f ( wh - 1 , i ) ;
            if ( prv > -1 ) {
                dp[ i ] = dp[ prv ] + query ( prv + 1 , i - 1 ) ;
            }
        }
        for ( int hh = b[ wh - 1 ] + 1 ; hh <= b[ wh ] ; ++ hh ) {
            for ( auto id : at_val[ hh ] ) {
                w.update ( 1 , 1 , n , id , -a[ id ].second ) ;
            }
        }
        for ( auto i : at_pos[ wh ] ) {
            if ( best[ wh ].empty ( ) == false ) {
                int prv = best[ wh ].back ( ) ;
                ll cand = dp[ prv ] + query ( prv + 1 , i - 1 ) ;
                dp[ i ] = min ( dp[ i ] , cand ) ;
            }
            if ( dp[ i ] < 1e17 ) {
                if ( wh == k ) {
                    ll cand = dp[ i ] + query ( i + 1 , n  ) ;
                    ans = min ( ans , cand ) ;
                }
                
                if ( best[ wh ].empty ( ) == true  ) {
                    best[ wh ].push_back ( i ) ;
                }
                else {
                    ll cand = dp[ best[ wh ].back ( ) ] + query ( best[ wh ].back ( ) + 1 , i ) ;
                    if ( cand > dp[ i ] ) {
                        best[ wh ].push_back ( i ) ;
                    }
                }
            }

        }
    }
    if ( ans == 1e17 ) { cout << "NO\n" ; }
    else {
        cout << "YES\n" ;
        cout << ans << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}