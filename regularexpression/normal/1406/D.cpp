#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 7, INF = 1e18 + 239;
int n;
int t[N];

void upd(int l, int x) {
    for (int i = l + 1; i < N; i += i & -i) t[i] += x;
}

void upd(int l, int r, int x) {
    upd(l, x);
    upd(r, -x);
}

int query(int r) {
    int res = 0;
    for (; r > 0; r -= r & -r) res += t[r];
    return res;
}

int get_a(int i) {
    return query(i + 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        upd(i, i + 1, a);
    }
    int sum = 0;
    for (int i = 0; i + 1 < n; ++i) sum += max(0LL, get_a(i + 1) - get_a(i));
    int q;
    cin >> q;
    ++q;
    for (int iq = 0; iq < q; ++iq) {
            if (iq != 0) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            if (l != 0) sum -= max(0LL, get_a(l) - get_a(l - 1));
            if (r != n) sum -= max(0LL, get_a(r) - get_a(r - 1));
            upd(l, r, x);
            if (l != 0) sum += max(0LL, get_a(l) - get_a(l - 1));
            if (r != n) sum += max(0LL, get_a(r) - get_a(r - 1));
        }
        int a0 = get_a(0);
        int d = a0 - sum;
        int B = d < 0 ? -((-d + 1) / 2) : (d + 1) / 2;
        int ans = INF;
        for (int b0 = B - 1; b0 <= B + 1; ++b0) ans = min(ans, max(b0 + sum, a0 - b0));
        cout << ans << '\n';
    }
    return 0;
}