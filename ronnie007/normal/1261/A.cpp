#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

int n , k ;
string a ;
string cmp ;
vector < pair < int , int > > v ;

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
    a = '#' + a ;
}

void solve ( ) {
    v.clear ( ) ;
    cmp = "#" ;
    for ( int i = 0 ; i < k - 1 ; ++ i ) {
        cmp += "()" ;
    }
    int h = n - ((k-1)<<1) ;
    for ( int i = 1 ; i <= h ; ++ i ) {
        if ( (i<<1) <= h ) { cmp += '(' ; }
        else { cmp += ')' ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] != cmp[ i ] ) {
            for ( int j = i + 1 ; j <= n ; ++ j ) {
                if ( a[ j ] == cmp[ i ] ) {
                    v.push_back ( { i , j } ) ;
                    for ( int t = 0 ; t < ( ( j - i + 1 ) >> 1 ) ; ++ t ) {
                        swap ( a[ i + t ] , a[ j - t ] ) ;
                    }
                    break ;
                }
            }
        }
    }
    int sz = v.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << v[ i ].first << " " << v[ i ].second << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}