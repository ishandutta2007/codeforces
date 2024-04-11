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
string a ;

string w[ 8 ] = { "vaporeon" , "jolteon" , "flareon" , "espeon" , "umbreon" , "leafeon" , "glaceon" , "sylveon" } ;

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
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int i , j ;
    int sz ;
    for ( i = 0 ; i < 8 ; i ++ ) {
        sz = w[ i ].size ( ) ;
        if ( sz == n ) {
            for ( j = 0 ; j < n ; j ++ ) {
                if ( a[ j ] == '.' ) continue ;
                if ( a[ j ] != w[ i ][ j ] ) break ;
            }
            if ( j == n ) { cout << w[ i ] ; return ; }
        }
    }
}