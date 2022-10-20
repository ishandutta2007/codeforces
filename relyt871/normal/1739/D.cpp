#include <bits/stdc++.h>
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

int n, k, fa[MAXN], mxd[MAXN];

bool Check(int mid) {
    for (int i = 1; i <= n; ++i) {
        mxd[i] = 1;
    }
    int need = 0;
    for (int i = n; i > 1; --i) {
        if (mxd[i] == mid && fa[i] != 1) {
            ++need;
        } else {
            mxd[fa[i]] = max(mxd[fa[i]], mxd[i] + 1);
        }
    }
    return (need <= k);
}

void solve() {
    read(n); read(k);
    for (int i = 2; i <= n; ++i) {
        read(fa[i]);
    }
    int L = 1, R = n - 1, ans = n;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (Check(mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}