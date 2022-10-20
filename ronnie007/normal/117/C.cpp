#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

int n;
vector < int > ans ;
char a[ 5007 ][ 5007 ];
int used1[ 5007 ];
int used[ 5007 ];
int pos [ 5007 ];
int stk [ 5007 ] ;
int k;




int dfs ( int vertex )
    {
    int i, j;
    used[ vertex ] = 1;
    used1[ vertex ] = 1;
    stk [ k ] = vertex ;
    pos [ vertex ] = k ;
    k++;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( i == vertex ) continue ;
        if ( a [ vertex ] [ i ] == '0' ) continue ;
        if ( used[  i  ] == 1 )
            {
            ans.clear ( );
            for ( j = pos [ i ] ; j < k ; j ++ )
                {
                ans.push_back(stk[ j ] );
                }
            return 1;
            }
        if ( used1 [ i ] == 0 && dfs ( i ) == 1 ) return 1;
        }
    used [ vertex ] = 0 ;
    k--;
    return 0;
    }


int find_cycle ( )
    {
    int i;
    k=0;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( used1[ i ] == 0 )
            {
            if ( dfs ( i ) == 1 ) return 1;
            }
        }
    return 0;
    }

void solve ( )
    {
    if ( find_cycle( ) == 0 )
        {
        printf( "-1 \n" );
        return ;
        }
    int i , j ;
    int first;
    int second ;
    int third;
    first = ans[ 0 ];
    ///for ( i = 0 ; i < ans.size ( ) ; i ++ )
        ///{
        ///printf ( "%d \n" ,ans [ i ] ) ;
        ///}
    for ( i = 1 ;i < ans.size() - 1 ; i ++ )
        {
        second = ans [ i ];
        third = ans [ i + 1 ] ;
        if( a[ first ] [ second ] == '1' && a [ third ] [ first ] == '1' )
            {
            printf ( "%d %d %d\n " ,first + 1, second + 1 , third + 1 ) ;
            return ;
            }
        }
    printf (  "-1\n " );
    return ;
    }

int main()
    {
    int i,j;
    scanf("%d",&n);
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf("%s",&a[i]);
        }
    solve( ) ;
    return 0;
    }