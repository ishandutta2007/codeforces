#include <bits/stdc++.h>

using LL = long long;

const int max_N = (int) 1e5 + 21;

std::unordered_map<std::string, int> name;

std::unordered_map<LL, int> map, lbt;

int n, m, event[max_N], cnt;

char tmp[50];

LL bit[40];

inline int name_id(const std::string &s) {
    if (!name.count(s)) {
        name[s] = cnt++;
    }
    return name[s];
}

int solve(LL mask) {
    if (!mask) return 0;
    if (map.count(mask)) {
        return map[mask];
    }
    int u = lbt[mask & -mask];
    int ret = solve(mask ^ (1LL << u));
    ret = std::max(ret, 1 + solve(mask & ~bit[u]));
    return map[mask] = ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) lbt[1LL << i] = i;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", event + i);
        if (event[i] == 1) {
            event[i] = -1;
        } else {
            scanf("%s", tmp);
            event[i] = name_id(tmp);
        }
    }
    for (int i = 1, j; i <= n; i = j) {
        for (j = i + 1; j <= n && event[j] >= 0; ++j);
        LL mask = 0;
        for (int k = i + 1; k < j; ++k) {
            int u = event[k];
            mask |= (1LL << u);
        }
        for (int k = i + 1; k < j; ++k) {
            int u = event[k];
            bit[u] |= mask;
        }
    }
    printf("%d\n", solve((1LL << m) - 1));
}