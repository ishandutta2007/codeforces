#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, deg[N];
bool vis[N];
std::vector<int> e[N];

int main() {
    n = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    for (int i = 0; i < n / 2; i++) {
        int s = -1, t = -1;
        for (int u = 1; u <= n; u++) {
            if (deg[u] == 1 && !vis[u]) {
                s = u; break;
            }
        }
        vis[s] = true;
        for (int u = 1; u <= n; u++) {
            if (deg[u] == 1 && !vis[u]) {
                t = u; break;
            }
        }
        vis[t] = true;
        std::cout << "? " << s << " " << t << std::endl;
        int res = -1;
        std::cin >> res;
        if (s == res) { std::cout << "! " << s << std::endl; return 0; }
        if (t == res) { std::cout << "! " << t << std::endl; return 0; }
        for (auto v : e[s]) {
            deg[v]--;
        }
        for (auto v : e[t]) {
            deg[v]--;
        }
    }
    for (int u = 1; u <= n; u++) {
        if (!vis[u]) { std::cout << "! " << u << std::endl; break; }
    }
    return 0;
}