#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 4e5 + 5;

int m, n, siz[N], ss[N];
std::vector<int> ans, a[N], e[N], _e[N];

bool check(int u, int fa, int dep) {
    if (dep == m) {
        if (_e[u].size() != 2) { return false; }
    } else if (dep == 1) {
        if (_e[u].size() != 1) { return false; }
    } else {
        if (_e[u].size() != 3) { return false;}
    } bool flag = true;
    for (auto v : _e[u]) {
        if (v != fa) { flag &= check(v, u, dep - 1); }
    } return flag;
}

void solveLeaf() {
    if (a[2].size() > 2) { return; }
    int root = -1, mid = -1;
    for (auto u : a[2]) {
        bool flag = false;
        for (auto v : e[u]) {
            if (e[v].size() == 1) { flag = true; }
        }
        if (flag) {
            mid = u;
        } else {
            root = u;
        }
    }
    if (mid != -1 && root != -1) {
        _e[mid].push_back(n); _e[n].push_back(mid);
        if (check(root, 0, m)) { ans.push_back(mid); }
        _e[mid].pop_back(); _e[n].pop_back();
    }
}

void findCore(int u, int fa) {
    siz[u] = 1; ss[u] = 0;
    for (auto v : e[u]) {
        if (v != fa) {
            findCore(v, u); siz[u] += siz[v];
            ss[u] = std::max(ss[u], siz[v]);
        }
    }
}
void solveRoot() {
    findCore(1, 0);
    for (int i = 1; i < n; i++) {
        ss[i] = std::max(ss[i], siz[1] - siz[i]);
    } int min = *std::min_element(ss + 1, ss + n);
    std::vector<int> nod;
    for (int i = 1; i < n; i++) {
        if (ss[i] == min) { nod.push_back(i); }
    }
    if (nod.size() == 2 && check(nod[0], nod[1], m - 1) && check(nod[1], nod[0], m - 1)) {
        ans.push_back(nod[0]); ans.push_back(nod[1]);
    }
}

void dfs(int u, int fa) {
    siz[u] = 1;
    for (auto v : e[u]) {
        if (v != fa) { dfs(v, u); siz[u] += siz[v]; }
    }
}
void solveNormal() {
    if (a[2].size() != 1) { return; }
    if (a[4].size() != 1) { return; }
    int root = a[2].back(), u = a[4].back(); dfs(root, 0);
    std::vector<int> nod, nodd;
    for (auto v : e[u]) {
        if (siz[v] < siz[u]) {
            nod.push_back(v);
        }
    }
    int max = 0;
    for (auto v : nod) { max = std::max(max, siz[v]); }
    for (auto v : nod) {
        if (max != siz[v]) { nodd.push_back(v); }
    }
    if (nodd.size() != 2) { return; }
    for (int i = 0; i < _e[u].size(); ) {
        if (_e[u][i] == nodd[0] || _e[u][i] == nodd[1]) {
            _e[_e[u][i]].push_back(n); _e[n].push_back(_e[u][i]);
            for (int j = 0; j < _e[_e[u][i]].size(); j++) {
                if (_e[_e[u][i]][j] == u) {
                    _e[_e[u][i]].erase(_e[_e[u][i]].begin() + j); break;
                }
            }
            _e[u].erase(_e[u].begin() + i);
        } else { i++; }
    }
    _e[u].push_back(n); _e[n].push_back(u);
    if (check(root, 0, m)) { ans.push_back(u); }
}

int main() {
    m = read(); n = (1 << m) - 1;
    if (m == 2) {
        ans.push_back(1);
        ans.push_back(2);
    } else {
        for (int i = 2; i < n; i++) {
            int u = read(), v = read();
            e[u].push_back(v); e[v].push_back(u);
            _e[u].push_back(v); _e[v].push_back(u);
        }
        for (int i = 1; i < n; i++) {
            a[e[i].size()].push_back(i);
        }
        solveLeaf();
        solveRoot();
        solveNormal();
    } 
    std::sort(ans.begin(), ans.end());
    ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());
    printf("%d\n", ans.size());
    for (auto x : ans) { printf("%d ", x); }
    return 0;
}