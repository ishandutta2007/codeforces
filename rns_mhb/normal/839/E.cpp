#include <bits/stdc++.h>
using namespace std;

#define N 45

struct mx_clique{
    int n, cnct[N][N], ans, f[N];

    bool dfs(int *id, int sz, int cnt) {
        if (!sz) {
            if (ans < cnt) {
                ans = cnt; return 1;
            }
            return 0;
        }
        int stk[N];
        for (int i = 0; i < sz; i ++) {
            if (cnt + sz - i <= ans) return 0;
            if (cnt + f[id[i]] <= ans) return 0;
            int top = 0;
            for (int j = i + 1; j < sz; j ++) if (cnct[id[i]][id[j]]) stk[top++] = id[j];
            if (dfs(stk, top, cnt + 1)) return 1;
        }
        return 0;
    }

    int solve(int _n) {
        n = _n;
        ans = 0;
        int stk[N];
        for (int i = n - 1; i >= 0; i --) {
            int top = 0;
            for (int j = i + 1; j < n; j ++) if (cnct[i][j]) stk[top++] = j;
            dfs(stk, top, 1);
            f[i] = ans;
        }
        return ans;
    }
} A;

int n, k, m;
double ans;

int main() {
    
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++) {
        scanf("%d", &A.cnct[i][j]);
    }
    m = A.solve(n);
    printf("%.12lf\n", 0.5 * k * k * (m - 1) / m);
    return 0;
}