#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull  = unsigned long long;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
    if (y < x) {
        x = y;
    }
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) {
        x = y;
    }
}

const int N = 2e5 + 10;
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> st;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if (!a[i]) {
            continue;
        }
        if (st.empty()) {
            st.push_back(i);
        } else {
            int from = st.back();
            st.pop_back();
            int to = i;
            if (from + 1 == to) {
                if (a[from] - a[to] == 0) {
                    ans.push_back({from, to});
                } else if (a[from] + a[to] == 0) {
                    ans.push_back({from, from});
                    ans.push_back({to, to});
                } else {
                    throw;
                }
            } else {
                if (a[from] + a[to] == 0) {
                    ans.push_back({from, to - 1});
                    ans.push_back({to, to});
                } else if (a[from] - a[to] == 0) {
                    ans.push_back({from, to - 2});
                    ans.push_back({to - 1, to});
                } else {
                    throw;
                }
            }
        }
    }

    if (!st.empty()) {
        cout << "-1\n";
        return;
    }


    vector<pair<int, int>> add;
    if (ans.empty()) {
        add = {{0, n - 1}};
    } else {
        if (ans[0].first != 0) {
            add.push_back({0, ans[0].first - 1});
        }
        if (ans.back().second != n - 1) {
            add.push_back({ans.back().second + 1, n - 1});
        }
        for (int i = 0; i + 1 < (int)ans.size(); ++i) {
            if (ans[i + 1].first - ans[i].second != 1) {
                add.push_back({ans[i].second + 1, ans[i + 1].first - 1});
            }
        }
    }

    for (auto i : add) {
        ans.push_back(i);
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (auto [l, r] : ans) {
        cout << l + 1 << " " << r + 1 << '\n';
    }
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