#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005, maxLog = 21;

int n, m, max, num, numA, numB, logN, a[maxN], b[maxN], sa[maxN], rnk[maxN], cnt[maxN], old[maxN], f[maxLog][maxN], g[maxN], height[maxN];
std::string str;

typedef long long lol;

struct SegmentTree {
    int cnt[maxN << 2]; lol sum[maxN << 2]; bool clr[maxN << 2];

    inline void pushUp(int u) { cnt[u] = cnt[u << 1] + cnt[u << 1 | 1]; sum[u] = sum[u << 1] + sum[u << 1 | 1]; }
    inline void pushClr(int u) { clr[u] = true; cnt[u] = sum[u] = 0; }
    inline void pushDown(int u) { if (clr[u]) { clr[u] = false; pushClr(u << 1); pushClr(u << 1 | 1); } }
    void modify(int u, int l, int r, int p, int x) {
        if (!p) { return; }
        if (l == r) { cnt[u] += x; sum[u] += 1ll * x * l; return; }
        int mid = l + r >> 1; pushDown(u);
        if (p <= mid) { modify(u << 1, l, mid, p, x); } else { modify(u << 1 | 1, mid + 1, r, p, x); }
        pushUp(u);
    }
    void query(int u, int l, int r, int pl, int pr, int &res) {
        if (pl > pr) { return; }
        if (l == pl && r == pr) { res += cnt[u]; pushClr(u); return; }
        int mid = l + r >> 1; pushDown(u);
        if (pr <= mid) { query(u << 1, l, mid, pl, pr, res); }
        else if (pl > mid) { query(u << 1 | 1, mid + 1, r, pl, pr, res); }
        else { query(u << 1, l, mid, pl, mid, res); query(u << 1 | 1, mid + 1, r, mid + 1, pr, res); }
        pushUp(u);
    }
} tr;

inline void radixSort() {
    for (int i = 1; i <= max; i++) { cnt[i] = 0; }
    for (int i = 1; i <= n; i++) { cnt[rnk[i]]++; }
    for (int i = 2; i <= max; i++) { cnt[i] += cnt[i - 1]; }
    for (int i = n; i; i--) { sa[cnt[rnk[old[i]]]--] = old[i]; }
}
void suffixSort() {
    for (int i = 1; i <= n; i++) { max = std::max(max, rnk[i] = str[i] - 'a' + 1); old[i] = i; }
    radixSort();
    for (int len = 1; true; len <<= 1) {
        for (int i = n - len + 1; i <= n; i++) { old[++num] = i; }
        for (int i = 1; i <= n; i++) { if (sa[i] > len) { old[++num] = sa[i] - len; } }
        radixSort(); memcpy(old, rnk, sizeof(rnk)); rnk[sa[1]] = max = 1;
        for (int i = 2; i <= n; i++) { rnk[sa[i]] = old[sa[i - 1]] == old[sa[i]] && old[sa[i - 1] + len] == old[sa[i] + len] ? max : ++max; }
        if (max >= n) { num = 0; break; } else { num = 0; }
    }
    for (int i = 1, j; i <= n; i++) {
        if (rnk[i] == 1) { height[1] = num = 0; continue; }
        j = sa[rnk[i] - 1]; num = num ? num - 1 : 0;
        while (i + num <= n && j + num <= n && str[i + num] == str[j + num]) { num++; }
        height[rnk[i]] = num;
    }
}

void buildST() {
    for (int i = 1; i <= logN; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) { f[i][j] = std::min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]); }
    }
}
inline int getLcp(int l, int r) {
    if (l > r) { std::swap(l, r); } else if (l == r) { return n + 1 - sa[l]; } else { l++; }
    // printf("< %d %d > %d %d %d %d\n", l, r, g[r - l + 1], height[l], f[0][l], f[0][r - (1 << g[r - l + 1]) + 1]);
    int logLen = g[r - l + 1]; return std::min(f[logLen][l], f[logLen][r - (1 << logLen) + 1]);
}

int main() {
    n = read(); m = read(); while (1 << logN + 1 <= n) { logN++; }
    std::cin >> str; str = " " + str; suffixSort();
    for (int i = 1; i <= n; i++) { f[0][i] = height[i]; g[i] = log(i) / log(2); } buildST();
    for (lol ans = 0; m; m--, ans = 0) {
        numA = read(); numB = read();
        for (int i = 1; i <= numA; i++) { a[i] = rnk[read()]; } std::sort(a + 1, a + numA + 1);
        for (int i = 1; i <= numB; i++) { b[i] = rnk[read()]; } std::sort(b + 1, b + numB + 1);
        for (int i = 1, j = 1; i <= numA; i++) {
            if (i == 1) { tr.pushClr(1); } else {
                int lcp = getLcp(a[i - 1], a[i]), tmp = 0;
                tr.query(1, 1, n, lcp + 1, n, tmp);
                if (lcp) { tr.modify(1, 1, n, lcp, tmp); } // printf("|= %d %d\n", lcp, tmp);
            }
            for (; j <= numB && b[j] <= a[i]; j++) { tr.modify(1, 1, n, getLcp(b[j], a[i]), 1); }
            ans += tr.sum[1];
        }
        for (int i = 1, j = 1; i <= numB; i++) {
            if (i == 1) { tr.pushClr(1); } else {
                int lcp = getLcp(b[i - 1], b[i]), tmp = 0;
                tr.query(1, 1, n, lcp + 1, n, tmp);
                if (lcp) { tr.modify(1, 1, n, lcp, tmp); } // printf("= %d %d\n", lcp, tmp);
            }
            for (; j <= numA && a[j] < b[i]; j++) { tr.modify(1, 1, n, getLcp(a[j], b[i]), 1); }
            for (; j <= numA && a[j] <= b[i]; j++) { tr.modify(1, 1, n, getLcp(a[j], b[i]), 1); ans -= getLcp(a[j], b[i]); }
            ans += tr.sum[1]; // printf("-- %d %d\n", i, tr.sum[1]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
} ///