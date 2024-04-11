#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e7 + 34;

int t[N];

void add(int v, int l, int r, int p) {
    if (l + 1 == r) {
        t[v] = 1;
        return;
    }
    int m = (l + r) / 2;
    if (p < m) add(v * 2 + 1, l, m, p);
    else add(v * 2 + 2, m, r, p);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int sum(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l + r) / 2;
    return sum(v * 2 + 1, l, m, L, R) + sum(v * 2 + 2, m, r, L, R);
}

int main() {
    init();

    int n, k, p, lst, d;
    cin >> n >> k;
    if (k * 2 > n) {
        k = n - k;
    }
    lst = 0;
    p = k;
    cout << 2;
    ll ans = 2;
    for (int i = 1; i < n; i++) {
        lst = p;
        p = (p + k) % n;

        if (p > lst) {
            d = 2 * sum(0, 0, n, lst + 1, p);
        } else {
            d = 1 + 2 * sum(0, 0, n, lst + 1, n) + 2 * sum(0, 0, n, 0, p);
        }
        ans += (p == 0 ? d : d + 1);
        cout << " " << ans;
        add(0, 0, n, lst);
    }

    return 0;
}