#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 505;

int n , m;
int g[N][N] , c[N];
char str[N];

bool dfs(int x , int C)  {
    if (c[x] && c[x] != C) return 0;
    if (c[x]) return 1; c[x] = C;
    for (int y = 0 ; y < n ; ++ y)
        if (g[x][y]) {
            if (!dfs(y , 4 - C))
                return 0;
        }
    return 1;
}

int main() {
    scanf("%d%d" , &n , &m);
    memset(g , 1 , sizeof(g));
    for (int i = 0 ; i < n ; ++ i)
        g[i][i] = 0;
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        -- x, -- y;
        g[x][y] = g[y][x] = 0;
    }
    int x = -1;
    for (int i = 0 ; i < n ; ++ i) {
        bool flag = 0;
        for (int j = 0 ; j < n ; ++ j)
            if (g[i][j]) {
                flag = 1;
                break;
            }
        if (flag) {
            x = i;
            break;
        }
    }
    if (~x && !dfs(x , 1)) {
        puts("No");
        return 0;
    }
    for (int i = 0 ; i < n ; ++ i)
        if (!c[i]) {
            bool flag = 0;
            for (int j = 0 ; j < n ; ++ j)
                if (g[i][j]) {
                    flag = 1;
                    break;
                }
            if (!flag) 
                c[i] = 2;
        }    

    for (int i = 0 ; i < n ; ++ i) 
        for (int j = 0 ; j < i ; ++ j) {
            if ((!g[i][j]) ^ (abs(c[i] - c[j]) <= 1)) {
                puts("No");
                return 0;
            }
        }
    puts("Yes");
    for (int i = 0 ; i < n ; ++ i)
        printf("%c" , 'a' + c[i] - 1);
    puts("");
    return 0;
}