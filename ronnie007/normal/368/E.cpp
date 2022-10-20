#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;



long long n , m ;
long long a[ 2000007 ] ;





void input ( ) ;
void solve ( ) ;


int main()
    {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0;
    }


void input ( )
    {
    scanf ( "%I64d%I64d" , &n , &m ) ;
    int i ;
    int x ;
    for ( i = 1 ; i <= m ; i ++ )
        {
        scanf ( "%d%I64d" , &x , &a[ i ] ) ;
        }
    sort ( a + 1 , a + m + 1 ) ;
    reverse ( a + 1 , a + m + 1 ) ;
    }


void solve ( )
    {
    long long i , c ;
    long long ans = 0 ;
    for ( i = 1 ; i <= m ; i ++ )
        {
        c = i * ( i - 1 ) / 2 ;
        if ( i % 2 == 0 ) c += i / 2 ;
        else c ++ ;
        if ( c <= n ) ans += a[ i ] ;
        }
    printf ( "%I64d\n" , ans ) ;
    }