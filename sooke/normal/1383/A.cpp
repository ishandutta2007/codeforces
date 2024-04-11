#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, anc[N];
char s[N], t[N];

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

int solve() {
    for (int u = 0; u < 30; u++) {
        anc[u] = u;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] > t[i]) { return -1; }
        if (find(s[i] - 'a') != find(t[i] - 'a')) {
            anc[find(s[i] - 'a')] = find(t[i] - 'a');
        }
    }
    int ans = 0;
    for (int u = 0; u < 30; u++) {
        if (find(u) != u) { ans++; }
    }
    return ans;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        scanf("%s%s", s, t);
        printf("%d\n", solve());
    }
    return 0;
}