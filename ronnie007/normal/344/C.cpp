#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

long long a , b ;

void input ( ) ;
void solve ( ) ;

int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf ( "%I64d%I64d" , &a , &b ) ;
    }

void solve ( )
    {
    long long ans = 0 ;
    ///ans = d * ( b ) ;
    ///if ( ans > ( b - d ) * ( b ) ) ans = ( b - d ) * ( b ) ;
    ///if ( b != 1 ) d ++ ;
    while ( a != 0 && b != 0 )
        {
        if ( a >= b )
            {
            ans += a / b ;
            a = a % b ;
            }
        else if ( b > a )
            {
            ans += b / a ;
            b = b % a ;
            }
        }
    printf ( "%I64d\n" , ans  ) ;
    }