#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define int long long

const int maxN = 1000005;

int n, m, num, max, ans, logN, g[maxN], sa[maxN], rnk[maxN], old[maxN], cnt[maxN], height[maxN], f[23][maxN];
std::string t, str;

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
inline int lcp(int l, int r) {
    l = rnk[l]; r = rnk[r];
    if (l > r) { std::swap(l, r); } l++;
    int len = g[r - l + 1];
    return std::min(f[len][l], f[len][r - (1 << len) + 1]);
}

signed main() {
    std::cin >> t >> str;
    m = t.size(); t = " " + t;
    n = str.size(); str = " " + str; suffixSort();
    while (1 << logN + 1 <= n) { logN++; }
    for (int i = 1; i <= n; i++) { f[0][i] = height[i]; g[i] = log(i) / log(2.0); }
    buildST(); cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= m; i++) { cnt[t[i] & 15]++; }
    for (int len0 = 1, len1, lastLen = -1; len0 <= n; len0++) {
        len1 = n - len0 * cnt[0];
        if (len1 <= 0) { continue; }
        if (len1 % cnt[1] != 0) { continue; } len1 /= cnt[1];
        if (len1 == lastLen) { continue; } else { lastLen = len1; }
        bool flag = true; int last0 = 0, last1 = 0;
        for (int i = 1, l = 1, r = 0; i <= m; i++, l = r + 1) {
            if (t[i] & 15) {
                r += len1;
                if (!last1) { last1 = l; } else {
                    if (lcp(last1, l) < len1) { flag = false; break; }
                }
            } else {
                r += len0;
                if (!last0) { last0 = l; } else {
                    if (lcp(last0, l) < len0) { flag = false; break; }
                }
            }
        }
        if (len0 == len1 && last0 && last1 && lcp(last0, last1) >= len0) { flag = false; }
        ans += flag;
    }
    printf("%I64d\n", ans);
    return 0;
}