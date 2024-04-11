#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std ;

#define MAXN 27

int n ;
struct tuhla {
    string name ;
    int len ;
    vector < string > v ;
};
tuhla aux[ MAXN ] ;
tuhla a[ MAXN ] ;

bool cmp ( tuhla p1 , tuhla p2 ) {
    return ( p1.name < p2.name ) ;
}

bool cmpstr ( string p1 , string p2 ) {
    return ( p1.size ( ) < p2.size ( ) ) ;
}

bool f ( string p1 , string p2 ) {
    int sz = p1.size ( ) ;
    int g = p2.size ( ) ;
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( p1[ sz - i - 1 ] != p2[ g - i - 1 ] ) { return false ; }
    }
    return true ;
}

void input ( ) {
    cin >> n ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> aux[ i ].name ;
        cin >> aux[ i ].len ;
        aux[ i ].v.resize ( aux[ i ].len ) ;
        for ( j = 0 ; j < aux[ i ].len ; j ++ ) {
            cin >> aux[ i ].v[ j ] ;
        }
    }
    sort ( aux + 1 , aux + n + 1 , cmp ) ;
    int nw = 1 ;
    a[ 1 ] = aux[ 1 ] ;
    for ( i = 2 ; i <= n ; i ++ ) {
        if ( aux[ i ].name == aux[ i - 1 ].name ) {
            for ( j = 0 ; j < aux[ i ].len ; j ++ ) {
                a[ nw ].v.push_back ( aux[ i ].v[ j ] ) ;
                a[ nw ].len ++ ;
            }
        }
        else {
            nw ++ ;
            a[ nw ] = aux[ i ] ;
        }
    }
    n = nw ;
}

void solve ( ) {
    cout << n << "\n" ;
    int i , j , t , z ;
    for ( i = 1 ; i <= n ; i ++ ) {
        sort ( a[ i ].v.begin ( ) , a[ i ].v.end ( ) , cmpstr ) ;
        vector < int > ans ;
        for ( j = a[ i ].len - 1 ; j >= 0 ; j -- ) {
            for ( t = ( j + 1 ) ; t < a[ i ].len ; t ++ ) {
                if ( f ( a[ i ].v[ j ] , a[ i ].v[ t ] ) == true ) {
                    break ;
                }
            }
            if ( t >= a[ i ].len ) { ans.push_back ( j ) ; }
        }
        if ( ans.size ( ) > 0 ) {
            int h = ans.size ( ) ;
            cout << a[ i ].name << " " << h ;
            for ( j = 0 ; j < h ; j ++ ) {
                cout << " " << a[ i ].v[ ans[ j ] ] ;
            }
            cout << "\n" ;
        }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}