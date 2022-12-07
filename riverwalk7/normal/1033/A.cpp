#include <iostream>
#include <fstream>
using namespace std;
int ax, ay; int bx, by; int cx, cy;
int N;
bool grid[1010][1010];
bool vis[1010][1010];
bool good(int x, int y)
{
    int s = x-ax; int t = y-ay;
    if(s == 0 || t == 0)
    {
        return false;
    }
    if(s == t || s == -t)
    {
        return false;
    }
    return true;
}
void dfs(int x, int y)
{
    if(!grid[x][y]||vis[x][y])
    {
        return;
    }
    vis[x][y] = true;
    dfs(x, y+1);
    dfs(x, y-1);
    dfs(x-1, y-1);
    dfs(x-1, y);
    dfs(x-1, y+1);
    dfs(x+1, y-1);
    dfs(x+1, y);
    dfs(x+1, y+1);
}
int main()
{
    cin>>N;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(good(i, j))
            {
                grid[i][j] = true;
            }
        }
    }
    dfs(bx, by);
    if(vis[cx][cy])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}