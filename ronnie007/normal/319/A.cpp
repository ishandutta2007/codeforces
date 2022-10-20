#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

#define MOD 1000000007

string a ;
int ans = 0 ;


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
    }

void solve ( )
    {
    int n = a.size ( ) ;
    int i , j ;
    int p ;
    int br = 0 ;
    for ( i = n - 1 ; i >= 0 ; i -- )
        {
        if ( a[ i ] == '0' )
            {
            ans = ( ans * 2 ) % MOD ;
            }
        else
            {
            ans = ( ans * 2 ) % MOD ;
            p = 1 ;
            for ( j = 0 ; j < 2 * br ; j ++ )
                {
                p = ( p * 2 ) % MOD ;
                }
            ans = ( ans + p ) % MOD ;
            }
        br ++ ;
        }
    printf ( "%d\n" , ans ) ;
    }