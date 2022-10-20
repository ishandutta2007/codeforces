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
    scanf ( "%d" , &n ) ;
    }

void solve()
    {
    int x ;
    if ( n == 0 ) printf ( "O-|-OOOO\n" ) ;
    while ( n != 0 )
        {
        x = n % 10 ;
        if ( x == 0 ) printf ( "O-|-OOOO\n" ) ;
        if ( x == 1 ) printf ( "O-|O-OOO\n" ) ;
        if ( x == 2 ) printf ( "O-|OO-OO\n" ) ;
        if ( x == 3 ) printf ( "O-|OOO-O\n" ) ;
        if ( x == 4 ) printf ( "O-|OOOO-\n" ) ;
        if ( x == 5 ) printf ( "-O|-OOOO\n" ) ;
        if ( x == 6 ) printf ( "-O|O-OOO\n" ) ;
        if ( x == 7 ) printf ( "-O|OO-OO\n" ) ;
        if ( x == 8 ) printf ( "-O|OOO-O\n" ) ;
        if ( x == 9 ) printf ( "-O|OOOO-\n" ) ;
        n = n / 10 ;
        }
    }