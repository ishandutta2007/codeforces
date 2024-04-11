#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PLL = pair<LL, LL>;
using PII = pair<int, int>;

using VI = vector<int>;
using VPII = vector<PII>;
using VPLL = vector<PLL>;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())

#define lbt(x) ((x) & -(x))

#define ls(x) ((x) << 1)
#define rs(x) (ls(x) | 1)
#define mid ((l + r) >> 1)
#define lch ls(x), l, mid
#define rch rs(x), mid + 1, r

#define forLR(i, a, b) for (auto i = a; i <= b; ++i)
#define forLr(i, a, b) for (auto i = a; i < b; ++i)
#define forRL(i, a, b) for (auto i = a; i >= b; --i)
#define forRl(i, a, b) for (auto i = a; i > b; --i)

const int max_N = (int) 5e5 + 21;
const int max_S = (1 << 15);

int n, m, q, k, sumw, w[233], cnt[max_S], val[max_S];

LL ans[max_S][233];

char a[233];

int main() {
    scanf("%d%d%d", &n, &q, &m);
    forLr(i, 0, n) {
        scanf("%d", w + i);
        sumw += w[i];
    }
    int maxs = (1 << n);
    forLr(i, 0, n) val[1 << i] = w[i];
    for (int s = 1; s < maxs; ++s) {
        int x = lbt(s);
        if (x == s) continue;
        val[s] = val[s ^ x] + val[x];
    }
    forLr(i, 0, q) {
        scanf("%s", a);
        int s = 0;
        forLr(j, 0, n) if (a[j] == '1') s |= (1 << j);
        ++cnt[s];
    }
    for (int s = 0; s < maxs; ++s) {
        for (int ss = 0; ss < maxs; ++ss) {
            int x = sumw - val[s ^ ss];
            if (x <= 100) ans[s][x] += cnt[ss];
        }
        forLR(i, 1, 100) ans[s][i] += ans[s][i - 1];
    }
    while (m--) {
        scanf("%s%d", a, &k);
        int s = 0;
        forLr(j, 0, n) if (a[j] == '1') s |= (1 << j);
        printf("%lld\n", ans[s][k]);
    }
    return 0;
}