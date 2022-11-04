#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define int ll

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e9;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

struct SparceTable {
    vector<vector<int>> table;
    vector<int> ln;

    SparceTable(const vector<int> &v) {
        table.pb(v);
        for (int iter = 0; (1 << (iter + 1)) <= len(v); ++iter) {
            table.emplace_back(len(v) - (1 << (iter + 1)) + 1);
            for (int i = 0; i < len(table.back()); ++i) {
                table.back()[i] = max(table[iter][i], table[iter][i + (1 << iter)]);
            }
        }

        ln.resize(len(v) + 1, -1);
        for (int i = 1; i < len(v) + 1; ++i) {
            ln[i] = ln[i >> 1] + 1;
        }
    }

    int query(int l, int r) {
        int L = ln[r - l];
        return max(table[L][l], table[L][r - (1 << L)]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int m;
    cin >> m;
    vector<pii> items(m);
    for (auto &[x, y] : items) {
        cin >> x >> y;
    }
    sort(all(items));
    vector<int> suff_max(m + 1, 0);
    for (int i = m - 1; i > -1; --i) {
        suff_max[i] = max(suff_max[i + 1], items[i].second);
    }
    SparceTable t(a);
    int cur = 0, cnt = 0;
    while (cur < n) {
        int l = 0, r = n - cur + 1;
        while (r - l > 1) {
            int c = (r + l) >> 1;
            int mx = t.query(cur, cur + c);
            int idx = lower_bound(all(items), mp(mx, 0ll)) - items.begin();
            if (suff_max[idx] >= c) {
                l = c;
            } else {
                r = c;
            }
        }
        if (l == 0) {
            cout << -1 << endl;
            return;
        }
        cur += l;
        ++cnt;
    }
    cout << cnt << endl;
}

void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}