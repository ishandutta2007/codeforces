#include <bits/stdc++.h>

// #define int long long
#define pb push_back
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

struct ST {
    vector<pair<int, int>> st;

    ST(int n) {
        st.resize(4 * n);
        build(0, 0, n);
    }

    void build(int i, int l, int r) {
        if (l + 1 == r) {
            st[i] = {0, l};
            return;
        }
        int m = (l + r) / 2;
        build(i * 2 + 1, l, m);
        build(i * 2 + 2, m, r);
        st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
    }

    void upd(int i, int l, int r, int pos, int qd) {
        if (l + 1 == r) {
            st[i].first = qd;
            return;
        }
        int m = (l + r) / 2;
        if (pos < m) {
            upd(i * 2 + 1, l, m, pos, qd);
        } else {
            upd(i * 2 + 2, m, r, pos, qd);
        }
        st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
    }

    pair<int, int> mx(int i, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) {
            return st[i];
        }
        int m = (l + r) / 2;
        if (qr <= m) {
            return mx(i * 2 + 1, l, m, ql, qr);
        }
        if (ql >= m) {
            return mx(i * 2 + 2, m, r, ql, qr);
        }
        return max(mx(i * 2 + 1, l, m, ql, m), mx(i * 2 + 2, m, r, m, qr));
    }
};

const int MAXN = 200500;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &el : a) {
        cin >> el;
    }
    vector<pair<int, int>> kek;
    for (int i = 0; i < n; i++) {
        if (i + 1 >= a[i]) {
            kek.emplace_back(i - a[i], a[i]);
        }
    }
    sort(all(kek));
    ST st(MAXN);
    for (auto el : kek) {
        int ok = el.second;
        pair<int, int> res = st.mx(0, 0, MAXN, 0, ok);
        st.upd(0, 0, MAXN, ok, res.first + 1);
    }
    cout << st.mx(0, 0, MAXN, 0, MAXN).first << '\n';
}