#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;



struct keremida
    {
    int vertex;
    int dist;
    };

long long d[100007];
long long tsm=0;
int n;
vector < struct keremida > v[100007];


void input();
void solve();

void dfs ( int vertex );

int main()
    {
    input();
    solve();
    return 0;
    }



void input()
    {
    scanf( "%d" , &n);
    int i;
    int x,y,z;
    struct keremida p;

    for(i = 0 ; i < n-1 ; i++)
        {
        scanf("%d%d%d", &x , &y , &z);
        p.vertex = y;
        p.dist = z;
        v[x].push_back(p);
        p.vertex = x;
        v[y].push_back(p);
        tsm += z ;
        }

    }
void solve()
    {
    d[1]=1;
    dfs(1);

    int mx = 0;
    int i;
    for(i = 1; i <= n; i++)
        {
        d[i]--;
        if(d[i] > mx ) mx = d[i];
        }
    ///printf("%d %d\n",tsm , mx);
    printf("%I64d \n",(tsm-mx)*2+mx);
    }

void dfs ( int vertex )
    {
    int i;
    int sz = v[vertex].size();
    for ( i = 0 ; i < sz ; i ++)
        {
        if ( d[ v[ vertex ][ i ].vertex ] == 0 )
            {
            d[ v[ vertex ][ i ].vertex ]= d[ vertex ] + v[ vertex ][ i ].dist ;
            dfs( v[ vertex ][ i ].vertex );
            }
        }
    }