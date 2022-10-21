#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;


#define MAXN 2000007

int n ;
string a[ MAXN ] ;
int sz[ MAXN ] ;
vector < int > v[ MAXN ] ;


pair < int , int > to_push[ MAXN ] ;

string ret ;

int mxpos ;

void input ( ) {
    cin >> n ;
    int i , j ;
    mxpos = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
        cin >> sz[ i ] ;
        v[ i ].resize ( sz[ i ] ) ;
        for ( j = 0 ; j < sz[ i ] ; j ++ ) {
            cin >> v[ i ][ j ] ;
            if ( mxpos < v[ i ][ j ] + a[ i ].size ( ) - 1 ) {
                mxpos = v[ i ][ j ] + a[ i ].size ( ) - 1 ;
            }
            if ( a[ i ].size ( ) > a[ to_push[ v[ i ][ j ] ].first ].size ( ) ) {
                to_push[ v[ i ][ j ] ] = make_pair ( i , 0 ) ;
            }
        }
    }
}

void solve ( ) {
    int i ;
    ret.clear ( ) ;
    for ( i = 0 ; i < mxpos ; i ++ ) {
        ret += "a" ;
    }
    for ( i = 0 ; i < mxpos ; i ++ ) {
        if ( to_push[ i + 1 ].first == 0 ) { continue ; }
        else {
            ret[ i ] = a[ to_push[ i + 1 ].first ][ to_push[ i + 1 ].second ] ;
            if ( to_push[ i + 1 ].second + 1 < a[ to_push[ i + 1 ].first ].size ( ) ) {
                if ( a[ to_push[ i + 1 ].first ].size ( ) - to_push[ i + 1 ].second > a[ to_push[ i + 2 ].first ].size ( ) ) {
                    to_push[ i + 2 ] = make_pair ( to_push[ i + 1 ].first , to_push[ i + 1 ].second + 1 ) ;
                }
            }
        }
    }
    cout << ret << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}