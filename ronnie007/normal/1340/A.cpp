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
int pos[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    int st = 1 ;
    int en = n ;
    while ( st <= n ) {
        int aux = pos[ st ] ;
        for ( int i = aux + 1 ; i <= en ; ++ i ) {
            if ( a[ i ] - a[ i - 1 ] != 1 ) {
                printf ( "No\n" ) ;
                return ;
            }
        }
        st = a[ en ] + 1 ;
        en = aux - 1 ;
    }
    if ( en != 0 ) {
        printf ( "No\n" ) ;
        return ;
    }
    printf ( "Yes\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}