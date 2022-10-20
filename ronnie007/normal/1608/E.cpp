#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 100007

int n ;
struct el {
    int x , y , c ;
};

el a[ MAXN ] ;

set < int > s ;

map < int , int > revX , revY ;

vector < int > sortedx[ 4 ] ;
vector < int > sortedy[ 4 ] ;

vector < int > atx[ MAXN ][ 4 ] ;
vector < int > aty[ MAXN ][ 4 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].x >> a[ i ].y >> a[ i ].c ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        s.insert ( a[ i ].x ) ;
    }
    int tp = 0 ;
    for ( auto x : s ) {
        revX[ x ] = ++ tp ;
    }
    s.clear ( ) ;

    for ( int i = 1 ; i <= n ; ++ i ) {
        s.insert ( a[ i ].y ) ;
    }
    tp = 0 ;
    for ( auto y : s ) {
        revY[ y ] = ++ tp ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ].x = revX[ a[ i ].x ] ;
        a[ i ].y = revY[ a[ i ].y ] ;
    }
}

int wtf[ 3 ] = { 1 , 2 , 3 } ;

int lval[ MAXN ] ;
int rval[ MAXN ] ;

void advance ( int &st , int &en , int &cnt_left , int &cnt_right , int sr ) {
    while ( st >= 1 && cnt_left - lval[ st ] >= sr ) {
        cnt_left -= lval[ st -- ] ;
    }
    while ( en <= n && cnt_right - rval[ en ] >= sr ) {
        cnt_right -= rval[ en ++ ] ;
    }
}

bool check ( int sr ) {
    if ( sr == 0 ) { return true ; }
    int lx = sortedx[ wtf[ 0 ] ][ sr - 1 ] + 1 ;
    int hx = sortedx[ wtf[ 2 ] ][ ( n / 3 ) - sr ] - 1 ;
    int aux = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ].c == wtf[ 1 ] ) {
            if ( lx <= a[ i ].x && a[ i ].x <= hx ) { ++ aux ; }
        }
    }
    if ( aux >= sr ) { return true ; }
    
    int cnt_left , cnt_right ;
    cnt_left = cnt_right = 0 ;
    int st = n ;
    int en = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        lval[ i ] = rval[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= hx + 1 ; ++ i ) {
        if ( cnt_left >= sr && cnt_right >= sr ) {
            if ( st < en ) {
                return true ;
            }
        }
        for ( auto id : atx[ i ][ wtf[ 0 ] ] ) {
            ++ lval[ a[ id ].y ] ;
            if ( a[ id ].y <= st ) {
                ++ cnt_left ;
            }
        }
        for ( auto id : atx[ i ][ wtf[ 1 ] ] ) {
            ++ rval[ a[ id ].y ] ;
            if ( a[ id ].y >= en ) {
                ++ cnt_right ;
            }
        }
        advance ( st , en , cnt_left , cnt_right , sr ) ;
    }
    return false ;
}

bool f ( int sr ) {
    wtf[ 0 ] = 1 , wtf[ 1 ] = 2 , wtf[ 2 ] = 3 ;
    do {
        if ( check ( sr ) == true ) { return true ; }
    } while ( next_permutation ( wtf , wtf + 3 ) ) ;
    return false ;
}

int get_opt ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        sortedx[ a[ i ].c ].clear ( ) ;
        sortedy[ a[ i ].c ].clear ( ) ;
        for ( int j = 1 ; j <= 3 ; ++ j ) {
            atx[ i ][ j ].clear ( ) ;
            aty[ i ][ j ].clear ( ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        sortedx[ a[ i ].c ].push_back ( a[ i ].x ) ;
        sortedy[ a[ i ].c ].push_back ( a[ i ].y ) ;

        atx[ a[ i ].x ][ a[ i ].c ].push_back ( i ) ;
        aty[ a[ i ].y ][ a[ i ].c ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= 3 ; ++ i ) {
        sort ( sortedx[ i ].begin ( ) , sortedx[ i ].end ( ) ) ;
        sort ( sortedy[ i ].begin ( ) , sortedy[ i ].end ( ) ) ;
    }    
    int l , r , mid ;
    l = 0 ;
    r = n / 3 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    while ( f ( r ) == false ) { -- r ; }
    return 3 * r ;
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        ans = max ( ans , get_opt ( ) ) ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            a[ j ].x = n - a[ j ].x + 1 ;
        }
        ans = max ( ans , get_opt ( ) ) ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            swap ( a[ j ].x , a[ j ].y ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}