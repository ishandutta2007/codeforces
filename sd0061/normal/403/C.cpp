#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

#define N 2005
int n , m  , a[N][N];
bool f[N] , g[N];

void dfs1(int x) {
    f[x] = 1;
    for (int y = 0 ; y < n ; ++ y) {
        if (a[x][y] && !f[y]) {
            dfs1(y);
        }
    }
}
void dfs2(int x) {
    g[x] = 1;
    for (int y = 0 ; y < n ; ++ y) {
        if (a[y][x] && !g[y]) {
            dfs2(y);
        }
    }
}


void work()
{
    int i , j;
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < n ; ++ j)
            scanf("%d",&a[i][j]);
    dfs1(0) , dfs2(0);
    for (i = 0 ; i < n ; ++ i)
        if (!f[i] || !g[i])
            break;
    if (i < n)
        puts("NO");
    else
        puts("YES");
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    while (~scanf("%d" , &n))
        work();
    return 0;
}