#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n , m ;
int a[ 100007 ] ;
long long ans = 0 ;


vector < int > gr[ 100007 ] ;
int ind[ 100007 ] ;



struct tuhla {
    int x , y  ;
    long long c ;
};

vector < struct tuhla > v ;

bool f ( struct tuhla p1 , struct tuhla p2 ) {
    return ( p1.c > p2.c ) ;
}

void merge ( int i , int j ) {
    int sz1 = gr[ i ].size ( ) ;
    int sz2 = gr[ j ].size ( ) ;

    if(sz2 > sz1) i ^= j ^= i ^= j;

    while ( !gr[ j ].empty ( ) )  {
        int l = gr[ j ].back ( ) ;
        gr[ j ].pop_back ( ) ;

        ind[l] = i;
        gr[i].push_back( l );
    }
}


void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    v.resize ( m ) ;
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d%d" , &v[ i ].x , &v[ i ].y ) ;
        v[ i ].c = min ( a[ v[ i ].x ] , a[ v[ i ].y ]) ;
    }
}


void solve ( )  {
    sort ( v.begin ( ) , v.end ( ) , f ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        gr[ i ].push_back ( i ) ;
        ind[ i ] = i ;
    }
    for ( i = 0 ; i < m ; i ++ ) {
        int x = v[ i ].x;
        int y = v[ i ].y;

        int idx1 = ind[ x ] ;
        int idx2 = ind[ y ] ;

        if ( idx1 == idx2 ) continue ;

        ans += ( 2LL * v[ i ].c * gr[ idx1 ].size ( ) * gr[ idx2 ].size ( ) ) ;

        merge ( idx1, idx2 ) ;
    }

    cout.precision(6);
    cout << fixed << ((long double)ans / (long double)n) / (long double)(n - 1) << "\n" ;
}