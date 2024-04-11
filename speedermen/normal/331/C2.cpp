#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int BASE = 1000000;

char what[1 << 20];
pair <int, int> nxt[10][1 << 20];
pair <long long, int> to[10][10];

inline long long Calc(long long x) {
    long long suff = x / BASE, pref = x % BASE;
    long long ans = suff;
    while (suff > 0) {
        ans += nxt[what[suff]][pref].first;
        pref = nxt[what[suff]][pref].second;
        pref += BASE - max(what[suff], what[pref]);
        --suff;
    }
    return ans + nxt[0][pref].first;
}

inline long long Process(long long x) {
    long long suff = x / (1LL * BASE * BASE), psuff = x / BASE % BASE, pref = x % BASE;
    if (suff == 0) {
        return Calc(x);
    }
    long long ans = psuff + 1;
    while (psuff >= 0) {
        char r = what[psuff] < what[suff] ? what[suff] : what[psuff];
        ans += nxt[r][pref].first;
        pref = nxt[r][pref].second;
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
        what[i] = i % 10 > what[i / 10] ? i % 10 : what[i / 10];
        for (int d = 0; d < 10; ++d) {
            char r = what[i] < d ? d : what[i];
            if (i >= r) {
                nxt[d][i] = make_pair(nxt[d][i - r].first + 1, nxt[d][i - r].second);
            } else {
                nxt[d][i] = make_pair(0, i);
            }
        }
    }
    for (char d = 1; d < 10; ++d) {
        for (int l = 0; l < 10; ++l) {
            int suff = BASE - 1, pref = BASE - l;
            to[d][l].first = BASE;
            while (suff >= 0) {
                char r = (d < what[suff] ? what[suff] : d);
                to[d][l].first += nxt[r][pref].first;
                pref = nxt[r][pref].second;
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