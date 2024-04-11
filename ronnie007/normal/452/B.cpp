#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std;

int n , m ;

vector < pair < int , int > > v ;
set < pair < int , int > > s ;

pair < int , int > ans[ 7 ] ;

long long best ;
long long cur ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> n >> m ;
    s.insert ( make_pair ( 0 , 0 ) ) ;
    s.insert ( make_pair ( 0 , m ) ) ;
    s.insert ( make_pair ( n , 0 ) ) ;
    s.insert ( make_pair ( n , m ) ) ;


    s.insert ( make_pair ( 1 , 0 ) ) ;
    s.insert ( make_pair ( 0 , 1 ) ) ;

    s.insert ( make_pair ( n - 1 , 0 ) ) ;
    s.insert ( make_pair ( n , 1 ) ) ;

    s.insert ( make_pair ( n , m - 1 ) ) ;
    s.insert ( make_pair ( n - 1 , m ) ) ;


    s.insert ( make_pair ( 1 , m ) ) ;
    s.insert ( make_pair ( 0 , m - 1 ) ) ;

}


void solve ( )  {
    set < pair < int , int > > ::iterator q ;
    pair < int , int > p ;
    for ( q = s.begin ( ) ; q != s.end ( ) ; q ++ ) {
        p = *q ;
        if ( p.first >= 0 && p.first <= n && p.second >= 0 && p.second <= m ) {
            v.push_back ( p ) ;
        }
    }
    int i , j , t , z ;
    int sz = v.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        for ( j = 0 ; j < sz ; j ++ ) {
            for ( t = 0 ; t < sz ; t ++ ) {
                for ( z = 0 ; z < sz ; z ++ ) {
                    if ( i == j || i == t || i == z ) continue ;
                    if ( j == t || j == z ) continue ;
                    if ( t == z ) continue ;
                    cur = 0 ;
                    cur += ( v[ i ].first - v[ j ].first ) * ( v[ i ].first - v[ j ].first ) + ( v[ i ].second - v[ j ].second ) * ( v[ i ].second - v[ j ].second ) ;
                    cur += ( v[ t ].first - v[ j ].first ) * ( v[ t ].first - v[ j ].first ) + ( v[ t ].second - v[ j ].second ) * ( v[ t ].second - v[ j ].second ) ;
                    cur += ( v[ t ].first - v[ z ].first ) * ( v[ t ].first - v[ z ].first ) + ( v[ t ].second - v[ z ].second ) * ( v[ t ].second - v[ z ].second ) ;
                    if ( best < cur ) {
                        best = cur ;
                        ans[ 0 ] = v[ i ] ;
                        ans[ 1 ] = v[ j ] ;
                        ans[ 2 ] = v[ t ] ;
                        ans[ 3 ] = v[ z ] ;
                    }
                }
            }
        }
    }
    for ( i = 0 ; i < 4 ; i ++ ) {
        cout << ans[ i ].first << " " << ans[ i ].second << "\n" ;
    }
}