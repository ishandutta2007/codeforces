#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 1000007
#define MAXVAL 5001
#define lim 669

int n ;
int a[ MAXVAL ] ;

vector < int > primes ;
int rv[ MAXN ] ;
int mxid ;
vector < int > divs[ MAXVAL ] ;

int pref[ MAXVAL ] ;

int v[ MAXVAL ][ lim + 2 ] ;
int suff[ MAXVAL ][ lim + 2 ] ;

vector < int > ans ;

void init ( ) {
    for ( int i = 2 ; i < MAXVAL ; ++ i ) {
        if ( (int)divs[ i ].size ( ) != 0 ) { continue ; }
        primes.push_back ( i ) ;
        rv[ i ] = mxid ++ ;
        for ( int j = i ; j < MAXVAL ; j += i ) {
            int x = j ;
            while ( ( x % i ) == 0 ) {
                x /= i ;
                divs[ j ].push_back ( i ) ;
            }
        }
    }
    for ( int i = 0 ; i < MAXVAL ; ++ i ) {
        if ( i > 0 ) {
            for ( int j = 0 ; j < lim ; ++ j ) {
                v[ i ][ j ] = v[ i - 1 ][ j ] ;
            }
        }
        for ( auto x : divs[ i ] ) {
            ++ v[ i ][ rv[ x ] ] ;
        }
        for ( int j = lim - 1 ; j >= 0 ; -- j ) {
            suff[ i ][ j ] = suff[ i ][ j + 1 ] + v[ i ][ j ] ;
        }
    }
}


void input ( ) {
    init ( ) ;
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ; scanf ( "%d" , &x ) ;
        ++ a[ x ] ;
    }
    pref[ 0 ] = a[ 0 ] ;
    for ( int i = 1 ; i < MAXVAL ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] + a[ i ] ) ;
    }
}

int get_kth ( int x , int k ) {
    int l , r , mid ;
    l = 0 , r = lim - 1 ;
    if ( suff[ x ][ 0 ] < k ) { return 1 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( suff[ x ][ mid ] >= k ) { l = mid ; }
        else { r = mid ; }
    }
    while ( suff[ x ][ r ] < k ) { -- r ; }
    return primes[ r ] ;
}

int get_fst ( int st , int en , int sr , int pos ) {
    int l , r , mid ;
    l = st , r = en ;
    if ( get_kth ( en , pos ) < sr ) { return en + 1 ; }
    if ( sr < get_kth ( st , pos ) ) { return en + 1 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( get_kth ( mid , pos ) < sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( get_kth ( l , pos ) < sr ) { ++ l ; }
    return l ;
}

int get_lst ( int st , int en , int sr , int pos ) {
    int l , r , mid ;
    l = st , r = en ;
    if ( get_kth ( en , pos ) < sr ) { return en + 1 ; }
    if ( sr < get_kth ( st , pos ) ) { return en + 1 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( get_kth ( mid , pos ) > sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( get_kth ( r , pos ) > sr ) { -- r ; }
    return r ;
}

void solve ( ) {
    int st = 0 , en = MAXVAL - 1 ;
    int sz = 0 ;
    while ( 1 ) {
        bool fl = false ;
        for ( int nxt = 0 ; nxt < lim ; ++ nxt ) {
            int fst = get_fst ( st , en , primes[ nxt ] , sz + 1 ) ;
            int lst = get_lst ( st , en , primes[ nxt ] , sz + 1 ) ;
            if ( fst > en ) { continue ; }
            int tot = pref[ lst ] - pref[ fst - 1 ] ;
            if ( tot > n - tot ) {
                ans.push_back ( primes[ nxt ] ) ;
                fl = true ;
                ++ sz ;
                st = fst , en = lst ;
                break ;
            }
        }
        if ( fl == false ) { break ; }
    }
    long long ret = 0 ;
    for ( int i = 0 ; i < MAXVAL ; ++ i ) {
        int pos = lim - 1 ;
        int add = suff[ i ][ 0 ] + sz ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            while ( pos > 0 && v[ i ][ pos ] == 0 ) { -- pos ; }
            if ( v[ i ][ pos ] > 0 && primes[ pos ] == ans[ j ] ) {
                -- v[ i ][ pos ] ;
                add -= 2 ;
            }
            else { break ; }
        }
        ret += 1LL * a[ i ] * add ;
    }
    printf ( "%lld\n" , ret ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}