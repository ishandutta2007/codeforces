#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


#define MOD 1000000007

int n ;
long long k , N ;
int a[ 2007 ] ;
long long dp[ 2007 ][ 2007 ] ;
int used[ 2007 ] ;
int posused[ 2007 ] ;
long long fact[ 2007 ] ;





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
    scanf ( "%d" , &n ) ;
    N = n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        used[ a[ i ] ] = true ;
        if ( a[ i ] != -1 ) N -- ;
        }

    k = 0 ;

    for ( i = 1 ; i <= n ; i ++ )
        {
        if ( a[ i ] == -1 && !used[ i ] ) k ++ ;
        }
    }


void solve ( )
    {
    int i , j ;
    fact[ 1 ] = 1 ;
    for ( i = 2 ; i < 2001 ; i ++ )
        {
        fact[ i ] = ( fact[ i - 1 ] * i ) % MOD ;
        }


    dp[ 1 ][ 0 ] = 1 ;
    dp[ 1 ][ 1 ] = 0 ;

    for ( i = 2 ; i <= n ; i ++ )
        {
        dp[ i ][ 0 ] = fact[ i ] ;
        dp[ i ][ 1 ] = ( dp[ i - 1 ][ 0 ] * ( i - 1 ) ) % MOD;
        for (j=2;j<=i;j++)
            {
            dp[i][j]=( ( dp[i-1][j-1]*(i-j) ) + ( dp[i-1][j-2]*(j-1) ) )%MOD;
            }
        }

    printf("%I64d\n",dp[N][k]);
    }