#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 200005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, h[MAXN], d[MAXN], dis[MAXN];
vector<int> tree[MAXN], vec[MAXN];
queue<int> q;

void BFS(int H, vector<int> &st) {
    for (int i = 1; i <= n; ++i) {
        dis[i] = 100000000;
    }
    for (auto u : st) {
        dis[u] = 0;
        q.push(u);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : tree[u]) {
            if (h[v] < h[u]) continue;
            int cur = max(0, dis[u] + (h[u] == h[v]? 1 : -1));
            if (dis[v] > cur) {
                dis[v] = cur;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!dis[i]) {
            d[i] = min(d[i], H);
        }
    }
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        int t; read(t);
        if (t) q.push(i);
        h[i] = (t? 0 : -1);
    }
    for(int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : tree[u]) {
            if (h[v] == -1) {
                h[v] = h[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = h[i];
        for (auto j : tree[i]) {
            if (h[i] == h[j]) {
                vec[h[i]].push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (vec[i].size()) {
            BFS(i, vec[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ",  h[i] * 2 - d[i]);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}