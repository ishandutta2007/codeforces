#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;


typedef long long ll ;

ll n ;

ll ans1 = -1 ;
ll ans2 = -1 ;

void tr ( ll a , ll b , ll c )
    {
    ll p = ( a + 2 ) * ( b + 2 ) * ( c + 1 ) ;
    if ( ans1 == -1 || p < ans1 )
        {
        ans1 = p ;
        }
    if ( ans2 == -1 || p > ans2 )
        {
        ans2 = p ;
        }
    }




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
    scanf ( "%I64d" , &n ) ;
    }

void solve ( )
    {
    ll i , j , t ;
    for ( i = 1 ; i * i * i <= n ; i ++ )
        {
        for ( j = i ; j * j * i <= n ; j ++ )
            {
            if ( n % ( i * j ) != 0 ) continue ;
            t = n / ( i * j ) ;
            tr ( i , j , t );
            tr ( i , t , j );
            tr ( j , t , i );
            }
        }
    printf ( "%I64d %I64d\n" , ans1 - n , ans2 - n ) ;
    }