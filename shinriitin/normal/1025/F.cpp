#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define SIZ(x) int((x).size())

using LL = long long;
using Poi = std::pair<LL, LL>;
const int max_N = 2000 + 21;

inline LL Cn2(LL n) { return n * (n - 1) / 2; }

int n;

Poi p[max_N];

LL ans, cnt[2];

std::vector<double> vec[2];

double angle(Poi u, Poi v) {
    return atan2(v.second - u.second, v.first - u.first);
}

const double pi = acos(-1.);

LL change(int d) { return Cn2(cnt[d ^ 1]++) * Cn2(--cnt[d]); }

int main() {
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
    }
    for (int i = 1; i <= n; ++i) {
        for (int d = 0; d < 2; ++d) vec[d].clear();
        cnt[0] = cnt[1] = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            double a = angle(p[i], p[j]);
            int d = (a > 0);
            ++cnt[d];
            vec[d].push_back(a);
        }
        for (int d = 0; d < 2; ++d) std::sort(ALL(vec[d]));
        int p = 0, q = 0;
        while (p < SIZ(vec[0]) || q < SIZ(vec[1])) {
            if (q == SIZ(vec[1]) ||
                (p < SIZ(vec[0]) && vec[0][p] + pi < vec[1][q])) {
                ans += change(0);
                ++p;
            } else {
                ans += change(1);
                ++q;
            }
        }
    }
    ans >>= 1;
    printf("%lld\n", ans);
    return 0;
}