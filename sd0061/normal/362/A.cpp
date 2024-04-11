#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define N 100005

int n;
char s[10][10];
int f[10][10];
int g[10][10];
void dfs(int x , int y , int e)
{
    if (x > n || x <= 0 || y > n || y <= 0) return;
    if (f[x][y]) return;
    f[x][y] = e;
    dfs(x - 2 , y - 2 , 3 - e);
    dfs(x - 2 , y + 2 , 3 - e);
    dfs(x + 2 , y - 2 , 3 - e);
    dfs(x + 2 , y + 2 , 3 - e);
}
void dfs2(int x , int y , int e)
{
    if (x > n || x <= 0 || y > n || y <= 0) return;
    if (g[x][y]) return;
    g[x][y] = e;
    dfs2(x - 2 , y - 2 , 3 - e);
    dfs2(x - 2 , y + 2 , 3 - e);
    dfs2(x + 2 , y - 2 , 3 - e);
    dfs2(x + 2 , y + 2 , 3 - e);
}

void work()
{
    int i , j , x = 0 , y = 0 ;
    memset(f , 0 , sizeof(f));
    memset(g , 0 , sizeof(g));

    n = 8;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s", s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            if (s[i][j] == 'K')
            {
                if (!x)
                    x = 1 , dfs(i , j , 1);
                else
                    dfs2(i , j , 1);
            }
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            if (s[i][j] != '#' && f[i][j] && (f[i][j] == g[i][j]))
                y = 1;
    puts(y ? "YES" : "NO");
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d",&n,&T))
        work();
    return 0;
}