#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

typedef long long lol;

const int maxN = 200005;

int n, tot, core, siz[maxN], son[maxN], f[maxN], cnt[1 << 21];
std::vector<int> vec[maxN], vcor[maxN];
std::string str;
bool vis[maxN];
lol ans[maxN];

void findCore(int u, int fa) {
    siz[u] = 1; son[u] = 0;
    for (int i = 0; i < (int) vec[u].size(); i++) {
        int v = vec[u][i];
        if (v != fa && !vis[v]) {
            findCore(v, u); siz[u] += siz[v];
            son[u] = std::max(son[u], siz[v]);
        }
    }
    son[u] = std::max(son[u], tot - siz[u]);
    if (son[core] > son[u]) { core = u; }
}


void dfs(int u, int fa) {
    cnt[f[u]]++; siz[u] = 1;
    for (int i = 0; i < (int) vec[u].size(); i++) {
        int v = vec[u][i];
        if (v != fa && !vis[v]) { dfs(v, u); siz[u] += siz[v]; }
    }
}
lol calc(int u, int fa, int x) {
    f[u] = f[fa] ^ (1 << str[u] - 'a');
    lol sum = cnt[f[u] ^ x];
    for (int i = 0; i <= 19; i++) { sum += cnt[f[u] ^ x ^ (1 << i)]; }
    for (int i = 0; i < (int) vec[u].size(); i++) {
        int v = vec[u][i];
        if (v != fa && !vis[v]) { sum += calc(v, u, x); }
    }
    ans[u] += sum; return sum;
}
void clear(int u, int fa) {
    cnt[f[u]]--;
    for (int i = 0; i < (int) vec[u].size(); i++) {
        int v = vec[u][i];
        if (v != fa && !vis[v]) { clear(v, u); }
    }
}

void solve(int u) {
    vis[u] = true; cnt[f[u] = 0]++;
    for (int i = 0; i < (int) vec[u].size(); i++) {
        int v = vec[u][i];
        if (!vis[v]) { ans[u] += calc(v, u, 1 << str[u] - 'a'); dfs(v, u); }
    }
    for (int i = 0; i < (int) vec[u].size(); i++) {
        int v = vec[u][i];
        if (!vis[v]) { clear(v, u); }
    }
    cnt[0]--;
    for (int i = (int) vec[u].size() - 1; ~i; i--) {
        int v = vec[u][i];
        if (!vis[v]) { calc(v, u, 1 << str[u] - 'a'); dfs(v, u); }
    }
    for (int i = (int) vec[u].size() - 1; ~i; i--) {
        int v = vec[u][i];
        if (!vis[v]) { clear(v, u); }
    }
    for (int i = 0; i < (int) vec[u].size(); i++) {
        int v = vec[u][i];
        if (!vis[v]) { core = 0; tot = siz[v]; findCore(v, u); vcor[u].push_back(core); }
    }
    for (int i = 0; i < (int) vcor[u].size(); i++) {
        int v = vcor[u][i];
        if (!vis[v]) { solve(v); }
    }
}

int main() {
    n = read(); son[0] = 1e9;
    for (int i = 2; i <= n; i++) {
        int u = read(), v = read();
        vec[u].push_back(v); vec[v].push_back(u);
    }
    std::cin >> str; str = " " + str;
    findCore(1, 0); solve(core);
    for (int i = 1; i <= n; i++) { printf("%I64d ", ans[i] + 1); }
    return 0;
} /// / / / / / / / / / / / fuck codeforces 