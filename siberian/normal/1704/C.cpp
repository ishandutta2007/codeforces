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

#define int ll

void solve() {
    int len, n;
    cin >> len >> n;
    vector<int> a(n);
    vin(a);
    sort(all(a));
    vector<int> segments;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] - a[i] - 1 > 0) {
            segments.push_back(a[i + 1] - a[i] - 1);
        }
    }
    if (len - a[n - 1] + a[0] - 1 > 0) {
        segments.push_back(len - a[n - 1] + a[0] - 1);
    }
    sort(all(segments));
    reverse(all(segments));
    // cerr << "segments = " << endl;
    // for (auto i : segments) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
    ll ans = 0;
    ll cur_ans = 0;

    multiset<int> values;

    int r = -1;
    while (r + 1 < (int)segments.size() && (values.empty() || *values.begin() + 2 * ((int)segments.size() - (r + 2)) > 0)) {
        ++r;
        values.insert(segments[r] - 2 * ((int)segments.size() - r - 1));
    }

    // cerr << "values = " << endl;
    // for (auto i : values) {
    //     cerr << i << " ";
    // }
    // cerr << endl;

    chkmax(ans, (int)values.size());

    for (int i = 0; i < (int)segments.size(); ++i) {
        if (r >= i) {
            values.erase(values.find(segments[i] - 2 * ((int)segments.size() - i - 1)));
        }

        while (!values.empty() && r >= i && *values.begin() + 2 * ((int)segments.size() - (r + 1)) - 4 * (i + 1) <= 0) {
            values.erase(values.find(segments[r] - 2 * ((int)segments.size() - r - 1)));
            --r;
        }
        // cerr << "i = " << i << " r = " << r << endl;
        cur_ans += (-2 * i) + (segments[i] - i) - i - 1;
        chkmax(ans, cur_ans + max(r - i, 0LL));
        // chkmax(ans, cur_ans);
    }

    cout << len - ans << '\n';
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