#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

const int N = 1e5 + 10;

int n;
int l[N], r[N];
vector<int> g[N];

pair<ll, ll> solve(int v, int p) {
    // cerr << "v = " << v << " p = " << p << endl;
    ll ansL = 0, ansR = 0;
    for (auto i : g[v]) {
        if (i == p) continue;
        auto fans = solve(i, v);
        ansL += max(fans.first + abs(l[v] - l[i]), fans.second + abs(l[v] - r[i]));
        ansR += max(fans.first + abs(r[v] - l[i]), fans.second + abs(r[v] - r[i]));
    }
    // cerr << "v = " << v << " ansL = " << ansL << " ansR = " << ansR << endl;
    return {ansL, ansR};
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto fans = solve(0, -1);
    cout << max(fans.first, fans.second) << '\n';
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