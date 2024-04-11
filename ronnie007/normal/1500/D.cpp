#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 1501

int n , q ;
int a[ MAXN ][ MAXN ] ;
pair < int , int > f[ MAXN ][ MAXN ][ 11 ] ;
int ans[ MAXN ] ;
bool used[ MAXN * MAXN ] ;


stack < vector < pair < int , int > > > s1 , s2 ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}



void unite ( vector < pair < int , int > > &ret , vector < pair < int , int > > &x , vector < pair < int , int > > &y , int row ) {
    int pos1 = 0 , pos2 = 0 ;
    for ( int z = 0 ; z <= q ; ++ z ) {
        while ( pos1 <= q && used[ x[ pos1 ].second ] == true ) { ++ pos1 ; }
        while ( pos2 <= q && used[ y[ pos2 ].second ] == true ) { ++ pos2 ; }
        if ( pos1 <= q && pos2 <= q ) {
            if ( x[ pos1 ].first < y[ pos2 ].first ) {
                ret[ z ] = x[ pos1 ] ;
                if ( x[ pos1 ].second != 0 ) {
                    used[ x[ pos1 ].second ] = true ;
                }
                ++ pos1 ;
            }
            else {
                ret[ z ] = y[ pos2 ] ;
                if ( y[ pos2 ].second != 0 ) {
                    used[ y[ pos2 ].second ] = true ;
                }
                ++ pos2 ;
            }
        }
        else if ( pos1 <= q ) {
            ret[ z ] = x[ pos1 ] ;
            if ( x[ pos1 ].second != 0 ) {
                used[ x[ pos1 ].second ] = true ;
            }
            ++ pos1 ;
        }
        else {
            ret[ z ] = y[ pos2 ] ;
            if ( y[ pos2 ].second != 0 ) {
                used[ y[ pos2 ].second ] = true ;
            }
            ++ pos2 ;
        }
    }
    for ( auto [ fst , scd ] : ret ) {
        used[ scd ] = false ;
    }
}

void add ( vector < pair < int , int > > &aux , vector < pair < int , int > > &hh , int pos , int row ) {
    for ( int z = 0 ; z <= q ; ++ z ) {
        hh[ z ] = f[ row ][ pos ][ z ] ;
    }
    if ( s1.empty ( ) == false ) {
        unite ( aux , s1.top ( ) , hh , row ) ;
        s1.push ( aux ) ;
    }
    else { s1.push ( hh ) ; }
}

void rem ( int j , int len , vector < pair < int , int > > &aux , vector < pair < int , int > > &hh , int row ) {
    if ( s2.empty ( ) == false ) { s2.pop ( ) ; }
    else {
        while ( s1.empty ( ) == false ) {
            s1.pop ( ) ;
        }
        for ( int pos = j + len - 2 ; pos >= j ; -- pos ) {
            for ( int z = 0 ; z <= q ; ++ z ) {
                hh[ z ] = f[ row ][ pos ][ z ] ;
            }
            if ( s2.empty ( ) == false ) {
                unite ( aux , s2.top ( ) , hh , row ) ;
                s2.push ( aux ) ;
            }
            else { s2.push ( hh ) ; }
        }
    }
}



int extr ( vector < pair < int , int > > &hh , int row ) {
    int ret = MAXN ;
    if ( s1.empty ( ) == true ) { return ( s2.top ( ) )[ q ].first ; }
    if ( s2.empty ( ) == true ) { return ( s1.top ( ) )[ q ].first ; }
    unite ( hh , s1.top ( ) , s2.top ( ) , row ) ;
    return hh[ q ].first ;
}

void solve ( ) {
    for ( int j = 1 ; j <= n ; ++ j ) {
        for ( int i = n ; i >= 1 ; -- i ) {
            f[ i ][ j ][ 0 ] = { i , a[ i ][ j ] } ;
            int tp = 1 ;
            if ( i < n ) {
                for ( int z = 0 ; z <= q ; ++ z ) {
                    pair < int , int > wh = f[ i + 1 ][ j ][ z ] ;
                    if ( wh.first == 0 ) { wh.first = n + 1 ; }
                    if ( wh.second == a[ i ][ j ] ) { continue ; }
                    f[ i ][ j ][ tp ++ ] = wh ;
                }
            }
            while ( tp <= q ) {
                f[ i ][ j ][ tp ++ ].first = MAXN ; 
            }
        }
    }
    vector < pair < int , int > > aux ; aux.resize ( q + 1 ) ;
    vector < pair < int , int > > hh ; hh.resize ( q + 1 ) ;
    for ( int i = 0 ; i <= q ; ++ i ) {
        aux[ i ] = hh[ i ] = { 0 , 0 } ;
    }
    int len = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( s1.empty ( ) == false ) { s1.pop ( ) ; }
        while ( s2.empty ( ) == false ) { s2.pop ( ) ; }
        for ( int j = 1 ; j <= n ; ++ j ) {
            rem ( j , len , aux , hh , i ) ;
            if ( len > 0 ) { -- len ; }
            while ( j + len - 1 < n ) {
                add ( aux , hh , j + len , i ) ;
                ++ len ;
                if ( extr ( hh , i ) - i < len || i + len - 1 > n ) {
                    s1.pop ( ) ;
                    if ( len > 0 ) { -- len ; }
                    break ; 
                }
            }
            ++ ans[ len ] ;
        }
    }
    for ( int i = n - 1 ; i >= 1 ; -- i ) {
        ans[ i ] += ans[ i + 1 ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d\n" , ans[ i ] ) ;
    }
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