#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

const int N = 5002;
int n, m, k;
int a[N], b[N], c[N];

vector<int> g[N];

struct Item {
    int a, b, c;
} it[N];

int limits[N];
LL dp[N][N];
vector<int> todo[N];
bool cmp(int x, int y) {
    return it[x].c > it[y].c;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &it[i].a, &it[i].b, &it[i].c);
    }
    limits[n] = it[n].a; 
    for (int i = n - 1; i >= 1; i --) {
        limits[i] = max(it[i].a, limits[i + 1] - it[i].b);
    }
    for (int i = 1; i <= m; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++) {
        sort(g[i].begin(), g[i].end());
        if (g[i].size()) {
            todo[g[i].back()].push_back(i);
        } else {
            todo[i].push_back(i);
        }
    }
    for (int i = 0; i < N; i ++) for (int j = 0; j < N; j ++) {
        dp[i][j] = -1e12;
    }
    dp[0][0] = 0;
    int now = k; LL ans = -1;
    for (int i = 0; i <= n; i ++) {
        sort(todo[i+1].begin(), todo[i+1].end(), cmp);
        for (int j = 0; j <= i; j ++) {
            // printf("dp[%d][%d] = %lld, now = %d, j = %d, limits[i+1]=%d\n", i, j, dp[i][j], now, j, limits[i+1]);
            if (now - j < limits[i + 1]) continue;
            if (i == n) ans = max(ans, dp[i][j]);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            LL sum = 0;
            for (int x = 0; x < todo[i+1].size(); x ++) {
                sum += it[ todo[i+1][x] ].c;
                dp[i+1][j+x+1] = max(dp[i+1][j+x+1], dp[i][j] + sum);
            }
        }
        now = now + it[i + 1].b;
    }
    cout << ans << endl;
}