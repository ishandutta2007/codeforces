#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e5 + 5;

int n, all, tms, m[N], nxt[N];
long long sum, now[N];
std::vector<int> a[N];
std::vector<int> vis1[N];
std::vector<bool> vis2[N];
std::map<long long, std::pair<int, int>> map;
std::vector<std::pair<int, int>> o[N];
std::vector<std::pair<int, std::pair<int, int>>> f[N];
std::vector<std::pair<int, std::pair<int, int>>> ans, ttt;
bool fv[N];

void dfs2(int i, int j, int _i, int _j, int s, bool flag) {
    if (vis2[i][j]) {
        if (!flag && i == _i && j == _j) {
            if (!fv[s]) {
                fv[s] = true; nxt[s] = -1; f[s] = ttt;
            }
        }
        return;
    }
    vis2[i][j] = true;
    if (1 << i & s) {
        flag = true;
    } else {
        s |= 1 << i;
    }
    if (o[i][j].first != -1) {
        ttt.push_back({o[i][j].first, {i, a[o[i][j].first][o[i][j].second]}});
        dfs2(o[i][j].first, o[i][j].second, _i, _j, s, flag);
    }
}
void dfs1(int i, int j) {
    if (vis1[i][j]) {
        if (vis1[i][j] == tms) {
            ttt.clear();
            dfs2(i, j, i, j, 0, false);
        }    
        return;
    }
    vis1[i][j] = tms;
    if (o[i][j].first != -1) {
        dfs1(o[i][j].first, o[i][j].second);
    }
}

void solve(int s) {
    if (nxt[s] == -1) {
        for (auto tmp : f[s]) { ans.push_back(tmp); }
    } else {
        solve(nxt[s]); solve(s ^ nxt[s]);
    }
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        m[i] = read(); a[i].resize(m[i]); o[i].resize(m[i]); vis1[i].resize(m[i]); vis2[i].resize(m[i]);
        for (int j = 0; j < m[i]; j++) {
            a[i][j] = read(); sum += a[i][j]; now[i] += a[i][j];
            map[a[i][j]] = {i, j};
        }
    }
    if (sum % n != 0) { printf("No\n"); return 0; }
    sum /= n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++) {
            long long x = sum - (now[i] - a[i][j]);
            if (map.count(x)) {
                o[i][j] = map[x];
            } else {
                o[i][j] = {-1, -1};
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++) {
            if (vis1[i][j] == 0) {
                tms++; dfs1(i, j);
            }
        }
    }
    all = 1 << n;
    for (int s = 0; s < all; s++) {
        if (fv[s]) { continue; }
        for (int t = s; ; ) {
            t = s & (t - 1);
            if (t == 0) { break; }
            if (fv[t] && fv[s ^ t]) {
                fv[s] = true; nxt[s] = t;
            }
        }
    }
    if (!fv[all - 1]) {
        printf("No\n");
    } else {
        printf("Yes\n");
        solve(all - 1);
        std::sort(ans.begin(), ans.end());
        for (auto tmp : ans) {
            printf("%d %d\n", tmp.second.second, tmp.second.first + 1);
        }
    }
    return 0;
}