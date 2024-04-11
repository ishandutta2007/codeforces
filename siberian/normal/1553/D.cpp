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

string make(const string& s) {
    string ans = "";
    for (auto i : s) {
        if (i == '-') {
            if (!ans.empty()) ans.pop_back();
        } else {
            ans += i;
        }
    }
    return ans;
}

void solve() {
    string s, t;
    cin >> s >> t;

    int posT = (int)t.size() - 1;
    // int cntDel = 0;

    for (int i = (int)s.size() - 1; i >= 0; --i) {
        if (posT == -1 || s[i] != t[posT]) {
            s[i] = '-';
            --i;
        } else {
            --posT;
        }
    }

    if (make(s) == t) {
        cout << "YES\n";
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