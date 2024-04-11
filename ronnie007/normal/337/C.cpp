#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;


#define MOD 1000000009


long long n , m , k ;
long long ans ;


void input();
void solve();
void f ( )
    {
    long long a = 2 ;
    long long b = n  + 1 ;
    long long r = 1 ;
    while ( b != 0 )
        {
        if ( b % 2 == 0 )
            {
            a = a * a % MOD ;
            b = b / 2 ;
            }
        else
            {
            r = r * a % MOD ;
            b -- ;
            }
        }
    ///if ( r == 1 )
        ///{
        ///ans  =  ans + r * k * 2 ;
        ///return ;
        ///}
    r = r % MOD ;
    r = ( r + MOD - 2 ) % MOD ;
    ///cout << r << "\n" ;
    r = r * k % MOD ;
    ///cout << r << "\n" ;
    ans = ans + r ;
    }



int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf ( "%I64d%I64d%I64d",&n,&m,&k);
    }


void solve()
    {

    int h ;
    m = m - n % k ;
    ans = ans + n % k ;
    n = n / k ;
    h = n * k - m ;
    ///cout << n << " " << h << "\n" ;
    if ( h >= n )
        {
        n = 0 ;
        ans = ( ans + m ) % MOD ;
        }
    else
        {
        ans = ( ans + h * ( k - 1 )% MOD  ) % MOD  ;
        n = n - h ;
        f ( ) ;
        }

    printf ( "%I64d\n" , ans % MOD ) ;
    }