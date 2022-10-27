#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int vis[30][30], n, m;
char row[30], col[30];
void dfs(int x, int y)
{
    vis[x][y] = 1;
    if(row[x]=='>')
    {
        for(int i=y+1;i<=m;i++)
        {
            if(!vis[x][i])
            {
                dfs(x, i);
            }
        }
    }
    if(row[x]=='<')
    {
        for(int i=y-1;i>=1;i--)
        {
            if(!vis[x][i])
            {
                dfs(x, i);
            }
        }
    }

    if(col[y]=='v')
    {
        for(int i=x+1;i<=n;i++)
        {
            if(!vis[i][y])
            {
                dfs(i, y);
            }
        }
    }
    if(col[y]=='^')
    {
        for(int i=x-1;i>=1;i--)
        {
            if(!vis[i][y])
            {
                dfs(i, y);
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s %s", row+1, col+1);
    int ok = 1;
    for(int i_=1;i_<=n;i_++)
    {
        for(int j_=1;j_<=m;j_++)
        {
            memset(vis, 0, sizeof(vis));
            dfs(i_,j_);
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(!vis[i][j]) ok = 0;
                }
            }   
        }
    }
    puts(ok?"YES":"NO");
}