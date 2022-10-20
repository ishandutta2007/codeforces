#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string a[37];
int used[37];
int bestsz=0;
int best[37];
int n,m;

int v[37][37];


int noconflict()
    {
    int i, j;
    for ( i = 0 ; i < n; i ++ )
        {
        for ( j = i + 1 ; j < n; j ++ )
            {
            if ( v[ i ][ j ] == 1 && used[ i ] == 1 && used[ j ] == 1 ) return 0;
            }
        }
    return 1 ;
    }

void comp()
    {
    if ( noconflict( ) == 0 ) return ;
    int i;
    int br = 0;
    for ( i = 0 ;i < n; i ++ )
        {
        if ( used[ i ] == 1 ) br ++;
        }

    if ( bestsz < br )
        {
        bestsz = br;
        for ( i = 0 ;i < n; i ++ )
            {
            best[ i ] = used[ i ];
            }
        }
    }


void backtrack(int left)
    {
    if(left==n){comp();return ;}
    used[left]=1;
    backtrack(left+1);
    used[left]=0;
    backtrack(left+1);
    }

int main()
    {
    int i;
    string q,w;
    int ind1;
    int ind2;
    cin >> n >> m;
    for ( i = 0 ; i < n ; i++ )
        {
        cin >> a[ i ] ;
        }
    for( i = 0 ; i < m  ; i ++ )
        {
        cin >> q >> w ;
        for( ind1 = n - 1 ; ind1 >= 0 ; ind1 -- )
            {
            if( q == a[ ind1 ] ) break;
            }
        for( ind2 = n - 1 ; ind2 >= 0 ; ind2 -- )
            {
            if( w == a[ ind2 ] ) break;
            }
        v[ ind1 ][ ind2 ] = 1;
        v[ ind2 ][ ind1 ] = 1;
        }
    backtrack ( 0 ) ;
    printf( "%d\n" , bestsz );
    vector < string > str;
    str.clear();
    for ( i = 0 ;i < n; i ++ )
        {
        if ( best[ i ] == 1 ) str.push_back( a[ i ] );
        }
    sort ( str.begin( ),str.end( ) );
    n = str.size();
    for ( i = 0 ; i < n; i ++ )
        {
        cout << str[ i ] <<"\n";
        }
    return 0;
    }