#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Fenwick{
    int n;
    vector<int> tree;
    Fenwick() = default;
    Fenwick(int _n) : n(_n), tree(n, 0) {}
    int get(int pos) {
        // return tree[pos];
        int ans = 0;
        for (; pos >= 0; pos = ((pos & (pos + 1)) - 1)) {
            ans += tree[pos];
        }
        return ans;
    }
    void add(int pos, int val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    void upd(int l, int r) {
        if (l > r) {
            upd(l, n - 1);
            upd(0, r);
        } else {
            // cerr << "l = " << l << " r = " << r << endl;
            // for (int i = l; i <= r; ++i) {
            //     tree[i]++;
            // }
            add(l, 1);
            add(r + 1, -1);
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> ans(n * m, 0);

    set<int> has;
    for (int i = 0; i < n * m; ++i) {
        if (s[i] == '1') {
            has.insert(i % m);
        }
        ans[i] += has.size();
    }

    Fenwick tree(m);
    for (int i = 0; i < n * m; ++i) {
        if (s[i] == '1') {
            int pos = i - 1;
            while (pos >= 0 && s[pos] != '1') --pos;
            // cerr << "i = " << i << " pos = " << pos << endl;
            if (pos == -1) {
                tree.upd(0, m - 1);
            } else {
                if (i - pos >= m) {
                    tree.upd(0, m - 1);
                } else {
                    tree.upd((m - (i - pos) + i) % m, (m - 1 + i) % m);
                }
            }
        }
        ans[i] += tree.get(i % m);
    }

    for (int i = 0; i < n * m; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}