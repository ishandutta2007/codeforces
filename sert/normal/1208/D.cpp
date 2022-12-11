#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 41;
// const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

struct ST {
    int sz;
    vector<pair<ll, int>> t;
    vector<ll> sub;

    ST(int sz) {
        this->sz = sz;
        t.resize(sz * 4);
        for (auto &x : t) x = make_pair(INF, -1);
        sub.resize(sz * 4);
        for (auto &x : sub) x = 0;
    }

    void push(int v) {
        ll x = sub[v];
        if (v * 2 + 1 < (int)t.size()) {
            t[v * 2 + 1].first -= x;
            sub[v * 2 + 1] += x;
        }
        if (v * 2 + 2 < (int)t.size()) {
            t[v * 2 + 2].first -= x;
            sub[v * 2 + 2] += x;
        }
        sub[v] = 0;
    }

    void build(const vector<ll> &a, int v = 0, int l = 0, int r = -1) {
        if (r == -1) r = sz;
        if (l + 1 == r) {
            t[v] = make_pair(a[l], -l);
            return;
        }
        int m = (l + r) / 2;
        build(a, v * 2 + 1, l, m);
        build(a, v * 2 + 2, m, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }

    void subt(int L, int R, int x, int v = 0, int l = 0, int r = -1) {
        if (r == -1) r = sz;
        if (L >= r || l >= R) return;
        if (L <= l && r <= R) {
            sub[v] += x;
            t[v].first -= x;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        subt(L, R, x, v * 2 + 1, l, m);
        subt(L, R, x, v * 2 + 2, m, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }

    void setval(int pos, int v = 0, int l = 0, int r = -1) {
        if (r == -1) r = sz;
        if (l + 1 == r) {
            t[v].first = INF;
            push(v);
            return;
        }
        push(v);
        int m = (l + r) / 2;
        if (pos < m) setval(pos, v * 2 + 1, l, m);
        else setval(pos, v * 2 + 2, m, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ST st(n);
    st.build(a);

    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
        auto mn = st.t[0];
        int ind = -mn.second;
        ans[ind] = i + 1;
        st.subt(ind + 1, n, i + 1);
        st.setval(ind);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tst = 1;
    //scanf("%d", &tst);
    // cin >> tst;
#ifdef MADE_BY_SERT
    D = true;  
    tst = 3;  
    while (tst--) {
        solve();
    }
#else
    while (tst--) solve();
#endif
}