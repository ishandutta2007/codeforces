#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007
#define MX_BUCKETS 1007
#define bucket 807

int n , q ;
pair < long long , int > a[ MAXN ] ;

int bucket_cnt ;

int st[ MX_BUCKETS ] ;
int en[ MX_BUCKETS ] ;

long long add[ MX_BUCKETS ] ;

pair < long long , int > aux1[ bucket + 2 ] ;
pair < long long , int > aux2[ bucket + 2 ] ;

void upd ( int id , int l , int r , int x ) {
    int sz1 , sz2 ;
    sz1 = sz2 = 0 ;
    for ( int i = st[ id ] ; i <= en[ id ] ; ++ i ) {
        if ( l <= a[ i ].second && a[ i ].second <= r ) {
            aux1[ sz1 ++ ] = { a[ i ].first + x , a[ i ].second } ;
        }
        else {
            aux2[ sz2 ++ ] = a[ i ] ;
        }
    }
    int pos1 , pos2 ;
    pos1 = pos2 = 0 ;
    while ( pos1 < sz1 || pos2 < sz2 ) {
        if ( pos1 == sz1 ) {
            a[ st[ id ] + pos1 + pos2 ] = aux2[ pos2 ] ;
            ++ pos2 ;
        }
        else if ( pos2 == sz2 ) {
            a[ st[ id ] + pos1 + pos2 ] = aux1[ pos1 ] ;
            ++ pos1 ;
        }
        else {
            if ( aux1[ pos1 ] < aux2[ pos2 ] ) {
                a[ st[ id ] + pos1 + pos2 ] = aux1[ pos1 ] ;
                ++ pos1 ; 
            }
            else {
                a[ st[ id ] + pos1 + pos2 ] = aux2[ pos2 ] ;
                ++ pos2 ;
            }
        }
    }
}

pair < int , int > ask ( int id , long long x ) {
    x -= add[ id ] ;
    if ( x < 0 ) { return { -1 , -1 } ; }
    int fst , scd ;
    fst = scd = -1 ;
    int l , r , mid ;
    l = st[ id ] ;
    r = en[ id ] ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ mid ].first < x ) { l = mid + 1 ; }
        else { r = mid ; }
    }
    while ( l < en[ id ] && a[ l ].first < x ) { ++ l ; }
    if ( a[ l ].first == x ) { fst = a[ l ].second ; }
    else { return { -1 , -1 } ; }

    l = st[ id ] ;
    r = en[ id ] ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ mid ].first <= x ) { l = mid ; }
        else { r = mid - 1 ; }
    }
    while ( r > st[ id ] && a[ r ].first > x ) { -- r ; }
    scd = a[ r ].second ;
    return { fst , scd } ;
}

int ans ( int x ) {
    int mn , mx ;
    mn = mx = -1 ;
    for ( int i = 1 ; i <= bucket_cnt ; ++ i ) {
        pair < int , int > ret = ask ( i , x ) ;
        if ( ret.first == -1 ) { continue ; }
        if ( mn == -1 ) {
            mn = ret.first ;
            mx = ret.second ;
        }
        else {
            if ( mn > ret.first ) { mn = ret.first ; }
            if ( mx < ret.second ) { mx = ret.second ; }
        }
    }
    if ( mn == -1 ) { return -1 ; }
    return ( mx - mn ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ].first ) ;
        a[ i ].second = i ;
    }
    int pos = 0 ;
    bucket_cnt = 0 ;
    while ( pos < n ) {
        ++ pos ;
        st[ ++ bucket_cnt ] = pos ;
        en[ bucket_cnt ] = min ( pos + bucket , n ) ;
        pos = en[ bucket_cnt ] ;
    }
    for ( int i = 1 ; i <= bucket_cnt ; ++ i ) {
        sort ( a + st[ i ] , a + en[ i ] + 1 ) ;
    }
}

void solve ( ) {
    int type ;
    int l , r , x ;
    while ( q -- ) {
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            scanf ( "%d%d%d" , &l , &r , &x ) ;
            for ( int i = 1 ; i <= bucket_cnt ; ++ i ) {
                if ( en[ i ] < l ) { continue ; }
                if ( l <= st[ i ] && en[ i ] <= r ) {
                    add[ i ] += x ;
                    continue ;
                }
                if ( r < st[ i ] ) { break ; }
                upd ( i , l , r , x ) ; 
            }
        }
        else {
            scanf ( "%d" , &x ) ;
            printf ( "%d\n" , ans ( x ) ) ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}