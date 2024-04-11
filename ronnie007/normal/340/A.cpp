#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;


int x , y , a , b ;

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
    scanf ( "%d%d%d%d" , &x , &y , &a , &b ) ;
    }

void solve()
    {
    int nok = ( x * y ) / ( __gcd( x , y ) ) ;
    int k = b / nok ;
    k -= ( a - 1 ) / nok ;
    printf ( "%d\n" , k ) ;
    }