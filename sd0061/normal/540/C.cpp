#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 505;
int n , m;
char g[N][N];
bool f[N][N];
int sx , sy , tx , ty;
void dfs(int x , int y) {
    if (x == tx && y == ty) {
        f[x][y] = 1;
        return;
    }
    if (g[x][y] != '.' && (x != sx || y != sy))
        return;
    if (f[x][y])
        return;
    //printf("%d %d\n" , x , y);
    f[x][y] = 1;
    dfs(x - 1 , y);
    dfs(x + 1 , y);
    dfs(x , y - 1);
    dfs(x , y + 1);    
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%s" , g[i] + 1);
    }
    scanf("%d%d" , &sx , &sy);
    scanf("%d%d" , &tx , &ty);
    dfs(sx , sy);
    if (!f[tx][ty]) {
        puts("NO");
        return 0;
    }
    int cnt = 0;
    cnt += (g[tx - 1][ty] == '.');
    cnt += (g[tx + 1][ty] == '.');
    cnt += (g[tx][ty - 1] == '.');
    cnt += (g[tx][ty + 1] == '.');
    if (abs(sx - tx) + abs(sy - ty) == 1)
        ++ cnt;
    if (g[tx][ty] == '.') {
        if (cnt >= 2)
            puts("YES");
        else
            puts("NO");
    } else {
        if (cnt >= 1)
            puts("YES");
        else
            puts("NO");    
    }
    return 0;
}