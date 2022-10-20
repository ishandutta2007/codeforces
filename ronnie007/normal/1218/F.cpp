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

#define MAXN 100007

int n ;
long long st ;
pair < long long , long long > a[ MAXN ] ;
long long add ;

void input ( ) {
    cin >> n >> st ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first ;
    }
    cin >> add ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].second ;
    }
}

void solve ( ) {
    priority_queue < long long > q ;
    while ( q.empty ( ) == false ) { q.pop ( ) ; }
    long long cost = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        q.push ( - a[ i ].second ) ;
        while ( q.empty ( ) == false && st < a[ i ].first ) {
            cost -= q.top ( ) ;
            st += add ;
            q.pop ( ) ;
        }
        if ( st < a[ i ].first ) { cout << "-1\n" ; return ; }
    }
    cout << cost << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}