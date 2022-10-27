#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF = 1e9 + 7;
const int MAXM = 20000 + 10;
const int MAXN = 100 + 10;
const int MAXK = 23;

int n, m, k, tot,used[MAXN][MAXN];
char mp[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct Node
{
    int x, y, cnt;
} node[MAXN*MAXN];
bool cmp(Node a, Node b)
{
    return a.cnt < b.cnt;
}
bool isOcean(int i, int j)
{
    if(i == 1 || i == n || j == 1 || j == m)
    {
        return 1;
    }
    return 0;
}
void dfs(int x, int y)
{
    if((used[x][y]==2) || (mp[x][y] == '*')) return;
    if(used[x][y] == 0)
    {
        node[++tot].x = x;
        node[tot].y = y;
        node[tot].cnt = 1;
    }
    used[x][y] = 2;
    for(int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(mp[cx][cy] == '.' && used[cx][cy] == 0)
        {
            node[tot].cnt++;
            if(isOcean(cx, cy))
            {
                node[tot].cnt = INF;
            }
            used[cx][cy] = 1;
            dfs(cx, cy);
        }
    }
}
void dfs_ex(int x, int y)
{
    if(used[x][y]) return;
    used[x][y] = 1;
    mp[x][y] = '*';
    for(int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(mp[cx][cy] == '.')
        {
            dfs_ex(cx, cy);
        }
    }
}
int main()
{
    int i, j;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    for(i = 2; i < n; i++)
    {
        for(j = 2; j < m; j++)
        {
            dfs(i, j);
        }
    }
    sort(node + 1, node + 1 + tot, cmp);
    memset(used, 0, sizeof(used));
    int res = 0;
    for(i = 1; i <= tot; i++)
    {
        if(node[i].cnt >= INF)
        {
            tot = i - 1;
            break;
        }
    }
    for(i = 1; i <= tot - k; i++)
    {
        res += node[i].cnt;
        dfs_ex(node[i].x, node[i].y);
    }
    cout << res << endl;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cout << mp[i][j];
        }
        cout << endl;
    }
}