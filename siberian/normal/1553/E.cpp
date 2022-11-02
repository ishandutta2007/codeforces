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

int calc(const vector<int>& p) {
    int ans = 0;
    vector<bool> used(p.size());
    for (int i = 0; i < p.size(); ++i) {
        if (used[i]) continue;
        if (p[i] == i) continue;
        int now = i;
        while (!used[now]) {
            ans++;
            used[now] = true;
            now = p[now];    
        }
        --ans;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(auto& i : p) {
        cin >> i;
        --i;
    }
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cnt[(i - p[i] + n) % n]++;
    }
    // cerr << "cnt = " << endl;
    // for (auto i : cnt) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
    set<int> ans;
    for (int k = 0; k < n; ++k) {
        if (n - cnt[k] <= 2 * m) {
            // cerr << "k = " << k << endl;
            vector<int> np(n);
            for (int i = 0; i < n; ++i) {
                np[(i - k + n) % n] = p[i];
            }
            // cerr << "np = " << endl;
            // for (auto i : np) {
            //     cerr << i << " ";
            // }
            // cerr << endl;
            if (calc(np) <= m) {
                ans.insert(k);
            }
        }
    }
    cout << ans.size();
    for (auto i : ans) {
        cout << ' ' << i;
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