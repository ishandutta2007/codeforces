#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100001

int n , k ;
pair < int , int > a[ MAXN ] ;
long long ans[ MAXN ] ;

vector < int > f ;
vector < int > lst ;
int mxval ;



struct tuhla {
    int x ;
    int st , en ;
    int coef ;
    tuhla ( ) { x = st = en = coef = 0 ; }
    tuhla ( int _x , int _st , int _en , int _coef ) {
        x = _x ;
        st = _st ; en = _en ;
        coef = _coef ;
    }
    bool operator < ( const tuhla other ) const {
        if ( x != other.x ) { return ( x < other.x ) ; }
        if ( st != other.st ) { return ( st < other.st ) ; }
        if ( en != other.en ) { return ( en < other.en ) ; }
        return ( coef < other.coef ) ;
    }
};

vector < tuhla > aux ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    vector < pair < int , int > > srt ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        srt.push_back ( { a[ i ].second , i } ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    mxval = k - 1 ;
    a[ srt[ 0 ].second ].second = mxval ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int diff = srt[ i ].first - srt[ i - 1 ].first ;
        int wh = srt[ i ].second ;
        if ( diff >= k ) { diff = k ; }
        mxval += diff ;
        a[ wh ].second = mxval ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux.push_back ( tuhla ( a[ i ].first - k + 1 , a[ i ].second - k + 1 , a[ i ].second , 1 ) ) ;
        aux.push_back ( tuhla ( a[ i ].first + 1 , a[ i ].second - k + 1 , a[ i ].second , -1 ) ) ;
    }
    sort ( aux.begin ( ) , aux.end ( ) ) ;
}

void solve ( ) {
    f.resize ( mxval + 1 ) ;
    lst.resize ( mxval + 1 ) ;
    for ( int i = 0 ; i <= mxval ; ++ i ) {
        f[ i ] = 0 , lst[ i ] = n * k ;
    }
    for ( auto h : aux ) {
        for ( int i = h.st ; i <= h.en ; ++ i ) {
            ans[ f[ i ] ] += max ( 0 , h.x - lst[ i ] ) ;
            lst[ i ] = h.x ;
            f[ i ] += h.coef ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%lld " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
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