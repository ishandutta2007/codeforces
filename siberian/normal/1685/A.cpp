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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vin(a);
    sort(all(a));
    vector<int> b(n);
    int pos = 0;
    for (int i = 0; i < n; i += 2) {
        b[i] = a[pos++];
    }
    for (int i = 1; i < n; i += 2) {
        b[i] = a[pos++];
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int prev = b[(i - 1 + n) % n];
        int cur = b[i];
        int nxt = b[(i + 1) % n];
        if (prev < cur && nxt < cur) {
            continue;
        }
        if (prev > cur && nxt > cur) {
            continue;
        }
        ok = false;
    }
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << ' ';
            cout << b[i];
        }
        cout << '\n';
    } else {
        cout << "NO\n";
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