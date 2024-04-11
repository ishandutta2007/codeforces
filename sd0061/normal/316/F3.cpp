#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1605;
int n , m , res[N] , sum;
int g[N][N];
int bel[N][N] , cnt;
int dx[] = {1 , 1 , 1 , 0 , 0 , -1 , -1 , -1};
int dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};

void dfs(int x , int y) {
    if (!g[x][y] || bel[x][y])
        return;
    bel[x][y] = cnt;
    for (int i = 0 ; i < 8 ; ++ i)
        dfs(x + dx[i] , y + dy[i]);
}
void DFS(int x , int y) {
    if (g[x][y] < 2 || g[x][y] > 3)
        return;
    g[x][y] = 8 , ++ sum;
    for (int i = 0 ; i < 8 ; ++ i)
        DFS(x + dx[i] , y + dy[i]);
}

void work () {
    scanf("%d%d",&n,&m);
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j)
            scanf("%d" , &g[i][j]);
    for (int i = 1 ; i <= n ; ++ i )
        for (int j = 1 ; j <= m ; ++ j)
            if (g[i][j] && !bel[i][j]) {
                ++ cnt;
                dfs(i , j);
            }
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            if (g[i][j] != 1) continue;
            for (int k = 0 ; k < 8 ; ++ k) {
                if (g[i + dx[k]][j + dy[k]] == 0) {
                    g[i][j] = 2;
                    break;
                }
            }
        }
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            if (g[i][j] != 1) continue;
            for (int k = 0 ; k < 8 ; ++ k) {
                if (g[i + dx[k]][j + dy[k]] == 0 || g[i + dx[k]][j + dy[k]] == 2) {
                    g[i][j] = 3;
                    break;
                }
            }
        }
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            if (g[i][j] == 1) continue;
            for (int k = 0 ; k < 8 ; ++ k) {
                if (g[i + dx[k]][j + dy[k]] == 1) {
                    g[i][j] = 4;
                    break;
                }
            }
        }
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            if (g[i][j] == 1 || g[i][j] == 4) continue;
            for (int k = 0 ; k < 8 ; ++ k) {
                if (g[i + dx[k]][j + dy[k]] == 1 ||
                    g[i + dx[k]][j + dy[k]] == 4 ) {
                    g[i][j] = 5;
                    break;
                }
            }
        }
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            if (g[i][j] == 1 || g[i][j] == 4 || g[i][j] == 5) continue;
            for (int k = 0 ; k < 8 ; ++ k) {
                if (g[i + dx[k]][j + dy[k]] == 1 ||
                    g[i + dx[k]][j + dy[k]] == 4 ||
                    g[i + dx[k]][j + dy[k]] == 5) {
                    g[i][j] = 6;
                    break;
                }
            }
        }
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            if (g[i][j] == 1 || g[i][j] == 4 || g[i][j] == 5 || g[i][j] == 6)
                continue;
            for (int k = 0 ; k < 8 ; ++ k) {
                if (g[i + dx[k]][j + dy[k]] == 1 ||
                    g[i + dx[k]][j + dy[k]] == 4 ||
                    g[i + dx[k]][j + dy[k]] == 5 ||
                    g[i + dx[k]][j + dy[k]] == 6) {
                    g[i][j] = 7;
                    break;
                }
            }
        }
    /*for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j)
            printf("%d" , g[i][j]);
        puts("");
        }*/
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            if (g[i][j] < 2 || g[i][j] > 3) continue;
            sum = 0;
            DFS(i , j);
            ++ res[bel[i][j]];            
        }
    sort(res + 1 , res + 1 + cnt);
    printf("%d\n" , cnt);
    for (int i = 1 ; i <= cnt ; ++ i)
        printf("%d%c" , res[i] , " \n"[i == cnt]);


}

int main() {
    //freopen("out" , "w" , stdout);
    work();
    return 0;
}