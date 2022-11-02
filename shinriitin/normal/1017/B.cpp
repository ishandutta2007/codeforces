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

int n, cnt0, cnt1, _cnt0, _cnt1;

char a[max_N], b[max_N];

LL ans;

int main() {
    scanf("%d%s%s", &n, a, b);
    forLr(i, 0, n) {
        cnt0 += a[i] == '0';
        cnt1 += a[i] == '1';
    }
    forLr(i, 0, n) {
        if (a[i] == '1' && b[i] == '0') {
            ans += cnt0;
            ++_cnt1;
        }
        if (a[i] == '0' && b[i] == '0') {
            ans += cnt1;
            ++_cnt0;
        }
    }
    ans -= 1ll * _cnt0 * _cnt1;
    printf("%lld\n", ans);
    return 0;
}