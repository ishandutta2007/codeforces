#include <iostream>
#include <fstream>
#define MAXN 52
using namespace std;
int T, N, M;
char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool flag;
void reset_vis()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            vis[i][j] = false;
        }
    }
}
void reset_g()
{
    for(int i=0; i<MAXN; i++)
    {
        for(int j=0; j<MAXN; j++)
        {
            g[i][j] = 0;
        }
    }
}
void dfs(int x, int y)
{
    if(vis[x][y])
    {
        return;
    }
    if(x == 0 || y == 0 || x > N || y > M)
    {
        return;
    }
    if(g[x][y] == '#')
    {
        return;
    }
    if(g[x][y-1] == 'B' || g[x][y+1] == 'B' || g[x-1][y] == 'B' || g[x+1][y] == 'B')
    {
        return;
    }
    vis[x][y] = true;
    dfs(x, y+1); dfs(x, y-1); dfs(x-1, y); dfs(x+1, y);
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N>>M;
        flag = true;
        reset_g();
        reset_vis();
        for(int j=1; j<=N; j++)
        {
            for(int k=1; k<=M; k++)
            {
                cin>>g[j][k];
            }
        }
        dfs(N, M);
        for(int j=1; j<=N; j++)
        {
            for(int k=1; k<=M; k++)
            {
                if((!vis[j][k]) && g[j][k] == 'G')
                {
                    flag = false;
                }
            }
        }
        cout<<(flag ? "Yes" : "No")<<endl;
    }
}