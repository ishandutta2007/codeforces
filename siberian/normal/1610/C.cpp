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

const int N = 2e5 + 10;

int n;
int a[N], b[N];

bool check(int x) {
    int now = 0;
    for (int i = 0; i < n && now < x; ++i) {
        if (a[i] + b[i] + 1 < x) continue;
        if (b[i] < now) continue;
        if (now + 1 + a[i] < x) continue;
        ++now;
    }
    return now == x;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    int L = 0, R = n + 1;
    while (L < R - 1) {
        int M = (L + R) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M;
        }
    }
    cout << L << '\n';
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