#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N], l[N], r[N], cnt[N], suf[N];
bool vis[N];

int solve() {
    int ans = n;
    for (int i = 0; i < n; i++) {
        l[i] = r[i] = -1; vis[i] = true; cnt[i] = suf[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x = a[i]; cnt[x]++; suf[x]++;
        if (l[x] == -1) { l[x] = i; } r[x] = i;
    } suf[n] = 0;
    for (int i = 0; i <= n; i++) { suf[i] = suf[i] > 0 ? 1 : 0; }
    for (int i = n; i > 0; i--) { suf[i - 1] += suf[i]; }
    for (int i = 0; i < n; i++) {
        if (vis[i] && cnt[i] != 0) {
            int j, now;
            for (j = i; j < n; j++) {
                if (cnt[j] == 0) { continue; }
                if (i == j) {
                    now = r[j];
                } else {
                    if (now > l[j] - 1) { break; }
                    now = r[j];
                }
                vis[j] = false;
            } ans = std::min(ans, suf[0] - (suf[i] - suf[j]));
        }
    } return ans;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) { a[i] = read(); a[i]--; }
        printf("%d\n", solve());
    }
    return 0;
}