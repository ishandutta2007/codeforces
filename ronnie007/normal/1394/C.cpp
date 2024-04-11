#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n ;
pair < int , int > a[ MAXN ] ;
vector < int > v[ MAXN ] ;
string s ;

int ans ;
pair < int , int > best ;

map < int , int > x_left ;
map < int , int > y_left ;

map < int , int > x_right ;
map < int , int > y_right ;

map < int , int > sm_left ;
map < int , int > sm_right ;

int f ( int x , int y ) {
    int ret = 0 ;
    if ( x_left.empty ( ) == false ) {
        ret = max ( ret , x - x_left.begin ( )->first ) ;
        ret = max ( ret , y - y_left.begin ( )->first ) ;
        ret = max ( ret , sm_left.rbegin ( )->first - y + x ) ;
    }

    ret = max ( ret , x_right.rbegin ( )->first - x ) ;
    ret = max ( ret , y_right.rbegin ( )->first - y ) ;
    ret = max ( ret , sm_right.rbegin ( )->first - x + y ) ;

    if ( ret < ans ) {
        ans = ret ;
        best = { x , y } ;
    }
    return ret ;
}

void proc ( int x ) {
    int l , r , mid1 , mid2 ;
    l = 0 ;
    r = MAXN - 2 ;
    if ( x == 0 ) { l = 1 ; }
    while ( r - l > 3 ) {
        mid1 = ( 2 * l + r ) / 3 ;
        mid2 = ( l + 2 * r ) / 3 ;
        f ( x , mid1 ) ; f ( x , mid2 ) ;
        if ( f ( x , mid1 ) <= f ( x ,mid2 ) ) {
            r = mid2 ;
        }
        else {
            l = mid1 ;
        }
    }
    for ( int i = l ; i <= r ; ++ i ) {
        f ( x , i ) ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> s ;
        int sz = s.size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            a[ i ].first += ( s[ j ] == 'B' ) ;
            a[ i ].second += ( s[ j ] == 'N' ) ;
        }
        v[ a[ i ].first ].push_back ( a[ i ].second ) ;
        ++ x_right[ a[ i ].first ] ;
        ++ y_right[ a[ i ].second ] ;
        ++ sm_right[ a[ i ].first - a[ i ].second ] ;
    }
}

void solve ( ) {
    ans = 5 * MAXN ; 
    for ( int i = 0 ; i <= 500000 ; ++ i ) {
        proc ( i ) ;
        int sz = v[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int fst = i ;
            int scd = v[ i ][ j ] ;
            -- x_right[ fst ] ;
            -- y_right[ scd ] ;
            -- sm_right[ fst - scd ] ;

            ++ x_left[ fst ] ;
            ++ y_left[ scd ] ;
            ++ sm_left[ - fst + scd ] ;
        }
    }
    cout << ans << "\n" ;
    for ( int i = 0 ; i < best.first ; ++ i ) {
        cout << "B" ;
    }
    for ( int i = 0 ; i < best.second ; ++ i ) {
        cout << "N" ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}