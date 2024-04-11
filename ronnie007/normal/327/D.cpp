#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n , m ;
string a[ 507 ];
int used[ 507 ][ 507 ];

struct tuhla
    {
    char cm;
    int g , h;
    };
vector < struct tuhla > v;

void input();
void solve();
void DFS ( int x , int y  , int k );




int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    cin >> n >> m ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        cin >> a[ i ];
        }
    }


void solve()
    {
    int i ;
    int j ;
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( a[ i ][ j ] == '.' && used[ i ] [ j ] == 0 )
                {
                DFS ( i , j , -1);
                }
            }
        }
    printf ( "%d\n",v.size( ));
    for ( i = 0 ; i < v.size( ) ; i ++ )
        {
        cout << v[ i ].cm << " " << v[ i ].g + 1<< " " << v[ i ].h + 1<< "\n";
        }
    }



void DFS ( int x , int y , int k )
    {
    struct tuhla p;
    p.cm = 'B';
    p.g = x;
    p.h = y;
    v.push_back ( p );
    used[ x ][ y ] = 1 ;
    if ( x > 0 )
        {
        if ( used[ x - 1 ][ y ] == 0 && a[ x - 1 ][ y ] == '.' ) DFS ( x - 1 , y , 1 );
        }
    if ( x + 1 < n )
        {
        if ( used[ x + 1 ][ y ] == 0 && a[ x + 1 ][ y ] == '.' ) DFS ( x + 1 , y, 1 );
        }
    if ( y > 0 )
        {
        if ( used[ x  ][ y - 1 ] == 0 && a[ x ][ y - 1 ] == '.' ) DFS ( x  , y - 1 , 1 );
        }
    if ( y + 1 < m  )
        {
        if ( used[ x ][ y + 1 ] == 0 && a[ x ][ y + 1 ] == '.' ) DFS ( x  , y + 1 , 1);
        }
    if ( k == -1 ) return ;
    p.cm = 'D';
    p.g = x;
    p.h = y;
    v.push_back ( p );

    p.cm = 'R';
    p.g = x;
    p.h = y;
    v.push_back ( p );
    }