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

const int N = 1e3 + 10;
char nxt[N];

void doOp(string& a) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '1') {
            nxt[i] = '1';
            continue;
        }
        int cnt = 0;
        if (i > 0 && a[i - 1] == '1') ++cnt;
        if (i + 1 < a.size() && a[i + 1] == '1') ++cnt;
        // if (a[i] == '1') ok = true;
        if (cnt == 1) {
            nxt[i] = '1';
        } else {
            nxt[i] = '0';
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        a[i] = nxt[i];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    string a;
    cin >> a;
    chkmin(m, n);
    for (int i = 0; i < m; ++i) {
        doOp(a);
    }
    cout << a << '\n';
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