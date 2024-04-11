#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n ;
int a[ 307 ] ;
int s ;

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
    scanf ( "%d" , &n ) ;
    int i ;
    s = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        s += a[ i ] ;
        }
    }


void solve()
    {
    int x ;
    x = 0 ;
    int lst = -1 ;
    while ( s > 0 )
        {
        if ( a[ x ] == 0 )
            {
            x ++ ;
            cout << "R" ;
            continue ;
            }
        if ( lst != 1 )
            {
            a[ x ] -- ;
            s -- ;
            cout << "P" ;
            lst = 1 ;
            }
        else
            {
            if ( x == 0 )
                {
                cout << "RL" ;
                }
            else cout << "LR" ;
            lst = -1 ;
            }
        }
    }