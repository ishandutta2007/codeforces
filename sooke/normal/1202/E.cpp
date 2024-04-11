#include <bits/stdc++.h>

const int N = 1e6 + 5, C = 26;

int n, m, q;
long long ans;

std::string s, t;

struct SuffixAutomaton {
    int tot, lst, son[N][C], fail[N], len[N], buc[N], ord[N], f[N], pos[N];

    SuffixAutomaton() { memset(son[0], -1, C << 2); tot = lst = 1; }
    void insert(int x) {
        int u = lst, v; len[lst = ++tot] = len[u] + 1;
        pos[len[lst]] = lst;
        for (; !son[u][x]; u = fail[u]) { son[u][x] = lst; }
        if (u) {
            v = son[u][x];
            if (len[u] + 1 == len[v]) { fail[lst] = v; } else {
                len[++tot] = len[u] + 1; fail[tot] = fail[v];
                memcpy(son[tot], son[v], C << 2); fail[v] = fail[lst] = tot;
                for (; son[u][x] == v; u = fail[u]) { son[u][x] = tot; }
            }
        } else { fail[lst] = 1; }
    }
    void radixSort() {
        for (int i = 1; i <= tot; i++) { buc[len[i]]++; }
        for (int i = 1; i <= len[lst]; i++) { buc[i] += buc[i - 1]; }
        for (int i = 1; i <= tot; i++) { ord[buc[len[i]]--] = i; }
    }
    void modify() {
        int u = 1;
        for (int i = 0; i < m; i++) {
            if (son[u][t[i] - 'a'] == 0) { return; }
            u = son[u][t[i] - 'a'];
        }
        f[u]++;
    }
    void solve() {
        for (int i = 1; i <= tot; i++) { f[ord[i]] += f[fail[ord[i]]]; }
    }
} sam1, sam2;

int main() {
    std::cin >> s; n = s.size();
    for (int i = 0; i < n; i++) { sam1.insert(s[i] - 'a'); }
    std::reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) { sam2.insert(s[i] - 'a'); }
    sam1.radixSort(); sam2.radixSort();
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::cin >> t; m = t.size();
        sam1.modify();
        std::reverse(t.begin(), t.end());
        sam2.modify();
    }
    sam1.solve(); sam2.solve();
    for (int i = 1; i <= n; i++) { ans += 1ll * sam1.f[sam1.pos[i]] * sam2.f[sam2.pos[n - i]]; }
    std::cout << ans << std::endl;
    return 0;
}