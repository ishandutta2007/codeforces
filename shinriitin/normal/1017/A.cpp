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

const int max_N = (int) 1e5 + 21;

int n, sum[max_N], Q[max_N];

int main() {
    scanf("%d", &n);
    for (int i = 1, a, b, c, d; i <= n; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        sum[i] = a + b + c + d;
        Q[i] = i;
    }
    std::sort(Q + 1, Q + 1 + n, [&](int x, int y) { return sum[x] != sum[y] ? sum[x] > sum[y] : x < y; });
    for (int i = 1; i <= n; ++i) if (Q[i] == 1) printf("%d\n", i);
    return 0;
}