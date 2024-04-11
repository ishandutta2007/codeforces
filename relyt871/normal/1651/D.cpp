#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 1000005;
const LL INF = 0x3f3f3f3f3f3f3f3f;

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

const int nx[4] = {1, 0, -1, 0};
const int ny[4] = {0, 1, 0, -1};

int n, m, dis[MAXN], from[MAXN];
pii p[MAXN];
vector<int> g[MAXN];
map<pii, int> ID;
queue<int> q;

inline int getID(pii pr) {
    if (ID.find(pr) == ID.end()) {
        p[++m] = pr;
        ID[pr] = m;
    }
    return ID[pr];
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(p[i].fi); read(p[i].se);
        ID[p[i]] = i;
    }
    m = n;
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k < 4; ++k) {
            int x = p[i].fi + nx[k], y = p[i].se + ny[k];
            int j = getID(MP(x, y));
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    mset(dis, -1);
    for (int i = n + 1; i <= m; ++i) {
        q.push(i);
        dis[i] = 0;
        from[i] = i;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                from[v] = from[u];
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int j = from[i];
        printf("%d %d\n", p[j].fi, p[j].se);
    }
}

int main() {
    solve();
    return 0;
}