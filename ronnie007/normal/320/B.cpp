#include<iostream>
#include<stdio.h>
using namespace std;

void input();

int n;
int a[ 107 ][ 107 ];
int used[ 107 ];
int x[ 107 ];
int y[ 107 ];
int sz=0;

void dfs ( int vertex )
    {
    int i;
    used[ vertex ] =1;
    for ( i = 0 ; i <= sz; i ++ )
        {
        if ( a[ vertex ][ i ] == 1 && used[ i ] == 0 ) dfs ( i );
        }
    }

int main()
    {
    input();
    return 0;
    }


void input()
    {
    int i,j,t;
    int k;
    scanf("%d",&n);
    int s,e;
    for ( i = 0 ; i < n; i ++ )
        {
        scanf("%d",&k);
        if ( k == 1 )
            {
            scanf("%d%d",&x[ sz ],&y[ sz ]);
            for ( j = sz - 1 ;j >= 0 ; j--)
                {
                if ( ( x[ sz ] > x[ j ] && x[ sz ] < y[ j ] ) || ( y[ sz ] > x[ j ] && y[ sz ] < y[ j ] ) )
                    {
                    a[ sz ][ j ] = 1;
                    }
                }
            for ( j = sz - 1 ;j >= 0 ; j--)
                {
                if ( ( x[ j ] > x[ sz ] && x[ j ] < y[ sz ] ) || ( y[ j ] > x[ sz ] && y[ j ] < y[ sz ] ) )
                    {
                    a[ j ][ sz ] = 1;
                    }
                }
            sz ++;
            }
        else
            {
            scanf("%d%d",&s,&e);
            s--;
            e--;
            for ( j = 0 ; j <= sz ; j ++ )
                {
                used[ j ] = 0;
                }
            dfs( s );
            if ( used[ e ] == 1 ) printf("YES\n");
            else printf("NO\n");
            }
        }
    }