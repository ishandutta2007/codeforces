#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1.01e9 + 41;

struct ST {
    vector<int> t;
    int sz;
    explicit ST(int sz = 0) {
        this->sz = sz;
        t = vector<int>(sz * 4, INF);
    }

    void add(int p, int value, int v = 0, int l = 0, int r = -1) {
        if (r == -1) r = sz;
        if (l + 1 == r) { t[v] = value; return; }
        int m = (l + r) / 2;
        if (p < m) add(p, value, v * 2 + 1, l, m);
        else add(p, value, v * 2 + 2, m, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }

    int getMin(int L, int R, int v = 0, int l = 0, int r = -1) const {
        if (r == -1) r = sz;
        if (l >= R || L >= r) return INF;
        if (L <= l && r <= R) return t[v];
        int m = (l + r) / 2;
        return min(getMin(L, R, v * 2 + 1, l, m), getMin(L, R, v * 2 + 2, m, r));
    }
};

int go(const vector<int> &k, int l, int r) {
    vector<int> a(k.begin() + l, k.begin() + r + 1);
    int n = a.size();

    ST st(n);
    vector<int> ord(n, 0);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i1, int i2) {
        return i1 - a[i1] > i2 - a[i2] || (i1 - a[i1] == i2 - a[i2] && i1 < i2);
    });

    for (int i = 0; i < n; i++) {
        int v = ord[i];
        if (v == 0) {
            st.add(0, 0);
            continue;
        }

        int mn = st.getMin(0, v);
        if (mn == INF) continue;

        int curDp = mn + v - 1;
        if (v == n - 1) return curDp;
        st.add(v, curDp - v);
    }
    return INF;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = -INF + 10; a[n + 1] = INF - 10;

    vector<int> b(k + 2, 0);
    for (int i = 0; i < k; i++) cin >> b[i + 1];
    b.back() = n + 1;

    int ans = 0;
    for (int i = 1; i < (int)b.size(); i++) {
        int l = b[i - 1];
        int r = b[i];
        if (a[r] - a[l] < r - l) { cout << "-1\n"; return; }
        int cur = go(a, l, r);
        if (cur == INF) { cout << "-1\n"; return; }
        ans += cur;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 4;
#endif
    while (t--) solve();
}