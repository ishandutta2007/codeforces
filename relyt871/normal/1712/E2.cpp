#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 200000;
const int MAXN = 200005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

struct BIT {
    LL tr[MAXN];
    inline void add(int x, LL v) {
        for (; x <= N; x += (x & (-x))) {
            tr[x] += v;
        }
    }
    inline LL sum(int x) {
        LL ret = 0;
        for (; x; x -= (x & (-x))) {
            ret += tr[x];
        }
        return ret;
    }
} bit;

vector<int> d[MAXN];
vector< pair<int, int> > q[MAXN];

LL ans[MAXN];

void init() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            d[j].push_back(i);
        }
    }
}

void solve() {
    int T; read(T);
    for (int i = 1l, l, r; i <= T; ++i) {
        read(l); read(r);
        LL len = r - l + 1;
        if (len >= 3) {
            ans[i] = len * (len - 1) * (len - 2) / 6;
            q[r].push_back(make_pair(l, i));
        }
    }
    for (int i = 1; i <= N; ++i) {
        int sz = d[i].size();
        for (int j = 0; j < sz - 2; ++j) {
            bit.add(N - d[i][j] + 1, sz - 2 - j);
        }
        if (i % 6 == 0) {
            bit.add(N - i / 2 + 1, 1);
        }
        if (i % 15 == 0) {
            bit.add(N - i / 5 * 2 + 1, 1);
        }
        for (auto qr : q[i]) {
            ans[qr.second] -= bit.sum(N - qr.first + 1);
        }
    }
    for (int i = 1; i <= T; ++i) {
        printf("%lld\n", ans[i]);
    }
}

int main() {
    init();
    solve();
    return 0;
}