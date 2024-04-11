#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

const int N = 2005, C = 26;

char s[N], t[N];
int n, m, w[N], pos[N], f[N][N];

struct AcAutomaton {
    int tot, fail[N], son[N][C];

    AcAutomaton() { memset(son[0], -1, C << 2); tot = 1; }
    inline int insert(char str[]) {
        int u = 1;
        for (int i = 0, x; str[i]; i++) {
            x = str[i] - 'a';
            if (son[u][x]) { u = son[u][x]; } else { son[u][x] = ++tot; u = tot; }
        }
        return u;
    }
    void build() {
        std::queue<int> que;
        for (int i = 0; i < C; i++) { if (son[1][i]) { que.push(son[1][i]); fail[son[1][i]] = 1; } }
        for (int u, v; !que.empty(); que.pop()) {
            u = que.front(); w[u] += w[fail[u]];
            for (int i = 0; i < C; i++) {
                if (son[u][i]) {
                    que.push(son[u][i]); v = fail[u];
                    for (; !son[v][i]; v = fail[v]);
                    fail[son[u][i]] = v ? son[v][i] : 1;
                } else { son[u][i] = son[fail[u]][i]; }
            }
        }
    }
} aam;

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    for (int i = 1; i <= 2; i++) {
        scanf("%s", t); pos[i] = aam.insert(t);
        w[pos[i]] = i == 1 ? 1 : -1;
    }
    aam.build();
    memset(f, 128, sizeof(f)); f[0][1] = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1, k; j <= aam.tot; j++) {
            if (f[i - 1][j] >= -1e8) {
                f[i - 1][j] += w[j];
                if (i <= n) {
                    if (s[i] == '*') {
                        for (int x = 0; x < C; x++) {
                            k = aam.son[j][x]; k = k ? k : 1;
                            f[i][k] = std::max(f[i][k], f[i - 1][j]);
                        }
                    } else {
                        k = aam.son[j][s[i] - 'a']; k = k ? k : 1;
                        f[i][k] = std::max(f[i][k], f[i - 1][j]);
                    }
                }
            }
        }
    }
    printf("%d\n", *std::max_element(f[n] + 1, f[n] + aam.tot + 1));
    return 0;
}