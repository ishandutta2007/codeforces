#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;


vector < long long > w ;
char a[ 7 ] ;

long long mn = -1 ;

void input ( ) ;
void solve ( ) ;

void rec ( vector < long long > v , int ind ) {
    int n = v.size ( ) ;
    int i , j , t  ;
    vector < long long  > u ;
    if ( n == 1 ) {
        if ( mn == -1 || mn > v[ 0 ] ) mn = v[ 0 ] ;
        return ;
    }
    for ( i = 0 ; i < n - 1 ; i ++ ) {
        for ( j = i + 1 ; j < n ; j ++ ) {
            u.clear ( ) ;
            if ( a[ ind ] == '+' ) u.push_back ( v[ i ] + v[ j ] ) ;
            else u.push_back ( v[ i ] * v[ j ] ) ;
            for ( t = 0 ; t < n ; t ++ ) {
                if ( t != i && t != j ) u.push_back ( v[ t ] ) ;
            }
            rec ( u , ind + 1 ) ;
        }
    }
}

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    w.resize ( 4 ) ;
    int i ;
    for ( i = 0 ; i < 4 ; i ++ ) {
        cin >> w[ i ] ;
    }
    for ( i = 0 ; i < 3 ; i ++ ) {
        cin >> a[ i ] ; 
    }
}

void solve ( )  {
    rec ( w , 0 ) ;
    cout << mn << "\n" ;
}