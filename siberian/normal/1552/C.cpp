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

int get(pair<int, int> a, int x) {
    return a.first <= x && a.second >= x;
}

bool checkCross(pair<int, int> a, pair<int, int> b) {
    if (a.first > a.second) swap(a.first, a.second);
    if (b.first > b.second) swap(b.first, b.second);
    return get(a, b.first) + get(a, b.second) == 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(k);
    vector<bool> used(2 * n + 1);
    for (int i = 0; i < k; ++i) {
        cin >> a[i].first >> a[i].second;
        used[a[i].first] = true;
        used[a[i].second] = true;
    }
    vector<int> coord;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!used[i]) {
            coord.push_back(i);
        }
    }
    for (int i = 0; i < n - k; ++i) {
        a.push_back({coord[i], coord[i + n - k]});
    }
    // for (auto i : a) {
    //     cerr << i.first << " " << i.second << endl;
    // }
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            if (checkCross(a[i], a[j])) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
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