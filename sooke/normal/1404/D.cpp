#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, m, col[N];
std::vector<int> bln[N];
std::vector<std::pair<int, int>> e[N];

void dfs(int u, int fa, int c) {
    if (col[u] != 0) { return; }
    col[u] = c;
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (w == fa) { continue; }
        dfs(v, w, -c);
    }
}

int main() {
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << "First" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << i + 1 << " ";
        }
        for (int i = 0; i < n; i++) {
            std::cout << i + 1 << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Second" << std::endl;
        for (int i = 0; i < n + n; i++) {
            int x;
            std::cin >> x;
            x--;
            bln[x].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            e[i].push_back({n + i, m});
            e[n + i].push_back({i, m});
            m++;
            e[bln[i][0]].push_back({bln[i][1], m});
            e[bln[i][1]].push_back({bln[i][0], m});
            m++;
        }
        for (int u = 0; u < n + n; u++) {
            if (col[u] != 0) { continue; }
            dfs(u, -1, 1);
        }
        long long sum = 0;
        for (int u = 0; u < n + n; u++) {
            if (col[u] == 1) { sum += u + 1; }
        }
        if (sum % (n + n) == 0) {
            for (int u = 0; u < n + n; u++) {
                if (col[u] == 1) {
                    std::cout << u + 1 << " ";
                }
            }
            std::cout << std::endl;
        } else {
            for (int u = 0; u < n + n; u++) {
                if (col[u] == -1) {
                    std::cout << u + 1 << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}