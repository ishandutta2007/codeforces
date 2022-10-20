#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

int n ;
long long a ;
string s ;

long long pr[ 4007 ] ;
long long  used[ 40007 ] ;

void input ( ) ;
void solve ( ) ;

int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }



void input ( )
    {
    cin >> a ;
    cin >> s ;
    n = s.size ( ) ;
    }

void solve ( )
    {
    int i , j ;
    long long ans = 0 ;
    long long p = 0 ;
    pr[ 0 ] = 0 ;

    for ( i = 1 ; i <= n ; i ++ )
        {
        pr[ i ] = pr[ i - 1 ] + ( s[ i - 1 ] - '0' ) ;
        }
    for ( i = 0 ; i <= n ; i ++ )
        {
        for ( j = i + 1 ; j <= n ; j ++ )
            {
            used[ pr[ j ] - pr[ i ] ] ++ ;
            p ++ ;
            }
        }

    long long x ;
    ///cout << p << "\n" ;
    for ( i = 0 ; i <= n ; i ++ )
        {
        for ( j = i + 1 ; j <= n ; j ++ )
            {
            x = pr[ j ] - pr[ i ] ;
            if ( x != 0 )
                {
                if (  a % x == 0 && pr[ n ] >= a / x ) ans += used[ a / x ] ;
                }
            else
                {
                if ( a == 0 )
                    {
                    ans += p ;
                    }
                }
            }
        }
    cout << ans << "\n" ;
    }