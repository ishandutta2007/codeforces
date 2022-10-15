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

const int maxN = 10005, maxC = 26;

int n, a, b, f[maxN];
std::string str;

struct SuffixAutomaton {
    int tot, lst, son[maxN][maxC], fail[maxN], len[maxN];

    SuffixAutomaton() { memset(son[0], -1, maxC << 2); tot = lst = 1; }
    void insert(int x) {
        int u = lst, v; len[lst = ++tot] = len[u] + 1;
        for (; !son[u][x]; u = fail[u]) { son[u][x] = lst; }
        if (u) {
            v = son[u][x];
            if (len[u] + 1 == len[v]) { fail[lst] = v; } else {
                len[++tot] = len[u] + 1; fail[tot] = fail[v];
                memcpy(son[tot], son[v], maxC << 2); fail[v] = fail[lst] = tot;
                for (; son[u][x] == v; u = fail[u]) { son[u][x] = tot; }
            }
        } else { fail[lst] = 1; }
    }
} sam;

int main() {
    std::cin >> n >> a >> b >> str;
    memset(f, 127, sizeof(f)); f[0] = a;
    for (int i = 0; i < n; i++) {
        sam.insert(str[i] - 'a'); f[i + 1] = std::min(f[i + 1], f[i] + a);
        for (int j = i + 1, u = 1; j < n; j++) {
            u = sam.son[u][str[j] - 'a'];
            if (!u) { break; } f[j] = std::min(f[j], f[i] + b);
        }
    }
    printf("%d\n", f[n - 1]);
    return 0;
} //