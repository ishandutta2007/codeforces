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

int n ;
int a[ 100007 ] ;
int l[ 100007 ] ;
int r[ 100007 ] ;
int ans = 0 ;


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
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    if ( n <= 2 ) {
        printf ( "%d\n" , n ) ;
        return ;
    }
    l[ 1 ] = 1 ;
    for ( i = 2 ; i <= n ; i ++ ) {
        if ( a[ i ] > a[ i - 1 ] ) l[ i ] = l[ i - 1 ] + 1 ;
        else l[ i ] = 1 ;
    }
    r[ n ] = 1 ;
    for ( i = n - 1 ; i >= 1 ; i -- ) {
        if ( a[ i ] < a[ i + 1 ] ) r[ i ] = r[ i + 1 ] + 1 ;
        else r[ i ] = 1 ;
    }
    int ans = 0 ;
    for ( i = 2 ; i <= n - 1 ; i ++ ) {
        ans = max ( ans , l[ i ] + 1 ) ;
        ans = max ( ans , r[ i ] + 1 ) ;
        if ( a[ i - 1 ] + 1 < a[ i + 1 ] ) {
            ans = max ( ans , l[ i - 1 ] + r[ i + 1 ] + 1 ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
}