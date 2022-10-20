#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n , m , k ;
int ans = 0 ;

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
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    int x ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        if ( x == 1 )
            {
            if ( m == 0 ) ans ++ ;
            m -- ;
            if ( m < 0 ) m = 0 ;
            }
        else
            {
            if ( k != 0 )
                {
                k -- ;
                }
            else
                {
                if ( m != 0 ) m -- ;
                else
                    {
                    ans ++ ;
                    }
                }
            }
        }
    }

void solve()
    {
    printf ( "%d\n" , ans ) ;
    }