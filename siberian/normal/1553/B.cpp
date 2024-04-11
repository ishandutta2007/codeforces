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

bool check(int pos, int r, const string& s, const string& t) {
    if (r - pos + 1 > t.size()) return false;
    for (int i = 0; i <= r - pos; ++i) {
        if (s[pos + i] != t[i]) {
            return false;
        }
    }
    for (int i = r - pos + 1; i < t.size(); ++i) {
        int sPos = r - (i - (r - pos));
        if (sPos < 0) return false;
        if (s[sPos] != t[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    // int m = t.size();
    for (int pos = 0; pos < n; ++pos) {
        for (int r = pos; r < n; ++r) {
            if (check(pos, r, s, t)) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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