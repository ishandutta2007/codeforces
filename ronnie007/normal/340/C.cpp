#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


#define ABS(x)(((x)>0)?(x):-(x))

long long n ;
long long a[ 100007 ] ;
long long totaldist ;

void input ( );
void solve ( );




int main()
    {
    input ( );
    solve ( );
    return 0 ;
    }


void input ( )
    {
    scanf ( "%I64d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%I64d" , &a[ i ] ) ;
        totaldist += a[ i ] ;
        }
    sort ( a , a + n ) ;
    }

void solve ( )
    {
    int i ;
    long long ans = 0 ;
    long long q = 0 ;
    long long sum = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        ans = ans + a[ i ] ;
        ans = ans + ( ( i*a[ i ] - sum ) + ( totaldist - sum - a[ i ] ) - ( n - i - 1 )* a[ i ]  );
        sum += a[ i ] ;
        ///printf ( "%I64d\n" , ans ) ;
        }
    long long u = __gcd( ans , n ) ;
    printf ( "%I64d %I64d\n" , ans / u , n / u ) ;

//  for ( i = 1 ; i <= n ; i ++ )
    //  {
        //}
    }