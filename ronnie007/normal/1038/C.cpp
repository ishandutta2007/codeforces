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
int a[ MAXN ] ;
int b[ MAXN ] ;

long long ans ;

priority_queue < pair < int , int > > q ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        q.push ( make_pair ( a[ i ] , 1 ) ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        q.push ( make_pair ( b[ i ] , 2 ) ) ;
    }
}

void solve ( ) {
    int id = 1 ;
    while ( q.empty ( ) == false ) {
        pair < int , int > cur = q.top ( ) ;
        q.pop ( ) ;
        if ( cur.second == id ) {
            if ( id == 1 ) { ans += cur.first ; }
            else { ans -= cur.first ; }
        }
        id = ( 3 - id ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}