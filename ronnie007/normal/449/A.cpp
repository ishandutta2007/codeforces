#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std;

long long n , m , k ;


void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    ///scanf ( "%d%d%d" , &n , &m , &k ) ;
    cin >> n >> m >> k ;
}

void solve ( ) {
    if ( k > n - 1 + m - 1 ) {
        cout << "-1\n" ;
    }
    else if ( k < max ( n , m ) ) {
        cout << max ( n / ( k + 1 ) * m , m / ( k + 1 ) * n ) << endl ;
    }
    else{
        cout << max ( m / ( k - n + 2 ) , n / ( k - m + 2 ) ) << endl ;
    }
}