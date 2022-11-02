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

int n;
vector<int> p;
vector<vector<int>> fans;
vector<bool> has;
vector<bool> used;

void isPerm(vector<int> a) {
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    assert(a.size() == n);
    for (auto i : a) {
        assert(i >= 0 && i < n);
    }
}

void dfs(int v) {
    // cerr << "v = " << v << endl;
    fans[fans.size() - 1].push_back(v);
    used[v] = true;
    if (used[p[v]]) return;
    dfs(p[v]);
}

vector<vector<int>> non_cycles;

void solve() {
    cin >> n;
    fans.clear();
    non_cycles.clear();
    p.resize(n);
    for(auto& i : p) {
        cin >> i;
        --i;
    }
    has.assign(n, false);
    for (int i = 0; i < n; ++i) {
        has[p[i]] = true;
    }
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!has[i]) {
            fans.push_back({});
            dfs(i);
            if (fans.back().size() == 1 || (p[fans.back().back()] != fans.back()[0])) {
                non_cycles.push_back(fans.back());
                fans.pop_back();
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            fans.push_back({});
            dfs(i);
        }
    }
    vector<int> ans(n, -1);
    for (auto i : fans) {
        for (auto j : i) {
            ans[j] = p[j];
        }
    }
    // cerr << "cycles: ok" << endl;
    if (!non_cycles.empty()) {
        assert((non_cycles.size() > 1 || non_cycles[0].size() > 1));
        int last = -1;
        for (auto i : non_cycles) {
            for (int j = 0; j < i.size(); ++j) {
                if (j == 0 && last != -1) {
                    ans[last] = i[j];
                }
                if (j + 1 == i.size()) {
                    last = i[j];
                } else {
                    ans[i[j]] = p[i[j]];
                }
            }
        }
        ans[last] = non_cycles[0][0];
    }
    // assert(isPerm(ans));
    int k = 0;
    for (int i = 0; i < n; ++i) {
        k += ans[i] == p[i];
    }
    cout << k << '\n';
    for (auto i : ans) {
        cout << i + 1 << " ";
    }
    cout << "\n";
    // cout.flush();
    isPerm(ans);
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