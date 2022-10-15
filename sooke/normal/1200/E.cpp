#include <bits/stdc++.h>

int n, m, min, q;
long long hs1, ht1, hs2, ht2, hs3, ht3, bs1, bs2, bs3, mod1, mod2, mod3, now1, now2, now3;

std::string s, t;

int solve() {
    int res = 0;
    hs1 = hs2 = hs3 = 0;
    ht1 = ht2 = ht3 = 0;
    now1 = now2 = now3 = 1;
    for (int i = 0; i < min; i++) {
        hs1 = (hs1 + now1 * s[n - 1 - i]) % mod1;
        hs2 = (hs2 + now2 * s[n - 1 - i]) % mod2;
        hs3 = (hs3 + now3 * s[n - 1 - i]) % mod3;
        ht1 = (ht1 * bs1 + t[i]) % mod1;
        ht2 = (ht2 * bs2 + t[i]) % mod2;
        ht3 = (ht3 * bs3 + t[i]) % mod3;
        now1 = now1 * bs1 % mod1;
        now2 = now2 * bs2 % mod2;
        now3 = now3 * bs3 % mod3;
        if (hs1 == ht1 && hs2 == ht2 && hs3 == ht3) {
            res = std::max(res, i + 1);
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> q;
    bs1 = 131;
    bs2 = 13131;
    bs3 = rand() % 32767;
    mod1 = 100000007;
    mod2 = 998244353;
    mod3 = (rand() % 32767) << 15 ^ rand();
    for (int qi = 0; qi < q; qi++) {
        std::cin >> t;
        if (qi == 0) {
            s = t;
        } else {
            n = s.size(); m = t.size(); min = std::min(n, m);
            int res = solve();
            for (int i = res; i < m; i++) { s += t[i]; }
        }
    }
    std::cout << s << std::endl;
    return 0;
}