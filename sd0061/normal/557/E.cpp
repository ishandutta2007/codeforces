#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 5005;

int n , K;
char str[N];
bool f[N][N];
int u[N * N][2] , val[N * N] , cnt;

int dfs(int x) {
    if (!x) return 0;
    val[x] += dfs(u[x][0]);
    val[x] += dfs(u[x][1]);
    return val[x];
}

int work() {
    scanf("%s%d" , str + 1 , &K);
    n = strlen(str + 1);
    for (int k = 1 ; k <= n ; ++ k) {
        for (int i = 1 , j = k ; j <= n ; ++ i , ++ j) {
            if (str[i] == str[j]) {
                if (i + 2 > j - 2 || f[i + 2][j - 2])
                    f[i][j] = 1;
            }
        }
    }
    cnt = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        int x = 1;
        for (int j = i ; j <= n ; ++ j) {
            int c = str[j] - 'a';
            if (!u[x][c])
                u[x][c] = ++ cnt;
            x = u[x][c];
            val[x] += f[i][j];
        }
    }
    dfs(1);
    int x = 1;
    while (1) {
        if (K <= val[x] - val[u[x][0]] - val[u[x][1]])
            break;
        else {
            K -= val[x] - val[u[x][0]] - val[u[x][1]];
            if (val[u[x][0]] >= K) {
                putchar('a');
                x = u[x][0];
            } else {
                K -= val[u[x][0]];
                putchar('b');
                x = u[x][1];                
            }
        }
        
    }
}

int main() {
    work();
    return 0;
}