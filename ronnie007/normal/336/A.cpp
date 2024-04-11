#include<iostream>
#include<stdio.h>
using namespace std;

int x , y;

void input();
void solve();

int main( )
    {
    input();
    solve();
    return 0;
    }

void input()
    {
    scanf ( "%d%d" , &x , &y ) ;
    }

void solve()
    {
    if ( x > 0 && y > 0 ) cout << "0 " << x+y << " " << x+y << " 0" << endl;
    else if ( x < 0 && y > 0 ) cout << x-y << " 0 0 " << y-x << endl;
    else if ( x > 0 && y < 0 ) cout << "0 " << y-x << " " << x-y << " 0" << endl;
    else if ( x < 0 && y < 0 ) cout << x+y << " 0 0 " << x+y << endl;
    }