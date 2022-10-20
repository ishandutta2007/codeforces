#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;


int a , b ;

void input ( ) ;
void solve ( ) ;


int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0;
    }


void input ( )
    {
    scanf ( "%d%d" , &a , &b ) ;
    }

void solve ( )
    {
    int ans = 0 ;
    int br = a ;
    int out = 0 ;
    int o ;
    while ( br >= b  )
        {
        ans += ( br - br%b );
        br = ( br % b + br / b ) ;
        }
    ans += br ;
    printf ( "%d\n" , ans ) ;
    }