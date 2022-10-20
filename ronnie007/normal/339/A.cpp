#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n ;
string a ;


void input();
void solve();


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    cin >> a ;
    n = a.size ( );
    }

void solve()
    {
    vector < int > v ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] =='1' || a[ i ] == '2' || a[ i ] == '3' ) v.push_back ( a[ i ] - '0' ) ;
        }
    sort ( v.begin ( ) , v.end ( ) ) ;
    for ( i = 0 ; i < v.size( ) - 1 ; i ++ )
        {
        printf ( "%d" , v[ i ] ) ;
        printf ( "+" );
        }
    printf ( "%d\n" , v[ v.size( ) - 1  ] ) ;
    }