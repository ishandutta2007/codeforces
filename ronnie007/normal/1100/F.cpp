#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n ;
int a[ MAXN ] ;

int precalc[ 4 * MAXN ] ;

int lst_pos[ MAXN ] ;

void add ( vector < int > &aux , int x ) {
    int sz = aux.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int lowbit = aux[ i ] - ( aux[ i ] & ( aux[ i ] - 1 ) ) ;
        if ( ( x & lowbit ) > 0 ) {
            x ^= aux[ i ] ;
        }
        if ( x == 0 ) { return ; }
    }
    int lowbit = x - ( x & ( x - 1 ) ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( ( aux[ i ] & lowbit ) > 0 ) {
            aux[ i ] ^= x ;
        }
    }
    aux.push_back ( x ) ;
}

void unite ( vector < int > &v1 , vector < int > v2 ) {
    if ( v1.size ( ) == 21 ) { return ; }
    int sz = v2.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        add ( v1 , v2[ i ] ) ;
    }
}

vector < int > ans ;


int bit_rev ( int x ) {
    int ret = 0 ;
    for ( int i = 0 ; i < 20 ; ++ i ) {
        if ( ( x & (1<<i) ) > 0 ) {
            ret += (1<<(19-i)) ;
        }
    }
    return ret ;
}

vector < pair < int , int > > to_solve[ MAXN ] ;
int final_ans[ MAXN ] ;

int proc ( ) {
    int ret = 0 ;
    int sz = ans.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        ret ^= ans[ i ] ;
    }
    return precalc[ ret ] ;
}

vector < int > pref[ MAXN ] ;
vector < int > suff[ MAXN ] ;

void rec ( int st , int en ) {
    if ( st >= en ) { return ; }
    int mid = ( st + en ) / 2 ;
    pref[ mid + 1 ].clear ( ) ;
    suff[ mid ].clear ( ) ;
    for ( int i = mid + 1 ; i <= en ; ++ i ) {
        suff[ i ] = suff[ i - 1 ] ;
        add ( suff[ i ] , a[ i ] ) ;
    }
    for ( int i = mid ; i >= st ; -- i ) {
        pref[ i ] = pref[ i + 1 ] ;
        add ( pref[ i ] , a[ i ] ) ;
    }
    for ( int i = st ; i <= mid ; ++ i ) {
        for ( int j = lst_pos[ i ] ; j >= 0 ; -- j ) {
            if ( to_solve[ i ][ j ].first < mid ) { break ; }
            -- lst_pos[ i ] ;
            ans = pref[ i ] ;
            unite ( ans , suff[ to_solve[ i ][ j ].first ] ) ;
            final_ans[ to_solve[ i ][ j ].second ] = proc ( ) ;
        }
    }
    if ( st < mid ) {
        rec ( st , mid ) ;
    }
    if ( mid + 1 < en ) {
        rec ( mid + 1 , en ) ;
    }
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i < (1<<20) ; ++ i ) {
        precalc[ i ] = bit_rev ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        a[ i ] = precalc[ a[ i ] ] ;
    }
}

void solve ( ) {
    int q ;
    scanf ( "%d" , &q ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int l , r ;
        scanf ( "%d%d" , &l , &r ) ;
        if ( l == r ) { final_ans[ i ] = precalc[ a[ l ] ] ; }
        else { to_solve[ l ].push_back ( { r , i } ) ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        sort ( to_solve[ i ].begin ( ) , to_solve[ i ].end ( ) ) ;
        lst_pos[ i ] = to_solve[ i ].size ( ) - 1 ;
    }
    rec ( 1 , n ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        printf ( "%d\n" , final_ans[ i ] ) ;
    }
    
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}