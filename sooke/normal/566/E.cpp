#include <cctype>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
 
inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}
 
const int N = 1e3 + 5;
 
int n, m, deg[N];
bool flag, vis[N], used[N];
std::bitset<N> tmp, to, self, leaf, e[N], bit[N];
std::vector<std::pair<int, int>> ans;
 
int main() {
    n = read(); flag = true;
    for (int i = 0, j, k; i < n; i++) {
        k = read(); flag &= k == n;
        for (; k; k--) {
            j = read(); j--;
            bit[i].set(j);
        }
    }
    if (flag) {
        for (int i = 1; i < n; i++) { ans.push_back({0, i}); }
    } else {
        for (int u = 0; u < n; u++) { leaf[u] = true; }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                tmp = bit[i] & bit[j];
                if (tmp.count() == 2) {
                    int u, v;
                    for (u = 0; u < n; u++) {
                        if (tmp[u]) { break; }
                    }
                    for (v = n - 1; v > u; v--) {
                        if (tmp[v]) { break; }
                    }
                    used[u] = used[v] = true;
                    leaf[u] = leaf[v] = false;
                    if (!e[u][v]) {
                        ans.push_back({u, v});
                        deg[u]++; deg[v]++;
                    }
                    e[u].set(v); e[v].set(u);
                }
            }
        }
        if (ans.size() == 1) {
            int u = ans[0].first, v = ans[0].second;
            for (int i = 0; i < n; i++) {
                if (bit[i].count() != n) {
                    for (int j = 0; j < n; j++) {
                        if (j == u || j == v) { continue; }
                        if (bit[i][j]) {
                            ans.push_back({j, u});
                        } else {
                            ans.push_back({j, v});
                        }
                    }
                    break;
                }
            }
        } else {
            for (int _ = 0; _ < n; _++) {
                if (vis[_] || used[_]) { continue; }
                for (int u = 0; u < n; u++) { tmp.set(u); }
                for (int i = 0; i < n; i++) {
                    if (bit[i][_]) { tmp &= bit[i]; }
                }
                int i, v = -1;
                for (i = 0; i < n; i++) {
                    if (bit[i] == tmp) { break; }
                }
                self = bit[i] & leaf; to = bit[i] ^ self;
                for (int u = 0; u < n; u++) {
                    if (to[u]) {
                        to.flip(u);
                        if (to == e[u]) { v = u; }
                        to.flip(u);
                        if (v != -1) { break; }
                    }
                }
                for (int u = 0; u < n; u++) {
                    if (self[u]) {
                        vis[u] = true;
                        ans.push_back({u, v});
                    }
                }
            }
        }
    }
    for (auto i : ans) { printf("%d %d\n", i.first + 1, i.second + 1); }
    return 0;
}