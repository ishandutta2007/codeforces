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

#define MAXN 27

int n , m ;
string a[ MAXN ] ;
string b[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 0 ; i < m ; ++ i ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    int q ;
    cin >> q ;
    while ( q -- ) {
        int x ;
        cin >> x ;
        -- x ;
        cout << a[ ( x % n ) ] << b[ ( x % m ) ] << "\n" ;
    }
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}