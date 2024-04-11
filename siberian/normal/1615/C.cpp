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

int solve(string a, string b) {
    int cnt = 0;
    int bal = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[i]) continue;
        if (a[i] == '0') {
            ++bal;
        } else {
            --bal;
        }
        ++cnt;
    }
    if (bal != 0) {
        return 1e9 + 228;
    } else {
        return cnt;
    }
}

string change(string a, int pos) {
    string ans;
    for (int i = 0; i < a.size(); ++i) {
        if (i == pos) {
            ans += '1';
        } else {
            ans += ((a[i] - '0') ^ 1) + '0'; 
        }
    }
    return ans;
}

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int ans = n + 1;

    chkmin(ans, solve(a, b));

    for (int i = 0; i < n; ++i) {
        if (a[i] == '1' && b[i] == '1') {
            chkmin(ans, solve(change(a, i), b) + 1);
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1' && b[i] == '0') {
            chkmin(ans, solve(change(a, i), b) + 1);
            break;
        }
    }

    if (ans == n + 1) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
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