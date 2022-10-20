#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const ll mod = ( 119 << 23 ) + 1 , root = 62 ;
typedef vector < ll > vl ;

ll fastpow ( ll x , ll pw ) {
    ll ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % mod ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % mod ;
            -- pw ;
        }
    }
    return ret ;
}

void ntt ( vl &a ) {
    int n = a.size ( ) , L = 31 - __builtin_clz ( n ) ;
    static vl rt ( 2 , 1 ) ;
    for ( static int k = 2 , s = 2 ; k < n ; k *= 2 , ++ s ) {
        rt.resize ( n ) ;
        ll z[] = { 1 , fastpow ( root , mod >> s ) } ;
        for ( int i = k ; i < 2 * k ; ++ i ) {
            rt[ i ] = ( rt[ i / 2 ] * z[ i & 1 ] ) % mod ;
        }
    }
    vl rev ( n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        rev[ i ] = ( rev[ i / 2 ] | ( i & 1 ) << L ) / 2 ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( i < rev[ i ] ) { swap ( a[ i ] , a[ rev[ i ] ] ) ; }
    }
    for ( int k = 1 ; k < n ; k *= 2 ) {
        for ( int i = 0 ; i < n ; i += 2 * k ) {
            for ( int j = 0 ; j < k ; ++ j ) {
                ll z = rt[ j + k ] * a[ i + j + k ] % mod , &ai = a[ i + j ] ;
                a[ i + j + k ] = ai - z + ( z > ai ? mod : 0 ) ;
                ai += ( ai + z >= mod ? z - mod : z ) ;
            }
        }
    }
}

vl conv ( const vl &a , const vl &b ) {
    if ( a.empty ( ) || b.empty ( ) ) { return { } ; }
    int s = a.size ( ) + b.size ( ) - 1 , B = 32 - __builtin_clz ( s ) , n = 1 << B ;
    int inv = fastpow ( n , mod - 2 ) ;
    vl L ( a ) , R ( b ) , out ( n ) ;
    L.resize ( n ) , R.resize ( n ) ;
    ntt ( L ) , ntt ( R ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        out[ -i & ( n - 1 ) ] = (ll)L[ i ] * R[ i ] % mod * inv % mod ;
    }
    ntt ( out ) ;
    return { out.begin ( ) , out.begin ( ) + s } ;
}

const int MAXN = 3e6 + 7 ;

int n ;
int cnt[ MAXN ] ;

vl vecs[ MAXN ] ;

set < pair < int , int > > s ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 , x ; i <= n ; ++ i ) {
        cin >> x ;
        ++ cnt[ x ] ;
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        if ( cnt[ i ] > 0 ) {
            vecs[ i ] = vl ( cnt[ i ] + 1 , 1 ) ;
            s.insert ( { cnt[ i ] + 1 , i } ) ;
        }
    }
    while ( s.size ( ) > 1 ) {
        auto p1 = *s.begin ( ) ;
        s.erase ( s.begin ( ) ) ;
        auto p2 = *s.begin ( ) ;
        s.erase ( s.begin ( ) ) ;
        vecs[ p1.second ] = conv ( vecs[ p1.second ] , vecs[ p2.second ] ) ;
        s.insert ( { vecs[ p1.second ].size ( ) , p1.second } ) ;
    }
    int wh = ( *s.begin ( ) ).second ;
    cout << vecs[ wh ][ n / 2 ] << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}