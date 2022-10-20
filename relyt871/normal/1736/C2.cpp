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

int n, q, a[MAXN], rmn[MAXN], rmn2[MAXN];
LL s[MAXN], s2[MAXN];
vector<int> vec[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    int mn = n + 1, mn2 = n + 1;
    LL ans = 0;
    for (int i = n; i >= 1; --i) {
        for (auto x : vec[i]) {
            if (x < mn) {
                mn2 = mn;
                mn = x;
            } else if (x < mn2) {
                mn2 = x;
            }
        }
        rmn[i] = mn;
        rmn2[i] = mn2;
        ans += mn - i;
        if (i - a[i] > 0) {
            vec[i - a[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + rmn[i];
        s2[i] = s2[i - 1] + rmn2[i];
    }
    read(q);
    while (q--) {
        int p, x;
        read(p); read(x);
        LL cur = ans;
        if (x < a[p]) {
            int t = upper_bound(rmn + 1, rmn + n + 1, p) - rmn;
            if (t <= p - x) {
                cur -= (s[p - x] - s[t - 1]);
                cur += 1LL * p * (p - x - t + 1);
            }
        } else if (x > a[p]) {
            int l = lower_bound(rmn + 1, rmn + n + 1, p) - rmn;
            int r = upper_bound(rmn + 1, rmn + n + 1, p) - rmn - 1;
            l = max(l, p - x + 1);
            if (l <= r) {
                cur -= 1LL * p * (r - l + 1);
                cur += (s2[r] - s2[l - 1]);
            }
        }
        printf("%lld\n", cur);
    }
}

int main() {
    solve();
    return 0;
}