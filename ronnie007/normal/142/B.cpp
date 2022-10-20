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
int ans ;

void input ( ) ;
void solve ( ) ;


int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0;
    }




void input()
    {
    scanf ( "%d%d" , &a , &b ) ;
    ans = ( a * b + 1 ) / 2 ;
    if ( ans < a ) ans = a ;
    if ( ans < b ) ans = b ;

    }


void solve()
    {
    int t ;
    if ( a >= 2 && b >= 2 )
        {
        t = ( max ( a , b ) / 4 ) * 4 ;
        if ( max ( a , b ) % 4 == 1 )
            {
            t += 2;
            }
        if ( max ( a , b ) % 4 > 1 )
            {
            t += 4;
            }
        if ( t > ans ) ans = t;
        }

    printf ( "%d\n" , ans ) ;
    }