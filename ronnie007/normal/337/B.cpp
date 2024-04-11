#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;


int a , b ;
int p , q ;

void input();
void solve();
int NOD( int x , int y )
    {
    if ( y == 0 ) return x ;
    return NOD ( y , x %y ) ;
    }
int NOK( int x , int y )
    {
    int ans = NOD ( x , y ) ;
    return x * y / ans ;
    }



int main()
    {
    input();
    solve();
    return 0;
    }




void input()
    {
    scanf ( "%d%d%d%d" , &a, &b , &p , &q ) ;
    }


void solve()
    {
    int ans = NOK ( a , p ) ;
    ///cout << ans << "\n" ;
    int best1 = 0 , best2 = 0 ;
    int b1 = ( ans / a ) * b ;
    int q1 = ( ans / p ) * q ;
    ///cout << b1 << " " << q1 << "\n";
    if ( b1 >= q1 )
        {
        best1 = q1 ;
        best2 = b1 ;
        }



    ans = NOK ( b , q ) ;
    int a1 = ( ans / b ) * a ;
    int p1 = ( ans / q ) * p ;
    ///cout << a1 << " " << p1 << "\n";
    if ( a1 >= p1 && ( ( best1 == 0 && best2 == 0 ) || best2 * p1 < best1 * a1 ) )
        {
        best1 = p1 ;
        best2 = a1 ;
        }
    best1 = best2 - best1 ;
    ans = NOD ( best1 , best2 ) ;
    best1 = best1 / ans ;
    best2 = best2 / ans ;
    printf ( "%d/%d\n" , best1 , best2 ) ;
    }