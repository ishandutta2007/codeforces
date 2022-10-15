#include <cstdio>
#include <cstring>

const int N = 1e5 + 5, C = 26;

int n, ans[N];
char str[N];

struct PalindromeAutomaton {
    int tot, lst, f[N], len[N], cnt[N], fail[N], half[N], son[N][C];

    PalindromeAutomaton() {
        tot = 3; lst = 2; len[1] = -1; fail[2] = 1;
    }
    
    void insert(int i) {
        int u = lst, x = str[i] - 'a';
        for (; str[i] != str[i - 1 - len[u]]; u = fail[u]);
        if (son[u][x] == 0) {
            int v = son[u][x] = tot++, w;
            if (u == 1) {
                fail[v] = 2;
            } else {
                for (w = fail[u]; str[i] != str[i - 1 - len[w]]; w = fail[w]);
                fail[v] = son[w][x];
            } len[v] = len[u] + 2;
            if (len[v] <= 2) {
                half[v] = fail[v];
            } else {
                for (w = half[u]; str[i] != str[i - 1 - len[w]] || (len[w] + 2) * 2 > len[v]; w = fail[w]);
                half[v] = son[w][x];
            }
            if (len[v] / 2 == len[half[v]]) {
                f[v] = f[half[v]] + 1;
            } else {
                f[v] = 1;
            }
        } lst = son[u][x]; cnt[lst]++;
    }

    void count() {
        for (int u = tot - 1; u >= 3; u--) {
            int v = fail[u]; cnt[v] += cnt[u];
        }
    }

    void solve() {
        for (int u = 3; u < tot; u++) { ans[f[u]] += cnt[u]; }
        for (int i = n; i; i--) { ans[i - 1] += ans[i]; }
    }
} pam;

int main() {
    scanf("%s", str + 1); n = strlen(str + 1);
    for (int i = 1; i <= n; i++) { pam.insert(i); }
    pam.count(); pam.solve();
    for (int i = 1; i <= n; i++) { printf("%d ", ans[i]); }
    return 0;
}