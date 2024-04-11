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

int ans, ansi;

int calc(int x) {
    return (n + x - 1) / x + x;
}

void output(int l, int r) {
    r = n - r + 1, l = n - l + 1;
    forLR(i, r, l) printf("%d ", i);
}

void display(int x) {
    for (int i = 0; i < n; i += x) {
        output(i + 1, min(i + x, n));
    }
}

int main() {
    scanf("%d", &n);
    ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        int tmp = calc(i);
        if (ans > tmp) {
            ans = tmp;
            ansi = i;
        }
    }
    display(ansi);
    return 0;
}