#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353;

inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 2e5 + 5, L = 20;

int n, m, dis[L][N];
std::vector<int> e[N], E[N];

struct Element {
    int x, d;
};

bool operator <(const Element &i, const Element &j) {
    return i.x == j.x ? i.d < j.d : i.x < j.x;
}
bool operator ==(const Element &i, const Element &j) {
    return i.x == j.x && i.d == j.d;
}

Element a[2][N], b[2][N];

void dijkstra1() {
    memset(dis, 60, sizeof(dis));
    dis[0][1] = 0;
    std::priority_queue<std::pair<int, std::pair<int, int>>> que;
    for (que.push({0, {0, 1}}); !que.empty(); ) {
        int d = -que.top().first;
        int i = que.top().second.first;
        int u = que.top().second.second;
        que.pop();
        if (d != dis[i][u]) { continue; }
        if (i % 2 == 0) {
            for (auto v : e[u]) {
                if (dis[i][v] > dis[i][u] + 1) {
                    dis[i][v] = dis[i][u] + 1;
                    que.push({-dis[i][v], {i, v}});
                }
            }
            if (i + 1 >= L) { continue; }
            if (dis[i + 1][u] > dis[i][u]) {
                dis[i + 1][u] = dis[i][u];
                que.push({-dis[i + 1][u], {i + 1, u}});
            }
        } else {
            for (auto v : E[u]) {
                if (dis[i][v] > dis[i][u] + 1) {
                    dis[i][v] = dis[i][u] + 1;
                    que.push({-dis[i][v], {i, v}});
                }
            }
            if (i + 1 >= L) { continue; }
            if (dis[i + 1][u] > dis[i][u]) {
                dis[i + 1][u] = dis[i][u];
                que.push({-dis[i + 1][u], {i + 1, u}});
            }
        }
    }
}

void dijkstra2() {
    for (int u = 1; u <= n; u++) {
        a[0][u] = (Element) {mod, mod};
        a[1][u] = (Element) {mod, mod};
    }
    a[0][1] = (Element) {0, 0};
    std::priority_queue<std::pair<Element, std::pair<int, int>>> que;
    for (que.push({a[0][1], {0, 1}}); !que.empty(); ) {
        Element s = que.top().first, t;
        s.x = -s.x; s.d = -s.d;
        int i = que.top().second.first;
        int u = que.top().second.second;
        que.pop();
        if (!(s == a[i][u])) { continue; }
        if (i == 0) {
            for (auto v : e[u]) {
                t = s; t.d++;
                if (t < a[i][v]) {
                    a[i][v] = t;
                    que.push({(Element) {-t.x, -t.d}, {i, v}});
                }
            }
            t = s; t.x++;
            if (t < a[i ^ 1][u]) {
                a[i ^ 1][u] = t;
                que.push({(Element) {-t.x, -t.d}, {i ^ 1, u}});
            }
        } else {
            for (auto v : E[u]) {
                t = s; t.d++;
                if (t < a[i][v]) {
                    a[i][v] = t;
                    que.push({(Element) {-t.x, -t.d}, {i, v}});
                }
            }
            t = s; t.x++;
            if (t < a[i ^ 1][u]) {
                a[i ^ 1][u] = t;
                que.push({(Element) {-t.x, -t.d}, {i ^ 1, u}});
            }
        }
    }
}

void judge1() {
    int ans = 1e9;
    for (int i = 0; i < L; i++) {
        ans = std::min(ans, sub(power(2, i), 1) + dis[i][n]);
    }
    if (ans < 1e9) {
        printf("%d\n", ans); exit(0);
    }
}

void judge2() {
    Element ans = (Element) {mod, mod};
    if (a[0][n] < ans) { ans = a[0][n]; }
    if (a[1][n] < ans) { ans = a[1][n]; }
    printf("%d\n", (ans.d + sub(power(2, ans.x), 1)) % mod);
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e[u].push_back(v); E[v].push_back(u);
    }
    dijkstra1();
    judge1();
    dijkstra2();
    judge2();
    return 0;
}