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

const int N = 51;
int n;
int a[N];
int x[N];

bool isSorted(int* a) {
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    } 
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (isSorted(a)) {
        cout << 0 << '\n';
    } else if (a[0] == n && a[n - 1] == 1) {
        cout << 3 << '\n';
    } else {
        for (int l = 0; l < n; ++l) {
            for (int r = l + 1; r < n; ++r) {
                if (l == 0 && r == n - 1) continue;
                for (int i = 0; i < n; ++i) {
                    x[i] = a[i];
                }
                sort(x + l, x + r + 1);
                if (isSorted(x)) {
                    cout << 1 << '\n';
                    return;
                }
            }
        }
        cout << 2 << '\n';
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