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

const int maxN = 200005;

int n, m, tmp, t, cnt, hu[maxN], hv[maxN], belong[maxN];

struct Person { int id, p; } s[maxN];
bool cmp(Person a, Person b) { return a.p > b.p; }

void dfs(int cnt, int dep, int hep, int turn, int flag) {
    if (cnt > n * 2) { return; }
    if (turn == 1) {
        if (flag) {
            if (belong[hu[flag]] > 0) {
                std::cout << hu[flag] << std::endl; belong[hu[flag]] = -1;
                dfs(cnt + 1, dep, hep, 3 - turn, 0);
                return;
            }
            if (belong[hv[flag]] > 0) {
                std::cout << hv[flag] << std::endl; belong[hv[flag]] = -1;
                dfs(cnt + 1, dep, hep, 3 - turn, 0);
                return;
            }
        }
        for (; hep <= m; hep++) {
            if (belong[hu[hep]] > 0) {
                std::cout << hu[hep] << std::endl; belong[hu[hep]] = -1;
                dfs(cnt + 1, dep, hep + 1, 3 - turn, 0);
                return;
            }
        }
        for (; dep <= n * 2; dep++) {
            if (belong[s[dep].id] == 0) {
                std::cout << s[dep].id << std::endl; belong[s[dep].id] = -1;
                dfs(cnt + 1, dep + 1, hep, 3 - turn, 0);
                return;
            }
        }
    } else {
        std::cin >> tmp;
        if (belong[tmp] > 0 && belong[hu[belong[tmp]]] > 0 && belong[hv[belong[tmp]]] > 0) {
            int col = belong[tmp];
            belong[tmp] = -1;
            dfs(cnt + 1, dep, hep, 3 - turn, col);
            return;
        }
        belong[tmp] = -1;
        dfs(cnt + 1, dep, hep, 3 - turn, 0);
        return;
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n * 2; i++) { std::cin >> s[i].p; s[i].id = i; }
    for (int i = 1; i <= m; i++) {
        std::cin >> hu[i] >> hv[i];
        belong[hu[i]] = belong[hv[i]] = i;
        if (s[hu[i]].p < s[hv[i]].p) { std::swap(hu[i], hv[i]); }
    }
    std::cin >> t; std::sort(s + 1, s + n * 2 + 1, cmp); dfs(1, 1, 1, t, 0);
    return 0;
} //