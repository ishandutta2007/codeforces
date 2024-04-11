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

const int maxN = 1000005;

int n, m, p, cnt[2], nxt[maxN];
std::string s, t, ans;

void kmp() {
    for (int i = 2; i <= m; i++) {
        nxt[i] = nxt[i - 1];
        while (nxt[i] > 0 && t[nxt[i] + 1] != t[i]) { nxt[i] = nxt[nxt[i]]; }
        if (t[nxt[i] + 1] == t[i]) { nxt[i]++; }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> s >> t; n = (int) s.size(); m = (int) t.size();
    s = " " + s; t = " " + t; p = 1; kmp();
    for (int i = 1; i <= n; i++) { cnt[s[i] & 15]++; }
    while (true) {
        if (cnt[t[p] & 1]) {
            cnt[t[p] & 1]--; ans += t[p]; p++;
            if (p > m) { p = nxt[m] + 1; }
        } else { break; }
    }
    for (; cnt[0]; cnt[0]--) { ans += "0"; }
    for (; cnt[1]; cnt[1]--) { ans += "1"; }
    std::cout << ans;
    return 0;
} //