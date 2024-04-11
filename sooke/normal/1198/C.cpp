#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m;
bool used[N];
std::vector<int> ans;
std::vector<std::pair<int, int>> e[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        for (int i = 0; i < m; i++) {
            int u = read() - 1, v = read() - 1;
            e[u].push_back({v, i});
            e[v].push_back({u, i});
        }
        ans.clear();
        for (int i = 0; i < n * 3; i++) {
            used[i] = true;
            for (auto p : e[i]) {
                int u = p.first;
                if (used[i] && used[u]) {
                    used[i] = used[u] = false;
                    ans.push_back(p.second);
                    break;
                }
            }
        }
        int cnt = 0;
        if (ans.size() >= n) {
            printf("Matching\n");
            for (auto i : ans) {
                printf("%d ", i + 1); cnt++;
                if (cnt == n) { break; }
            }
        } else {
            printf("IndSet\n");
            for (int i = 0; i < n * 3; i++) {
                if (used[i]) {
                    printf("%d ", i + 1); cnt++;
                    if (cnt == n) { break; }
                }
            }
        }
        printf("\n");
        for (int i = 0; i < n * 3; i++) {
            used[i] = false; e[i].clear();
        }
    }
    return 0;
}