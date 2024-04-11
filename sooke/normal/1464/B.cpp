#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, k01, k10;
long long f0[N], f1[N], pre0[N], pre1[N], suf0[N], suf1[N];
char s[N];

long long solve() {
    long long base = 0, c0 = 0, c1 = 0;
    for (int i = 1; i <= n; i++) {
        f0[i] += k10 * c1;
        f1[i] += k01 * c0;
        if (s[i] == '0') { base += k10 * c1; }
        if (s[i] == '1') { base += k01 * c0; }
        c0 += s[i] == '0';
        c1 += s[i] == '1';
    }
    c0 = c1 = 0;
    for (int i = n; i >= 1; i--) {
        f0[i] += k01 * c1;
        f1[i] += k10 * c0;
        c0 += s[i] == '0';
        c1 += s[i] == '1';
    }
    long long ans = 1e18;
    for (int i = 1; i <= n; i++) {
        if (s[i] != '?') { pre0[i] = pre0[i - 1]; pre1[i] = pre1[i - 1]; continue; }
        pre0[i] = pre0[i - 1] + f0[i];
        pre1[i] = pre1[i - 1] + f1[i];
    }
    for (int i = n; i >= 1; i--) {
        if (s[i] != '?') { suf0[i] = suf0[i + 1]; suf1[i] = suf1[i + 1]; continue; }
        suf0[i] = suf0[i + 1] + f0[i];
        suf1[i] = suf1[i + 1] + f1[i];
    }
    long long c = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '?') { c++; }
    }
    long long d = 0;
    for (int i = 1; i <= n + 1; i++) {
        ans = std::min(ans, pre0[i - 1] + suf1[i] + k01 * (c - d) * d);
        if (s[i] == '?') { d++; }
    }
    d = 0;
    for (int i = n; i >= 0; i--) {
        ans = std::min(ans, pre1[i] + suf0[i + 1] + k10 * (c - d) * d);
        if (s[i] == '?') { d++; }
    }
    return ans + base;
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    scanf("%d%d", &k01, &k10);
    printf("%lld\n", solve());
    return 0;
}