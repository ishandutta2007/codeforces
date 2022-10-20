#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pil pair<int, long long>
using namespace std;
typedef long long LL;
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

int n, m, k, a[MAXN], b[MAXN], ta, tb;
pil va[MAXN], vb[MAXN];

void solve() {
    ta = tb = 0;
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        int rem = a[i];
        while (rem % m == 0) {
            rem /= m;
        }
        if (i == 1 || rem != va[ta].first) {
            va[++ta] = make_pair(rem, a[i] / rem);
        } else {
            va[ta].second += a[i] / rem;
        }
    }
    read(k);
    for (int i = 1; i <= k; ++i) {
        read(b[i]);
        int rem = b[i];
        while (rem % m == 0) {
            rem /= m;
        }
        if (i == 1 || rem != vb[tb].first) {
            vb[++tb] = make_pair(rem, b[i] / rem);
        } else {
            vb[tb].second += b[i] / rem;
        }
    }
    if (ta != tb) {
        puts("No");
        return;
    }
    for (int i = 1; i <= ta; ++i) {
        if (va[i] != vb[i]) {
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}