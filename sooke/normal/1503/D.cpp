#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, ans, a[N], b[N], c[N], op[N], cnt[2];
bool used[N];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); b[i] = read();
        if (a[i] <= n && b[i] <= n) { printf("-1\n"); exit(0); }
        if (a[i] >  n && b[i] >  n) { printf("-1\n"); exit(0); }
        c[a[i]] = c[b[i]] = a[i] > b[i];
        op[a[i]] = b[i]; op[b[i]] = a[i];
    }
    for (int i = 1, j = n * 2; i <= j; ) {
        int l = i, r = n * 2 + 1;
        cnt[c[l] ^ 1] = 1; cnt[c[l]] = 0; used[l] = true;
        for (; i <= j; ) {
            for (; (used[i] || used[op[i]]) && i <= j; i++);
            for (; (used[j] || used[op[j]]) && i <= j; j--);
            if (i > j) { break; }
            int gg = -1;
            if (gg == -1 && i <= op[r]) { gg = 0; }
            if (gg == -1 && j >= op[l]) { gg = 1; }
            if (gg == 0) {
                if (op[i] > op[l]) { printf("-1\n"); exit(0); }
                l = i; cnt[c[i] ^ 1]++; used[i] = true;
            }
            if (gg == 1) {
                if (op[j] < op[r]) { printf("-1\n"); exit(0); }
                r = j; cnt[c[j]]++; used[j] = true;
            }
            if (gg == -1) { break; }
        }
        ans += std::min(cnt[0], cnt[1]);
    }
    printf("%d\n", ans);
    return 0;
}