#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MOD 998244353

long long n , m ;
long long cnt_even , cnt_odd ;

vector < vector < long long > > v ;

vector < vector < long long > > mul ( vector < vector < long long > > p1 , vector < vector < long long > > p2 ) {
    vector < vector < long long > > ret ;
    ret.resize ( 2 ) ;
    ret[ 0 ].resize ( 2 ) ;
    ret[ 1 ].resize ( 2 ) ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            ret[ i ][ j ] = 0 ;
        }
    }
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                ret[ i ][ j ] += p1[ i ][ t ] * p2[ t ][ j ] ;
                ret[ i ][ j ] %= MOD ;
            }
        }
    }
    return ret ;
}

vector < vector < long long > > fastpow ( vector < vector < long long > > x , long long pw ) {
    vector < vector < long long > > ret ;
    ret.resize ( 2 ) ;
    ret[ 0 ].resize ( 2 ) ;
    ret[ 1 ].resize ( 2 ) ;
    ret[ 0 ][ 0 ] = ret[ 1 ][ 1 ] = 1 ;
    ret[ 1 ][ 0 ] = ret[ 0 ][ 1 ] = 0 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = mul ( x , x ) ;
            pw /= 2 ;
        }
        else {
            ret = mul ( ret , x ) ;
            -- pw ;
        }
    }
    return ret ;
}

void input ( ) {
    long long st , en ;
    cin >> n >> m ;
    cin >> st >> en ;
    cnt_even = ( en / 2 ) - ( ( st - 1 ) / 2 ) ;
    cnt_odd = ( ( en - st + 1 ) - cnt_even ) ;
}

void solve ( ) {
    v.resize ( 2 ) ;
    v[ 0 ].push_back ( cnt_even ) ;
    v[ 0 ].push_back ( cnt_odd ) ;

    v[ 1 ].push_back ( cnt_odd ) ;
    v[ 1 ].push_back ( cnt_even ) ;

    vector < vector < long long > > aux = fastpow ( v , n * m ) ;
    if ( ( ( n * m ) % 2 ) == 0 ) {
        cout << aux[ 0 ][ 0 ] << "\n" ;
    }
    else {
        cout << ( aux[ 0 ][ 0 ] + aux[ 0 ][ 1 ] ) % MOD << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}