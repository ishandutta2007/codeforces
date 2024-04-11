#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int BASE = 1000000, D = 10;

int what[BASE + 2];
pair <int, int> nxt[BASE + 2][D];
pair <long long, int> to[D][D];

inline long long Calc(long long x) {
    long long suff = x / BASE, pref = x % BASE;
    long long ans = suff;
    while (suff > 0) {
        ans += nxt[pref][what[suff]].first;
        pref = nxt[pref][what[suff]].second;
        pref += BASE - max(what[suff], what[pref]);
        --suff;
    }
    return ans + nxt[pref][0].first;
}

inline long long Process(long long x) {
    long long suff = x / (1LL * BASE * BASE), psuff = x / BASE % BASE, pref = x % BASE;
    if (suff == 0) {
        return Calc(x);
    }
    long long ans = 0;
    while (psuff >= 0) {
        int r = what[psuff] < what[suff] ? what[suff] : what[psuff];
        ans += nxt[pref][r].first + 1;
        pref = nxt[pref][r].second;
        pref += BASE - (r < what[pref] ? what[pref] : r);
        --psuff;
    }
    --suff;
    while (suff > 0) {
        ans += to[what[suff]][BASE - pref].first;
        pref = to[what[suff]][BASE - pref].second;
        --suff;
    }
    return ans + Calc(1LL * (BASE - 1) * BASE + pref);
}

int main() {
//    freopen("input.txt", "r", stdin);
    for (int i = 1; i <= BASE; ++i) {
        what[i] = i % D > what[i / D] ? i % D : what[i / D];
        for (int d = 0; d < D; ++d) {
            int r = what[i] < d ? d : what[i];
            if (i >= r) {
                nxt[i][d] = make_pair(nxt[i - r][d].first + 1, nxt[i - r][d].second);
            } else {
                nxt[i][d] = make_pair(0, i);
            }
        }
    }
    for (int d = 1; d < D; ++d) {
        for (int l = 0; l < D; ++l) {
            int suff = BASE - 1, pref = BASE - l;
            to[d][l].first = BASE;
            while (suff >= 0) {
                int r = (d < what[suff] ? what[suff] : d);
                to[d][l].first += nxt[pref][r].first;
                pref = nxt[pref][r].second;
                pref += BASE - (r < what[pref] ? what[pref] : r);
                --suff;
            }
            to[d][l].second = pref;
        }
    }
    long long n;
    cin >> n;
    cout << Process(n) << '\n';
    return 0;
}