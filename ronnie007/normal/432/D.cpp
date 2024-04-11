#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int n ;
string a ;
int PI[ 100007 ] ;
int used[ 100007 ] ;
map < int , int > m ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i ;
    int l = 0 ;
    int k ;
    PI[ 0 ] = 0 ;
    PI[ 1 ] = 0 ;
    m[ n ] = 1 ;
    for ( i = 2 ; i <= n ; i ++ ) {
        k = l ;
        while ( l != 0 ) {
            if ( a[ i - 1 ] == a[ l ] ) {
                break ;
            }
            l = PI[ l ] ;
        }

        if ( a[ i - 1 ] == a[ l ] ) l ++ ;
        PI[ i ] = l ;
        m[ l ] ++ ;

    }
    for ( i = 100002 ; i >= 0 ; i -- ) {
        m[ PI[ i ] ] += m[ i ] ;
    }
    l = PI[ n ] ;
    while ( l != 0 ) {
        used[ l ] = 1 ;
        l = PI[ l ] ;
    }
    /**
    for ( i = 0 ; i <= n ; i ++ ) {
        printf ( "i = %d PI[ i ] = %d\n" , i , PI[ i ] ) ;
    }**/

    vector < pair < int , int > > v ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( m[ i ] != 0 && used[ i ] == 1 ) {
            v.push_back ( make_pair ( i , m[ i ] ) ) ;
        }
    }
    v.push_back ( make_pair ( n , 1 ) ) ;
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}