#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

#define MAXN 3007

int n ;
pair < int , int > a[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;
bool vis[ MAXN ] ;

vector < int > cycles[ MAXN ] ;

void dfs ( int vertex , int pos , int ori ) {
    vis[ vertex ] = true ;
    for ( auto e : v[ vertex ] ) {
        if ( vis[ e.first ] == false ) {
            cycles[ pos ].push_back ( e.second ) ;
            dfs ( e.first , pos , ori ) ;
        }
    }
    if ( vertex == ori ) {
        cycles[ pos ].push_back ( v[ vertex ][ 0 ].second + v[ vertex ][ 1 ].second - cycles[ pos ].front ( ) ) ;
    }
}

ll ans ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        v[ a[ i ].first ].push_back ( { a[ i ].second , i } ) ;
        v[ a[ i ].second ].push_back ( { a[ i ].first , i } ) ;
    }
}

void solve ( ) {
    int tp = 0 ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        if ( vis[ i ] == false ) {
            dfs ( i , ++ tp , i ) ;
        }
    }
    for ( int wh = 1 ; wh <= tp ; ++ wh ) {
        int sz = cycles[ wh ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int mn_x = MAXN , mx_x = 0 , mn_y = MAXN , mx_y = 0 ;
            for ( int cnt = 0 ; cnt < sz ; ++ cnt ) {
                if ( cnt == sz - 1 && i != 0 ) { continue ; }
                int j = ( cnt + i ) % sz ;
                int pos = cycles[ wh ][ j ] ;
                mn_x = min ( mn_x , a[ pos ].first ) , mx_x = max ( mx_x , a[ pos ].first ) ;
                mn_y = min ( mn_y , a[ pos ].second ) , mx_y = max ( mx_y , a[ pos ].second ) ;

                int aux_mnx = 0 , aux_mxx = n + 1 , aux_mny = n , aux_mxy = 2 * n + 1 ;

                if ( cnt < sz - 1 ) {
                    int prv_pos = cycles[ wh ][ ( i - 1 + sz ) % sz ] ;
                    int nxt_pos = cycles[ wh ][ ( j + 1 ) % sz ] ;
                    int nxt , prv ;
                    if ( a[ prv_pos ].first == a[ cycles[ wh ][ i ] ].first || a[ prv_pos ].first == a[ cycles[ wh ][ i ] ].second ) {
                        prv = a[ prv_pos ].second ;
                    }
                    else { prv = a[ prv_pos ].first ; }

                    if ( a[ nxt_pos ].first == a[ cycles[ wh ][ j ] ].first || a[ nxt_pos ].first == a[ cycles[ wh ][ j ] ].second ) {
                        nxt = a[ nxt_pos ].second ;
                    }
                    else { nxt = a[ nxt_pos ].first ; }

                    if ( prv <= n ) {
                        if ( mn_x <= prv && prv <= mx_x ) { continue ; }
                        if ( prv < mn_x ) { aux_mnx = max ( aux_mnx , prv ) ; }
                        if ( prv > mx_x ) { aux_mxx = min ( aux_mxx , prv ) ; }
                    }
                    else {
                        if ( mn_y <= prv && prv <= mx_y ) { continue ; }
                        if ( prv < mn_y ) { aux_mny = max ( aux_mny , prv ) ; }
                        if ( prv > mx_y ) { aux_mxy = min ( aux_mxy , prv ) ; }
                    }
                    if ( nxt <= n ) {
                        if ( mn_x <= nxt && nxt <= mx_x ) { continue ; }
                        if ( nxt < mn_x ) { aux_mnx = max ( aux_mnx , nxt ) ; }
                        if ( nxt > mx_x ) { aux_mxx = min ( aux_mxx , nxt ) ; }
                    }
                    else {
                        if ( mn_y <= nxt && nxt <= mx_y ) { continue ; }
                        if ( nxt < mn_y ) { aux_mny = max ( aux_mny , nxt ) ; }
                        if ( nxt > mx_y ) { aux_mxy = min ( aux_mxy , nxt ) ; }
                    }
                }
                ans += 1LL * ( ( cnt + 2 ) / 2 ) * ( mn_x - aux_mnx ) * ( aux_mxx - mx_x )
                                        * ( mn_y - aux_mny ) * ( aux_mxy - mx_y ) ;
            }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}