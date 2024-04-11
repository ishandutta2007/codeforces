#include <bits/stdc++.h>
using namespace std;
#define N 100010

int n, m, x, y, d[N], vis[N], res, g[5];
long long num, sum;

vector <int> V[N];
bool dfs(int r, int color) {
    if(vis[r] + color == 0) return false;
    if(vis[r] == color) return true;
    else {
        if(!vis[r]) {
            vis[r] = color;
            g[1 + color] ++;
            int col = (-1) * color;
            for(int i = 0; i < d[r]; i ++) if(!dfs(V[r][i], col)) return false;
            return true;
        }
        return true;
    }
}

int main() {
    //freopen("ksh.in", "r", stdin);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d", &x, &y);
        V[x].push_back(y);
        V[y].push_back(x);
        d[x] ++;
        d[y] ++;
    }
    sum = 0;
    num = 0;
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            memset(g, 0, sizeof g);
            if(!dfs(i, 1)) {
                res = 0;
                num = 1;
            }
            sum += 1LL * g[0] * (g[0] - 1) / 2 + 1LL * g[2] * (g[2] - 1) / 2;
        }
    }
    if(num) printf("%d %d", res, num);
    else {
        for(int i = 1; i <= n; i ++) {
            if(d[i] > 1) {
                res = 1;
                num = sum;
                break;
            }
        }
        if(res) printf("%d %I64d", res, num);
        else {
            for(int j = 1; j <= n; j ++) {
                if(d[j]) {
                    res = 2;
                    for(int l = 1; l <= n; l ++) {
                        if(d[l]) num += 1LL * (m - 1);
                        else num += 1LL * m;
                    }
                    break;
                }
            }
            if(res) printf("%d %I64d", res, num);
            else {
                num = 1LL * n * (n - 1) * (n - 2) / 6;
                res = 3;
                printf("%d %I64d", res, num);
            }
        }
    }
}