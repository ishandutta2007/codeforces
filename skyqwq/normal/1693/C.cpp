// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, m, out[N], d[N];

vector<int> g[N];

bool vis[N];

priority_queue<PII, vector<PII>, greater<PII> > q;

void wk() {
    memset(d, 0x3f, sizeof d);
    d[n] = 0;
    q.push(mp(d[n], n));
    while (!q.empty()) {
        int u = q.top().se;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v: g[u]) {
            --out[v];
            int w = out[v] + d[u] + 1;
            if (w < d[v]) {
                d[v] = w;
                q.push(mp(d[v], v));
            }
        }
    }
}

int main() {
    read(n), read(m);
    for (int i = 1; i <= m; i++) {
        int u, v; read(u), read(v);
        out[u]++;
        g[v].pb(u);
    }
    wk();
    printf("%d\n", d[1]);
    return 0;
}