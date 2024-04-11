#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1111;
const int inf = 100000000;

int f[N][N];
int act[N][N];
int n, m;
char map[N][N];
int ans = 0;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int ok(char a, char b) {
    if (a == 'D' && b == 'I' || 
        a == 'I' && b == 'M' || 
        a == 'M' && b == 'A' || 
        a == 'A' && b == 'D')
        return 1;
    return 0;
}

int dfs(int x, int y) {
        
    act[x][y] = 1;
    f[x][y] = (map[x][y] == 'A');
    
    for(int d = 0; d < 4; d++) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if (xx < 1 || xx > n || yy < 1 || yy > m)
            continue;
        if (!ok(map[x][y], map[xx][yy]))
            continue;
        
        if (act[xx][yy]) {
            f[x][y] = inf;
        } else if (f[xx][yy] == -1) {
            f[x][y] = max(f[x][y], dfs(xx, yy) + (map[x][y] == 'A'));
        } else {
            f[x][y] = max(f[x][y], f[xx][yy] + (map[x][y] == 'A'));
        }
    }   
    
    act[x][y] = 0;
    
    return f[x][y];
}

int main() {
    
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);
    }   
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            f[i][j] = -1;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if (map[i][j] == 'D' && f[i][j] == -1) {
                ans = max(ans, dfs(i, j));  
            }
            /*
    for(int i = 1; i <= n; i++, printf("\n"))
        for(int j = 1; j <= m; j++)
            printf("%d ", f[i][j]);
    */  
    if (ans <= 0) {
        printf("Poor Dima!\n");
    } else if (ans >= inf) {
        printf("Poor Inna!\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;   
}